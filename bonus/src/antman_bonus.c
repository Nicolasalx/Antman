/*
** EPITECH PROJECT, 2023
** print_wav_aiff_content
** File description:
** print_wav_aiff_content
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <zlib.h>
#include <stdio.h>

size_t ini_compression(const char *file_path, z_stream *stream)
{
    stream->zalloc = Z_NULL;
    stream->zfree = Z_NULL;
    stream->opaque = Z_NULL;
    if (deflateInit2(stream, Z_DEFAULT_COMPRESSION,
        Z_DEFLATED, 15 | 16, 8, Z_DEFAULT_STRATEGY) != Z_OK) {
        return 84;
    }

    struct stat file_stat;
    stat(file_path, &file_stat);
    size_t file_size = file_stat.st_size;

    return file_size;
}

void compress_file(z_stream *stream, size_t file_size, FILE *file)
{
    unsigned char *in = malloc(sizeof(unsigned char) * file_size);
    unsigned char *out = malloc(sizeof(unsigned char) * file_size);
    int flush;
    do {
        stream->avail_in = fread(in, 1, file_size, file);
        flush = feof(file) ? Z_FINISH : Z_NO_FLUSH;
        stream->next_in = in;
        do {
            stream->avail_out = file_size;
            stream->next_out = out;
            deflate(&stream, flush);
            fwrite(out, 1, file_size - stream->avail_out, stdout);
        } while (stream->avail_out == 0);
    } while (flush != Z_FINISH);
}

int compress_file_and_print(const char *file_path)
{
    FILE* file = fopen(file_path, "rb");
    if (file == 0) {
        write(2, "Invalid file\n", 13);
        return 84;
    }
    z_stream stream;
    size_t file_size = ini_compression(file_path, &stream);

    compress_file(&stream, file_size, file);

    deflateEnd(&stream);
    fclose(file);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 84;
    }

    if (compress_file_and_print(argv[1]) != 0) {
        return 84;
    }

    return 0;
}

/*
** EPITECH PROJECT, 2023
** giantman_audio
** File description:
** giantman_audio
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <zlib.h>
#include <stdio.h>

size_t ini_decompression(const char *file_path, z_stream *stream)
{
    stream->zalloc = Z_NULL;
    stream->zfree = Z_NULL;
    stream->opaque = Z_NULL;
    if (inflateInit2(&stream, 15 | 16) != Z_OK) {
        return 84;
    }

    struct stat file_stat;
    stat(file_path, &file_stat);
    size_t file_size = file_stat.st_size;

    return file_size;
}

void decompress_file(z_stream *stream, size_t file_size, FILE *file)
{
    unsigned char *in = malloc(sizeof(unsigned char) * file_size);
    unsigned char *out = malloc(sizeof(unsigned char) * file_size);
    int ret;
    do {
        stream->avail_in = fread(in, 1, file_size, file);
        if (stream->avail_in == 0)
            break;
        stream->next_in = in;
        do {
            stream->avail_out = file_size;
            stream->next_out = out;
            ret = inflate(&stream, Z_NO_FLUSH);
            fwrite(out, 1, file_size - stream->avail_out, stdout);
        } while (stream->avail_out == 0);
    } while (ret != Z_STREAM_END);
}

int decompress_file_and_print(const char *file_path)
{
    FILE* file = fopen(file_path, "rb");
    if (file == 0) {
        write(2, "Invalid file\n", 13);
        return 84;
    }

    z_stream stream;
    size_t file_size = ini_decompression(file_path, &stream);

    decompress_file(&stream, file_size, file);

    inflateEnd(&stream);
    fclose(file);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 84;
    }

    if (decompress_file_and_print(argv[1]) != 0) {
        return 84;
    }

    return 0;
}

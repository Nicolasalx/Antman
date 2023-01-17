# Antman
Description
The goal of this project is to compress data using lossless compression techniques. You will write two programs: '__antman__' and '__giantman__'. The '__antman__' binary will take a file as input and compress it, while the '__giantman__' binary will take a compressed file as input and translate it back to its original state.

## Compilation
The project can be compiled using the Makefile, with the following rules:

'__make__': compiles both the '__antman__' and '__giantman__' binaries
'__make re__': recompiles both binaries
'__make clean__': removes all object files
'__make fclean__': removes all object files and the binaries
The project should include all source files, except for binary, temp, and obj files. Any bonus files should be included in a directory named '__bonus__'.

## Usage
'__antman__' takes two parameters: the path to the file to be compressed and a number corresponding to the type of file it is. The program will then print the compressed version of the file on the standard output.

'__giantman__' takes two parameters: the path to the compressed file and the number corresponding to the type of file it originally was. The program will then print the readable file the compressed data was based on to the standard output.

## Error Handling
Error messages should be written to the error output and the program should exit with the error code 84 (or 0 if there is no error).

## Turn-in methods
You must have 2 folders at the root of your repository: a folder named '__antman__' with a binary named '__antman__' in it, and a folder named '__giantman__' with a binary named '__giantman__' in it. Each folder must contain a Makefile compiling the corresponding binary and a Makefile at the root must compile all binaries.

BOTH binaries must be functional for you to be graded on this project. We cannot evaluate one without the other.

## Authorized functions
The only system calls allowed are the following ones:

open
read
write
close
malloc
free
stat
## Lossless Compression
The type of compression used in this project is lossless compression. If the following command is executed:

```bash
./antman/antman file.txt 1 > compressed.data ;
./giantman/giantman compressed.data 1 > uncompressed.data
```
The “file.txt” and “uncompressed.data” files should be strictly identical.

This project will deal with 3 different types of input files:
1 corresponds to text files containing song lyrics. They are series of words, spaces, punctuation and newlines. Other characters can appear but are not common.
2 corresponds to HTML files. They can contain any character.
3 corresponds to P3 PPM images.

You only need to handle the compression and decompression of the file, not its validation.

## Authors
__Thibaud Cathala__

__Nicolas Alexandre__
## Acknowledgments
Epitech for providing the project guidelines

# Antman
## Description
The goal of this project is to compress data using lossless compression techniques. You will write two programs: '__antman__' and '__giantman__'. The '__antman__' binary will take a file as input and compress it, while the '__giantman__' binary will take a compressed file as input and translate it back to its original state.

##  Compilation
The project can be compiled using the Makefile, with the following rules:

'__make__': compiles both the '__antman__' and '__giantman__' binaries
'__make re__': recompiles both binaries
'__make clean__': removes all object files
'__make fclean__': removes all object files and the binaries
The project should include all source files, except for binary, temp, and obj files. Any bonus files should be included in a directory named '__bonus__'.

## Usage
'__antman__' takes two parameters: the path to the file to be compressed and a number corresponding to the type of file it is. The program will then print the compressed version of the file on the standard output.

'__giantman__' takes two parameters: the path to the compressed file and the number corresponding to the type of file it originally was. The program will then print the readable file the compressed data was based on to the standard output.

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

## Bonus
We have use the [huffman coding](https://fr.wikipedia.org/wiki/Codage_de_Huffman).
![image](https://user-images.githubusercontent.com/114945623/212955224-05d23c73-b9aa-49d8-9196-ee22b927ea71.png)
![image](https://user-images.githubusercontent.com/114945623/212956083-aae9babf-f86a-42ab-86a5-761cefc2421f.png)
![image](https://user-images.githubusercontent.com/114945623/212956215-ad82d89a-e6fb-45f6-ab4c-7df5c75e1fe7.png)
![image](https://user-images.githubusercontent.com/114945623/212956324-2e7ca275-ce93-428d-8d80-da2c4e3c8f70.png)

## Authors
__Thibaud Cathala__

__Nicolas Alexandre__
## Acknowledgments
Epitech for providing the project guidelines

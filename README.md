# Antman

Foobar is a Python library for dealing with word pluralization.

## Installation

Use the package manager [pip](https://pip.pypa.io/en/stable/) to install foobar.

```bash
pip install foobar
```

## Usage

```python
import foobar

# returns 'words'
foobar.pluralize('word')

# returns 'geese'
foobar.pluralize('goose')

# returns 'phenomenon'
foobar.singularize('phenomena')
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
----------------------------------------------------------------------------------------
# Antman
Description
The goal of this project is to compress data using lossless compression techniques. You will write two programs: __antman__ and giantman. The antman binary will take a file as input and compress it, while the giantman binary will take a compressed file as input and translate it back to its original state.

## Compilation
The project can be compiled using the Makefile, with the following rules:

make: compiles both the antman and giantman binaries
make re: recompiles both binaries
make clean: removes all object files
make fclean: removes all object files and the binaries
The project should include all source files, except for binary, temp, and obj files. Any bonus files should be included in a directory named bonus.

## Usage
antman takes two parameters: the path to the file to be compressed and a number corresponding to the type of file it is. The program will then print the compressed version of the file on the standard output.

giantman takes two parameters: the path to the compressed file and the number corresponding to the type of file it originally was. The program will then print the readable file the compressed data was based on to the standard output.

Error Handling
Error messages should be written to the error output and the program should exit with the error code 84 (or 0 if there is no error).

Turn-in methods
You must have 2 folders at the root of your repository: a folder named antman with a binary named antman in it, and a folder named giantman with a binary named giantman in it. Each folder must contain a Makefile compiling the corresponding binary and a Makefile at the root must compile all binaries.

BOTH binaries must be functional for you to be graded on this project. We cannot evaluate one without the other.

Authorized functions
The only system calls allowed are the following ones:

open
read
write
close
malloc
free
stat
Lossless Compression
The type of compression used in this project is lossless compression. If the following command is executed:

Copy code
./antman/antman file.txt 1 > compressed.data ; ./giantman/giantman compressed.data 1 > uncompressed.data
The “file.txt” and “uncompressed.data” files should be strictly identical.

This project will deal with 3 different types of input files:
1 corresponds to text files containing song lyrics. They are series of words, spaces, punctuation and newlines. Other characters can appear but are not common.
2 corresponds to HTML files. They can contain any character.
3 corresponds to P3 PPM images.

You only need to handle the compression and decompression of the file, not its validation.

Authors
Your name here
Acknowledgments
Epitech for providing the project guidelines

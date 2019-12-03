# Cryptography Hashing

## Description


## Installation
With the source files installed in the destination directory, run the following command to make both parts of the project:

`make all`

If you want to make a specific version of the project, run 1 of the following commands:

`make lzw`

`make lzwm`

In order to clean up the build files, run the following command:

`make clean`

## Capabilities And Usage

### Compression
`./lzwm c [filename]`
In order to compress a file, the 'c' flag must be used along with the name of the file (including extension) to compress. You can compress any file type with the command. Then, when the compression is done, it will be written out to [filename].lzw2

#### Decompression
`./lzwm e [filename]`
In order to decompress a file, the 'e' flag must be used along with the name of the file (including extension). The file that gets decompressed *must* be a .lzw file. When decompressed the content will be written out to [filename]2M

#### Example
Compress case1.txt:

`./lzw c case1.txt`
This produces the following files:

- case0.txt.lzw2
- log.txt
- log2.txt

Decompress case0.txt.lzw2

`./lzw e case1.txt.lzw`

This produces the following files:

- case0.txt.lzw22M
- log.txt (rewritten)
- log2.txt (rewritten)

Getting Help:
`./lzw h`

This produces the following output:
```
Help for lzwm command:

Usage: lzwm [option] [filename]
Available Options:
e or E: - expand a lzw file and print out the expanded message

c or C: - compress a file and export out to a file called [filename].lzw2

h or H: - print this help message

```
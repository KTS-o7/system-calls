# MV System Call Example

#### Explanation:

- **Rename System Call**: The `mv` command functionality is implemented using the `rename()` system call. This call renames or moves a file/directory from one location to another. It handles both renaming and moving the file to another directory.
- **Arguments**: The program takes two command-line arguments: the source file (the file to be moved) and the destination file (the new name or new path).
- **Error Handling**: The program checks if the `rename()` function fails and prints an appropriate error message.

---

## Overview

This folder contains a C program (`mv.c`) that implements the basic functionality of the Unix/Linux `mv` (move/rename) command using the `rename()` system call. The program moves or renames a file by changing its location or name.

## How It Works

1. The program takes two command-line arguments:

   - Source file path
   - Destination file path (the new name or the new location)

2. It calls the `rename()` system call, which either:

   - Renames the file if the destination is a new file name in the same directory.
   - Moves the file to a new directory if the destination is a path.

3. The program handles any errors that occur during this process, such as if the source file does not exist or the destination is invalid.

## Usage

To compile the program:

```bash
gcc mv.c -o mv
```

To run the program:

```bash
./mv source_file.txt destination_file.txt
```

Replace `source_file.txt` with the file you want to move/rename and `destination_file.txt` with the new file name or path.

## Error Handling

- If the source file does not exist or cannot be moved, the program prints an error message.
- If the destination is invalid (e.g., permission issues), an error message is printed.

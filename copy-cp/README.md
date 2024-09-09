# CP System Call Example

#### Explanation:

- **Open Files**: We use the `open()` system call to open the source file in read-only mode and the destination file in write-only mode, with create and truncate options.
- **Copy Loop**: The `read()` system call reads the contents of the source file into a buffer, and the `write()` system call writes it to the destination file.
- **Permissions**: The destination file is created with `0644` permissions, which gives the owner read and write permissions and the group and others read-only access.
- **Error Handling**: The program checks for any errors during file opening, reading, and writing, printing appropriate error messages.

---

## Overview

This folder contains a C program (`cp.c`) that implements a basic version of the Unix/Linux `cp` (copy) command using system calls. The program reads data from a source file and writes it to a destination file using `open()`, `read()`, and `write()` system calls.

## How It Works

1. The program takes two command-line arguments:

   - Source file path
   - Destination file path

2. It opens the source file in read-only mode using `open()` and creates (or truncates) the destination file in write-only mode with `0644` permissions.

3. It reads the source file in chunks of 1024 bytes using `read()` and writes the same data to the destination file using `write()`.

4. The process continues until the entire file is copied or an error occurs.

## Usage

To compile the program:

```bash
gcc cp.c -o cp
```

To run the program:

```bash
./cp source_file.txt destination_file.txt
```

Replace `source_file.txt` with the path of the file you want to copy, and `destination_file.txt` with the path where you want the copied file to be placed.

## Error Handling

- If the source file does not exist or cannot be opened, the program prints an error and exits.
- If the destination file cannot be created or written to, the program prints an error and exits.

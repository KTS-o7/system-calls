# CP System Call Example

#### Explanation:

- **Open Files**: We use the `ifstream` and `ofstream` classes to handle file operations in C++. The source file is opened in binary mode for reading, and the destination file is opened in binary mode for writing.
- **Copy Loop**: The `read()` method reads the contents of the source file into a buffer, and the `write()` method writes it to the destination file.
- **Permissions**: The destination file is created with default permissions set by the operating system.
- **Error Handling**: The program checks for any errors during file opening, reading, and writing, and prints appropriate error messages.

---

## Overview

This folder contains a C++ program (`cp.cpp`) that implements a basic version of the Unix/Linux `cp` (copy) command using file streams. The program reads data from a source file and writes it to a destination file using `ifstream` and `ofstream`.

## How It Works

1. The program takes two command-line arguments:

   - Source file path
   - Destination file path

2. It opens the source file in binary mode using `ifstream` and creates (or truncates) the destination file in binary mode using `ofstream`.

3. It reads the source file in chunks of 1024 bytes into a buffer and writes the same data to the destination file.

4. The process continues until the entire file is copied or an error occurs.

## Usage

To compile the program:

```bash
g++ cp.cpp -o cp
```

To run the program:

```bash
./cp source_file.txt destination_file.txt
```

Replace `source_file.txt` with the path of the file you want to copy, and `destination_file.txt` with the path where you want the copied file to be placed.

## Error Handling

- If the source file does not exist or cannot be opened, the program prints an error and exits.
- If the destination file cannot be created or written to, the program prints an error and exits.

---

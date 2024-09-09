# LS System Call Example

#### Explanation:

- **Directory Handling**: The program uses the `opendir()` function to open the directory specified in the command-line argument. If no directory is provided, it opens the current directory (`"."`).
- **Reading Entries**: The `readdir()` function is used to read the contents of the directory, which returns a `struct dirent` that contains information about each file. We then print the name of each file using `printf()`.
- **Closing Directory**: The directory is closed using `closedir()` to free resources.

---

## Overview

This folder contains a C program (`ls.c`) that implements a simple version of the Unix/Linux `ls` command, which lists the files and directories in a given directory. It uses system calls such as `opendir()`, `readdir()`, and `closedir()`.

## How It Works

1. The program accepts one optional command-line argument:

   - The path to the directory you want to list.

2. If no directory is provided, the program lists the contents of the current working directory.

3. The program opens the directory using the `opendir()` system call, reads the directory entries using `readdir()`, and prints the name of each file or subdirectory.

## Usage

To compile the program:

```bash
gcc ls.c -o ls
```

To run the program:

```bash
./ls [directory]
```

Replace `[directory]` with the path of the directory whose contents you want to list. If no directory is provided, it lists the contents of the current directory.

### Example

```bash
./ls /home/user
```

This will list all the files and directories inside `/home/user`.

## Error Handling

- If the directory cannot be opened (e.g., due to lack of permissions or an invalid path), the program will print an error message using `perror()`.

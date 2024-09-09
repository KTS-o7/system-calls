# RM System Call Example

#### Explanation:

- **Unlink System Call**: The program uses the `unlink()` system call, which removes (deletes) a file. In Unix-like systems, `unlink()` removes the file name and decreases the link count of the file. When the link count reaches zero and no process has the file open, the system frees the file resources.
- **Arguments**: The program accepts one argument, which is the path of the file to be deleted.
- **Error Handling**: If the file does not exist or the user lacks the required permissions to delete the file, an error is printed.

---

# RM System Call Example

## Overview

This folder contains a C program (`rm.c`) that implements a basic version of the Unix/Linux `rm` (remove) command using the `unlink()` system call. The program removes a file by unlinking it from the filesystem.

## How It Works

1. The program takes one command-line argument:

   - The path to the file you want to remove.

2. It calls the `unlink()` system call, which removes the file from the filesystem.

3. If the file cannot be deleted (e.g., due to lack of permissions or if the file does not exist), an error message is printed using `perror()`.

## Usage

To compile the program:

```bash
gcc rm.c -o rm
```

To run the program:

```bash
./rm file.txt
```

Replace `file.txt` with the name of the file you want to delete.

### Example

```bash
./rm /home/user/test.txt
```

This will delete the file `/home/user/test.txt`.

## Error Handling

- If the file cannot be deleted, an error message will be printed (e.g., if the file does not exist or the user lacks permissions).

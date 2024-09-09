# Hard Link System Call Example

#### Explanation:

- **Arguments**: The program expects two command-line arguments:
  1. The **source file**: The existing file you want to link.
  2. The **link name**: The new file name (the hard link).
- **link() System Call**: The `link()` system call creates a hard link. It makes a new directory entry (link) for an existing file. Both the original file and the hard link refer to the same data on disk.
  - `argv[1]` is the source file.
  - `argv[2]` is the new hard link name.
- **Error Handling**: If the hard link creation fails (e.g., the file doesn't exist, or permissions are insufficient), an error message is displayed using `perror()`.

---

## Overview

This folder contains a C program (`hardlink.c`) that demonstrates how to create a hard link between two files using the `link()` system call. A hard link allows two or more file names to point to the same inode (file content) on the filesystem.

## How It Works

1. The program takes two command-line arguments:

   - The path of the source file (existing file).
   - The name of the new hard link (new file name).

2. The `link()` system call creates a hard link between the two files. Both the source file and the link share the same inode, meaning they point to the same physical data on the disk.

3. If the hard link is successfully created, a message is printed to confirm the operation. If the operation fails, an error message is printed.

## Usage

To compile the program:

```bash
gcc hardlink.c -o hardlink
```

To run the program:

```bash
./hardlink source_file link_name
```

### Example

```bash
./hardlink file.txt link.txt
```

This command creates a hard link named `link.txt` that points to `file.txt`. Both files will share the same data on the disk.

## Error Handling

- If the source file does not exist, or if there are insufficient permissions to create the link, the program will print an appropriate error message.
- The program also checks if the correct number of arguments are passed before attempting to create the hard link.

## Important Notes

- Deleting the original file (`file.txt`) does not affect the hard link (`link.txt`). The data will still be accessible via the hard link until all links are deleted.
- Hard links can only be created on the same filesystem (i.e., they cannot link files across different filesystems or partitions).

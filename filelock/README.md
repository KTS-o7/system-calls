# File Lock Example

#### Explanation:

- **File Descriptor**: We open the file using `open()` with read and write permissions (`O_RDWR`).
- **fcntl() System Call**: This is used to apply a file lock. We use the `struct flock` to define the lock type:
  - `F_RDLCK`: A read lock (shared lock).
  - `F_WRLCK`: A write lock (exclusive lock).
  - `F_UNLCK`: Unlock the file.
- **Locking Mechanism**:
  - We attempt to lock the file with `fcntl()` using `F_SETLK`.
  - If the file is already locked by another process, `EACCES` or `EAGAIN` will be returned.
- **Simulating File Operation**: The program locks the file, simulates some work with `sleep()`, and then releases the lock.

---

## Overview

This folder contains a C program (`file_lock.c`) that demonstrates how to implement file locking using the `fcntl()` system call in Unix/Linux systems. It applies a write lock, simulates a file operation, and then unlocks the file.

## How It Works

1. **Opening the File**: The file is opened using `open()` in read-write mode (`O_RDWR`).
2. **Locking the File**: The `fcntl()` system call is used to lock the file:
   - `F_WRLCK`: Applies a write lock, which means no other process can read from or write to the file.
   - `F_RDLCK`: Applies a read lock, which means other processes can read but not write.
   - `F_UNLCK`: Unlocks the file, allowing other processes to access it.
3. **Simulating Operation**: The program locks the file, simulates a file operation (by sleeping for a few seconds), and then releases the lock.
4. **Error Handling**: If the file is already locked by another process, the program will display an appropriate error message.

## Usage

To compile the program:

```bash
gcc file_lock.c -o file_lock
```

To run the program:

```bash
./file_lock <file>
```

For example:

```bash
./file_lock test.txt
```

### Example Output

```bash
Write lock applied on file.
Simulating file operation...
File lock released.
```

## Important Notes

- **Locks and Concurrency**: File locks are useful in scenarios where multiple processes need to access or modify a file concurrently. A write lock prevents other processes from reading or writing to the file, while a read lock prevents writes but allows other reads.
- **Blocking vs Non-blocking**: The `fcntl()` system call can be used with `F_SETLKW` to make it block until the lock is available, or with `F_SETLK` to return immediately if the lock is unavailable.
- **Whole File Locking**: In this example, we lock the whole file (`lock.l_len = 0`). If partial file locking is required, you can specify a byte range using `l_start` and `l_len`.

## Error Handling

- If the file cannot be locked due to another process holding the lock, an error message is printed, and the program exits.

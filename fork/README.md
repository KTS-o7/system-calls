# Fork System Call with Parent and Child Example

#### Explanation:

- **Parent-Child Process**: The `fork()` call creates a new child process.
- **Child Process**:
  - The child process performs a simple addition of two numbers (`num1` and `num2`) and prints the result.
  - After completing the addition, the child process exits using `exit(0)`.
- **Parent Process**:
  - The parent process waits for the child to complete using the `wait()` system call. This ensures the parent waits for the child process to finish before continuing.
  - Once the child process finishes, the parent resumes execution and prints that it has finished waiting.

---

## Overview

This folder contains a C program (`fork_add.c`) that demonstrates how to use the `fork()` system call to create a parent and child process. The child process performs a simple addition of two numbers, while the parent process waits for the child to complete.

## How It Works

1. **Fork**: The program calls `fork()` to create a new child process.

   - The child process adds two predefined numbers (`num1` and `num2`) and prints the result.
   - The child process then exits using `exit(0)`.

2. **Wait**: The parent process calls `wait()` to wait for the child to finish its task. After the child process completes, the parent process resumes execution and prints a message.

## Usage

To compile the program:

```bash
gcc fork.c -o fork
```

To run the program:

```bash
./fork
```

### Example Output

```bash
Parent process (PID: 12345) is waiting for the child to finish...
Child process (PID: 12346) is adding 5 and 3
Child process (PID: 12346) calculated the result: 8
Parent process (PID: 12345) finished waiting. Child process completed.
```

## Error Handling

- If the `fork()` call fails, an error message is printed, and the program terminates.
- The parent uses `wait()` to ensure the child process completes before proceeding.

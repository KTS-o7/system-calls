# Multithreading with Mutex and Signals Example

#### Explanation:

- **Threads**: We create two threads using `pthread_create()`. One thread computes the sum, and the other computes the product.
- **Mutex**: The `pthread_mutex_t` is used to ensure that both threads can access shared data (i.e., `num1`, `num2`, `sum_result`, and `product_result`) safely. `pthread_mutex_lock()` and `pthread_mutex_unlock()` are used to lock and unlock the mutex around critical sections.
- **Signals**: The `pthread_kill()` function sends a signal from the sum thread to the product thread, which has a signal handler set using `signal()`. The product thread waits for the signal using `pause()`.
- **Signal Handler**: The `signal_handler()` function is triggered when the product thread receives the `SIGUSR1` signal. It then computes the product of the numbers and prints the result.

---

## Overview

This folder contains a C program (`threads.c`) that demonstrates the use of multithreading in C using POSIX threads (`pthread`). It showcases:

- Thread creation.
- Mutex for synchronization to ensure safe access to shared data.
- Signal handling to communicate between threads.

The program creates two threads:

- One to compute the sum of two numbers.
- One to compute the product of two numbers.

## How It Works

1. **Thread 1**: Computes the sum of `num1` and `num2` using a mutex to safely access shared data. After computing the sum, it sends a signal to **Thread 2**.
2. **Thread 2**: Waits for the signal from **Thread 1**. Once it receives the signal, it computes the product of `num1` and `num2`.
3. **Mutex**: A mutex is used to ensure that the threads access and modify shared data safely.
4. **Signal Handling**: **Thread 2** has a signal handler that is triggered when **Thread 1** sends a signal after computing the sum.

## Usage

To compile the program:

```bash
gcc threads.c -pthread -o threads
```

````

To run the program:

```bash
./threads
```

### Example Output

```bash
Thread 1: Sum of 5 and 3 is 8
Thread 2: Product of 5 and 3 is 15
```

## Error Handling

- The program checks for errors during mutex initialization and thread creation.
- It also ensures proper mutex destruction after the threads complete.

## Concepts

- **Mutex**: Used to prevent race conditions by allowing only one thread to access shared data at a time.
- **Signals**: Used for inter-thread communication. One thread can send a signal to another to notify it to perform some action.
````

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>

// Shared data
int num1 = 5, num2 = 3;
int sum_result = 0, product_result = 0;
pthread_mutex_t lock;

// Thread to compute sum
void *compute_sum(void *arg)
{
    printf("Thread 1: Before critical section\n");
    pthread_mutex_lock(&lock); // Lock mutex
    printf("Thread 1: Inside critical section\n");
    sum_result = num1 + num2;
    printf("Thread 1: Sum of %d and %d is %d\n", num1, num2, sum_result);
    num1 = 10; // Change num1 value
    printf("Thread 1: Updated num1 to %d\n", num1);
    pthread_mutex_unlock(&lock); // Unlock mutex
    printf("Thread 1: After critical section\n");

    // Send signal to other thread (product computation)
    pthread_kill(*(pthread_t *)arg, SIGUSR1);
    pthread_exit(0);
}

// Signal handler for product computation thread
void signal_handler(int sig)
{
    if (sig == SIGUSR1)
    {
        printf("Thread 2: Before critical section\n");
        pthread_mutex_lock(&lock); // Lock mutex
        printf("Thread 2: Inside critical section\n");
        product_result = num1 * num2;
        printf("Thread 2: Product of %d and %d is %d\n", num1, num2, product_result);
        pthread_mutex_unlock(&lock); // Unlock mutex
        printf("Thread 2: After critical section\n");
    }
}

void *compute_product(void *arg)
{
    // Set up signal handler
    signal(SIGUSR1, signal_handler);

    // Wait for signal from the other thread (sum computation)
    pause(); // Wait for signal
    pthread_exit(0);
}

int main()
{
    pthread_t sum_thread, product_thread;

    // Initialize mutex
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        perror("Mutex init failed");
        return 1;
    }

    // Create the product thread first
    pthread_create(&sum_thread, NULL, compute_product, NULL);

    // Create the sum thread and pass product_thread ID for signaling
    pthread_create(&product_thread, NULL, compute_sum, &sum_thread);

    // Wait for both threads to finish
    pthread_join(sum_thread, NULL);
    pthread_join(product_thread, NULL);

    // Destroy the mutex
    pthread_mutex_destroy(&lock);

    return 0;
}

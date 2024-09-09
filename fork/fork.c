#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int num1 = 5, num2 = 3;
    int result;
    pid_t pid;

    // Create a new process using fork
    pid = fork();

    if (pid < 0)
    {
        // Error occurred
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0)
    {
        // Child process
        printf("Child process (PID: %d) is adding %d and %d\n", getpid(), num1, num2);
        result = num1 + num2;
        printf("Child process (PID: %d) calculated the result: %d\n", getpid(), result);
        exit(0); // Child exits after completing the task
    }
    else
    {
        // Parent process
        printf("Parent process (PID: %d) is waiting for the child to finish...\n", getpid());
        wait(NULL); // Parent waits for the child process to complete
        printf("Parent process (PID: %d) finished waiting. Child process completed.\n", getpid());
    }

    return 0;
}

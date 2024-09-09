#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>

using namespace std;

int main() {
    int num1 = 5, num2 = 3;
    int result;
    pid_t pid;

    // Create a new process using fork
    pid = fork();

    if (pid < 0) {
        // Error occurred
        cerr << "Fork failed" << endl;
        return 1;
    } else if (pid == 0) {
        // Child process
        cout << "Child process (PID: " << getpid() << ") is adding " << num1 << " and " << num2 << endl;
        result = num1 + num2;
        cout << "Child process (PID: " << getpid() << ") calculated the result: " << result << endl;
        exit(0); // Child exits after completing the task
    } else {
        // Parent process
        cout << "Parent process (PID: " << getpid() << ") is waiting for the child to finish..." << endl;
        wait(NULL); // Parent waits for the child process to complete
        cout << "Parent process (PID: " << getpid() << ") finished waiting. Child process completed." << endl;
    }

    return 0;
}

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();   // Create a new process

    if (pid < 0) {
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        // Child process
        printf("This is child process\n");
        printf("Child PID: %d\n", getpid());
    }
    else {
        // Parent process
        printf("This is parent process\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
    }

    return 0;
}
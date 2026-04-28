#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();  // Create a new process

    if (pid < 0) {
        // Error
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        // Child process
        printf("Child Process\n");
        printf("PID: %d, Parent PID: %d\n", getpid(), getppid());
    }
    else {
        // Parent process
        printf("Parent Process\n");
        printf("PID: %d, Child PID: %d\n", getpid(), pid);
    }

    return 0;
}
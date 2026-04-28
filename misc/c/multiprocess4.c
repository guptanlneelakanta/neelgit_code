#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        while (1) {
            printf("Child PID: %d\n", getpid());
            sleep(2);
        }
    } else {
        // Parent process
        while (1) {
            printf("Parent PID: %d\n", getpid());
            sleep(3);
        }
    }

    return 0;
}
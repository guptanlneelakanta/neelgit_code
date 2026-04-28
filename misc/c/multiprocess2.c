#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {
    printf("Before fork\n");

    pid_t pid = fork();

    printf("After fork\n");

     if (pid == 0) {
        printf("I am Child\n");
    } else {
        printf("I am Parent\n");
    }


     if (pid == 0) {
        printf("Child running\n");
    } else {
        wait(NULL);  // Wait for child to finish
        printf("Parent after child\n");
    }


    return 0;
}
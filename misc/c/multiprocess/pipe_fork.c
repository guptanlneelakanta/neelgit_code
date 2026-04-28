#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];   // fd[0] = read, fd[1] = write
    char msg[] = "Hello from Parent";
    char buffer[100];

    pipe(fd);    // create pipe

    pid_t pid = fork();

    if (pid == 0) {
        // 👶 Child process (Reader)
        close(fd[1]);  // close write end

        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);

        close(fd[0]);
    } else {
        // 👨 Parent process (Writer)
        close(fd[0]);  // close read end
  printf("write : %s\n", msg);
        write(fd[1], msg, strlen(msg) + 1);

        close(fd[1]);
    }

    return 0;
}
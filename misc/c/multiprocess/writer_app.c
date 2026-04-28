#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main() {
    int fd;
    char *msg = "Hello from Process 1";

    printf("Writing: %s\n", msg);
    fd = open("myfifo", O_WRONLY);
    write(fd, msg, strlen(msg) + 1);

    close(fd);
    return 0;
}
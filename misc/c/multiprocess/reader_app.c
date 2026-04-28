#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main() {
    int fd;
    char buffer[100];

    fd = open("myfifo", O_RDONLY);
    if (fd < 0) {
        perror("open failed");
        return 1;
    }

    int n = read(fd, buffer, sizeof(buffer) - 1);

    if (n < 0) {
        perror("read failed");   // 🔥 shows actual error
        return 1;
    }

    buffer[n] = '\0';
    printf("Received: %s\n", buffer);

    close(fd);
    return 0;
}
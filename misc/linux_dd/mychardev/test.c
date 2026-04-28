#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;
    char buf[100];

    fd = open("/dev/mychardev", O_RDWR);

    write(fd, "Hello Kernel", 12);

    lseek(fd, 0, SEEK_SET);
    read(fd, buf, sizeof(buf));

    printf("Read from driver: %s\n", buf);

    close(fd);
    return 0;
}

#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    size_t size = 4096; // 1 page

    // Allocate virtual memory
    int *ptr = mmap(NULL, size,
                    PROT_READ | PROT_WRITE,
                    MAP_PRIVATE | MAP_ANONYMOUS,
                    -1, 0);

    if (ptr == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }

    // Use memory
    ptr[0] = 100;
    ptr[1] = 200;

    printf("%d %d\n", ptr[0], ptr[1]);

    // Free memory
    munmap(ptr, size);

    return 0;
}
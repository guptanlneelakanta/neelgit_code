#include <stdio.h>

// Standard Padded Structure (Compiler adds extra bytes)
struct Padded {
    char a;     // 1 byte
    int b;      // 4 bytes
    char c;     // 1 byte
};

// Packed Structure (Compiler removes extra bytes)
struct __attribute__((packed)) Packed {
    char a;     // 1 byte
    int b;      // 4 bytes
    char c;     // 1 byte
};

int main() {
    printf("Size of Padded struct: %zu bytes\n", sizeof(struct Padded));
    printf("Size of Packed struct: %zu bytes\n", sizeof(struct Packed));

    struct Packed p = {'A', 100, 'Z'};
    
    // You can access members normally
    printf("\nPacked Data: a=%c, b=%d, c=%c\n", p.a, p.b, p.c);

    return 0;
}
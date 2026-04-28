#include <stdio.h>
#include <stdbool.h>

#define BUFFER_SIZE 5

typedef struct {
    int data[BUFFER_SIZE];
    int head;   // write index
    int tail;   // read index
    int count;  // number of elements
} circ_buf_t;

/* Initialize buffer */
void init(circ_buf_t *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

/* Check if full */
bool is_full(circ_buf_t *cb) {
    return cb->count == BUFFER_SIZE;
}

/* Check if empty */
bool is_empty(circ_buf_t *cb) {
    return cb->count == 0;
}

/* Push (enqueue) */
bool push(circ_buf_t *cb, int item) {
    if (is_full(cb)) {
        printf("Buffer FULL!\n");
        return false;
    }

    cb->data[cb->head] = item;
    printf("Pushed %d at %d\n", item, cb->head);

    cb->head = (cb->head + 1) % BUFFER_SIZE;
    cb->count++;

    return true;
}

/* Pop (dequeue) */
bool pop(circ_buf_t *cb, int *item) {
    if (is_empty(cb)) {
        printf("Buffer EMPTY!\n");
        return false;
    }

    *item = cb->data[cb->tail];
    printf("Popped %d from %d\n", *item, cb->tail);

    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    cb->count--;

    return true;
}

/* Print buffer state */
void print_buffer(circ_buf_t *cb) {
    printf("Buffer: ");
    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%d ", cb->data[i]);
    }
    printf("\nHead=%d Tail=%d Count=%d\n", cb->head, cb->tail, cb->count);
}

int main() {
    circ_buf_t cb;
    int val;

    init(&cb);

    push(&cb, 10);
    push(&cb, 20);
    push(&cb, 30);
    push(&cb, 31);
    push(&cb, 32);
    push(&cb, 33);

    pop(&cb, &val);
    pop(&cb, &val);

    push(&cb, 40);
    push(&cb, 50);
    //push(&cb, 60);  // wrap happens here

    print_buffer(&cb);

    return 0;
}

#include <stdio.h>
#include <stdbool.h>

#define BUFFER_SIZE 5

typedef struct
{
    int buffer[BUFFER_SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

void initBuffer(CircularBuffer *cb)
{
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

bool isFull(CircularBuffer *cb)
{
    return cb->count == BUFFER_SIZE;
}

bool isEmpty(CircularBuffer *cb)
{
    return cb->count == 0;
}



bool dequeue(CircularBuffer *cb, int *data)
{
    if (isEmpty(cb))
        return false;

    *data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    cb->count--;
printf("\ndq cb->count=%d", cb->count);
    return true;
}

bool enqueue(CircularBuffer *cb, int data)
{
    if (isFull(cb))
        return false;

    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % BUFFER_SIZE;
    cb->count++;
printf("\neq cb->count=%d", cb->count);
    return true;
}

int main()
{
    CircularBuffer cb;
    initBuffer(&cb);
int d;
    enqueue(&cb, 10);
    enqueue(&cb, 20);
    enqueue(&cb, 30);
    enqueue(&cb, 40);
    enqueue(&cb, 50);
    

    dequeue(&cb, &d);
      printf("Read: %d\n", d);
      enqueue(&cb, 60);
    dequeue(&cb, &d);
    enqueue(&cb, 61);
      printf("Read: %d\n", d);
    dequeue(&cb, &d);
      printf("Read: %d\n", d);
    enqueue(&cb, 62);

    int value;
    int cnt=0;

    while (dequeue(&cb, &value))
    {
        printf("Read: %d\n", value);
        enqueue(&cb, 60);
        if(cnt++>5)
        break;
    }

    return 0;
}
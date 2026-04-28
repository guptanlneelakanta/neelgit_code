#include<stdio.h>

struct circularbuf{
    int data[5];
    int head;
    int tail;
    int count;
};

void init(struct circularbuf *cb)
{
    cb->head=0;
    cb->tail=0;
    cb->count=0;
}

void push(struct circularbuf *cb, int item)
{
    if(cb->count==5)
    {
        printf("Buffer FULL!\n");
        return;
    }

    cb->data[cb->head]=item;
    printf("Pushed %d at %d\n", item, cb->head);

    cb->head=(cb->head+1)%5;
    cb->count++;
}

int pop(struct circularbuf *cb)
{
    if(cb->count == 0)
    {
        printf("Buffer EMPTY!\n");
        return -1;
    }

    int item = cb->data[cb->tail];
    printf("\n pop : %d", item);
    cb->tail = (cb->tail + 1) % 5;
    cb->count--;
    return item;
}



int main()
{
    struct circularbuf cb;
    init(&cb);

    int val;

    push(&cb,10);
    push(&cb,20);
    push(&cb,30);
    push(&cb,40);
    push(&cb,50);
    push(&cb,64);

    val = pop(&cb);
       val = pop(&cb);
       push(&cb,41);
       push(&cb,42);
       push(&cb,43);
}
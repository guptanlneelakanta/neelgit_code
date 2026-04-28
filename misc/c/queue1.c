#include<stdio.h>
#define MAX 5
int rear=-1, front=-1;
int queue[5];

void enque(int num)
{
    printf("\n rear = %d", rear);
      rear++;
    if(rear > (MAX-1))
    {
        rear--;        
        printf("\n queue is overflow");
        return ;
    }

    if (front == -1)
    front =0;

    queue[rear] = num;
    printf("\n queue[%d] =%d", rear,queue[rear]);
}

int deque()
{
    int rnval=0;
    printf("\n front  = %d", front);
    if(front==-1 || front > rear )
    {
        rear=0;
        printf("\n queue is underflow");
    }    
    printf("\n queue[%d] = %d", front, queue[front]);
    rnval=queue[0];
    front=0;

    for(int i=0; i<=rear; i++)
        queue[i] = queue[i+1];
        
    rear=rear-1;
    printf("\n 2. rear =%d", rear);
    return rnval;    
}

void display()
{
    printf("\n queue data:");
    for(int i=0; i<MAX; i++)
        printf(" queue[%d] = %d  ", i, queue[i]);
}

int main()
{
    int v;
enque(33);
enque(23);
enque(13);
enque(14);
enque(15);
enque(17);

display();
v=deque();
display();
v=deque();
display();
v=deque();
enque(219);
display();
v=deque();
display();
v=deque();
enque(19);
display();
v=deque();
printf("\n");

}
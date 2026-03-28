#include<stdio.h>
#include<malloc.h>

struct list{
int data;
struct list *next;
};

struct list *ptr, *prev, *head;

void push1(struct list **h, int d)
{
    struct list *new = (struct list *)malloc(sizeof(struct list));
    new->data = d ;    
    new->next =*h;
    *h=new;
        
}

void printlist1(struct list **h)
{
for(ptr=*h; ptr; ptr=ptr->next)
{
    printf(" %d -> ", ptr->data);
}

}

static void reverse(struct list** head_ref)
{
    struct list* prev = NULL;
    struct list* current = *head_ref;
    struct list* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_ref = prev;

     printf("\n reverse list :\n ");

    for(ptr=*head_ref; ptr; ptr=ptr->next)
    {
        printf(" %d -> ", ptr->data);
    }   
}


void reverse1()
{
    struct list *next=NULL;
    struct list *prev=NULL;
    struct list *current= head;

    while(current != NULL)
    {
        next = current->next ;
        current->next = prev;
        prev= current;
        current = next;
    }
    
    head = prev;
    printf("\n reverse list :\n ");

    for(ptr=head; ptr; ptr=ptr->next)
    {
        printf(" %d -> ", ptr->data);
    }   
}

void push( int d)
{
    struct list *new = (struct list *)malloc(sizeof(struct list));
    new->data = d ;    
    new->next =head;
    head=new;
        
}

void printlist()
{
    for(ptr=head; ptr; ptr=ptr->next)
    {
        printf(" %d -> ", ptr->data);
    }
}

int main()
{
    ptr=prev=head=NULL;
    /*
    push(&head, 5);
    push(&head, 25);
    push(&head, 53);
    push(&head, 51);
    printlist(&head);
    */

    push( 5);
    push( 25);
    push( 53);
    push( 51);
    printlist();

    //reverse(&head);
    reverse1();
}


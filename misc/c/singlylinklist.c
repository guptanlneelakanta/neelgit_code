#include<stdio.h>
#include<malloc.h>


	struct slist_ {
		struct slist *next;
		int data;
	};
	
	typedef struct slist_ slist; 

	slist *start=NULL, *ptr=NULL, *prev=NULL, *node=NULL;


	slist *createnode(int d)
	{
		node=(slist*)malloc(sizeof(slist));
		node->data = d;
		node->next=NULL;
		return node;
	}

	void insertend(slist **head, int d)
	{
		 slist *node = createnode(d);
		if (*head==NULL)
		{
			*head=node;
			return;
		}
		slist *temp= *head;

		while(temp->next != NULL)
		{
			temp=temp->next;
		}
		
		temp->next=node;	
	}

	void insertfront(slist **head, int d)
	{
		slist *node = createnode(d);
		node->next=*head;
		*head=node;
	}

	print(slist *head)
	{
	
		slist *temp=head;
		while(temp !=NULL)
		{
		printf("%d->", temp->data);
		temp=temp->next;
		}
	}
	
	void deletenode(slist **head, int d)
	{
		slist *temp=*head;
		slist *prev=*head;
		
		if (temp->data == d)
		{
		temp=temp->next;
		*head=temp;
		free(prev);
		return;
		}

		while(temp != NULL)
		{

	 		if(temp->data == d)
			{				
				prev->next = temp->next;
				free(temp);
				return;  
			}
			prev=temp;		
			temp = temp->next;	
		}
	}	
	
			
int main()
{
	slist *head=NULL;  //(slist*)malloc(sizeof(slist));

	insertend(&head, 23);
	insertend(&head, 43);
	insertend(&head, 3);
	insertfront(&head, 6);

	deletenode(&head, 6);
	deletenode(&head, 23);	
	deletenode(&head, 3);

	print(head);
}



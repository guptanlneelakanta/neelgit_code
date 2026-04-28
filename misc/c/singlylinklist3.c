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

	void insertend(slist *head, int d)
	{
		 slist *node = createnode(d);
		if (head==NULL)
		{
			head=node;
			return;
		}
		slist *temp = head;

		while(temp->next != NULL)
		{
			temp=temp->next;
		}
		
		temp->next=node;	
	}

	void insertfront(slist *head, int d)
	{
		slist *node = createnode(d);
		if (head==NULL)
		{
			head=node;
			return;
		}
		
		node->next=head;
		head=node;
	}

	print(slist *head)
	{
		printf("\n");
		slist *temp=head;
		while(temp !=NULL)
		{
		printf("%d->", temp->data);
		temp=temp->next;
		}
		printf("\n");
	}
	
	void deletenode(slist *head, int d)
	{
		slist *temp=head;
		slist *prev=head;
		
		if (temp->data == d)
		{
		head=temp->next;
		free(temp);
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
	slist *head=(slist*)malloc(sizeof(slist));

	insertend(head, 23);
	insertend(head, 43);
	insertend(head, 3);
	insertfront(head, 6);
	print(head);

	deletenode(head, 6);
	print(head);
	deletenode(head, 23);	
	print(head);
	deletenode(head, 3);

	print(head);
}



#include<stdio.h>
#include<malloc.h>


struct Node{
int vertex;
struct node *next;
};

struct Graph{
int vertices;
struct node **adjLists;
};


struct Node * createNode(int v)
{
struct Node *newnode = malloc(sizeof(struct Node));
newnode->vertex = v;
newnode->next=NULL;
return newnode;
}

struct Node * createGraph(int v)
{
struct Graph *newgraph = malloc(sizeof(struct Graph));
newgraph->vertices =v;
newgraph->adjLists= malloc(vertices * sizeof(struct Graph));

for(int i=0; i< vertices; i++)
{
    newgraph[]->adjLists[i] = NULL;
}

return newgraph;
}

void addedge(struct Graph *graph, int src, int dest)
{
    struct Node *node=createNode(dest);
    node->next = graph->adjLists[src] ;
    graph->adjLists[src] = node;
 
    // undirected graph
    node = createNode(src);
    node->next = graph->adjLists[src];
    graph->adjLists[src] = node;
}

void printgraph(struct Graph *graph)
{
    for(int v=0; v< graph->vertices; v++)
    {
        struct Node *temp = graph->adjLists[v];
        printf("Vertex %d", v);
        while(temp)
        {
            printf("%d", temp->vertex);
            temp=temp->next;
        }
        printf("NULL");
    }

}

int main()
{
    struct Graph *graph = createGraph(4);
    addedge(graph, 0,1);
    addedge(graph, 0,2);
    addedge(graph, 1,3);
    addedge(graph, 2,3);
    printgraph(graph);
}






int main()
{

}
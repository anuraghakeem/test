#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1
typedef struct N
{
    int vertex;
    struct N *next;
}node;
typedef node *nodeptr;
nodeptr graph[30];
int q[30]={0};
int i=0,max,visited[30]={0},front=0,rear=0;
void addq(int v)
{
    q[rear++]=v;
}
int deleteq()
{
    return(q[front++]);
}

void BFS(int v)
{
    nodeptr temp;
    printf("%d ",v);
    visited[v]=TRUE;
    front=0;
    rear=0;
    addq(v);
    while(front<=rear)
    {
        v=deleteq();
        for(temp=graph[v];temp;temp=temp->next)
            if(!visited[temp->vertex])
        {
            printf("%d ",temp->vertex);
            addq(temp->vertex);
            visited[temp->vertex]=TRUE;
        }
    }
}
void insert(int vi,int vj)
{
 node *p,*q;
 //acquire memory for the new node
 q=(node *)malloc(sizeof(node));
 q->vertex=vj;
 q->next=NULL;
 //insert the node in the linked list for the vertex no. vi
 if(graph[vi]==NULL)
  graph[vi]=q;
 else
 {
  // go to the end of linked list
  p=graph[vi];
  while(p->next!=NULL)
   p=p->next;
  p->next=q;
 }
}
void readgraph()
{  int i,vi,vj,no_of_edges,n;
 printf("\nEnter no. of vertices :");
 scanf("%d",&n);
 //initialise G[] with NULL
 for(i=0;i<n;i++)
  graph[i]=NULL;
 //read edges and insert them in G[]
 printf("\nEnter no of edges :");
 scanf("%d",&no_of_edges);
 for(i=0;i<no_of_edges;i++)
 {
  printf("\nEnter an edge (u,v)  :");
  scanf("%d%d",&vi,&vj);
  insert(vi,vj);
  insert(vj,vi);
 }
}
void main()
{
 int i,op;
 do
   { printf("\n\n1)Create\n2)BFS\n4)Quit");
     printf("\nEnter Your Choice: ");
     scanf("%d",&op);
     switch(op)
      { case 1: readgraph();break;
        case 2: printf("\nStarting Node No. : ");
         scanf("%d",&i);
         BFS(i);break;
       }
    }while(op!=4);
}

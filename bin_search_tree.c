#include<stdio.h>
#include<stdlib.h>
struct tree
{
	int data;
	struct tree *rlink;
	struct tree *llink;
};
typedef struct tree * treeptr;
void insert(treeptr *root,int item)
{

	if(!(*root))
	{
		*root=(treeptr)malloc(sizeof(treeptr*));
		(*root)->data=item;
		(*root)->llink=NULL;
		(*root)->rlink=NULL;
		return;
	}
	else if((*root)->data>item)
		insert(&(*root)->llink,item);
	else if((*root)->data<item)
		insert(&(*root)->rlink,item);	
}
void inorder(treeptr root)
{
	if(root)
	{
		inorder(root->llink);
		printf("%d\t",root->data);
		inorder(root->rlink);
	}
}
void search(treeptr root,int item)
{
	if(root==NULL)
	{
		printf("\nNot found");
		return;
	}
	else if(root->data==item)
	{
		printf("\nFound");
		return;
	}
	else if(root->data>item)
		search(root->llink,item);
	else if(root->data<item)
		search(root->rlink,item);
}
int main()
{
	int ch,item;
	treeptr root;
	root=NULL;
	while(1)
	{
		printf("\n1.Insert\n2.InOrder\n3.Search\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter element to be inserted:\t");
				scanf("%d",&item);
				insert(&root,item);
				break;
			case 2:
				inorder(root);
				break;
			case 3:
				printf("\nEnter element to be deleted");
				scanf("%d",&item);
				search(root,item);
				break;
			case 4:
				exit(1);
		}
	}
}

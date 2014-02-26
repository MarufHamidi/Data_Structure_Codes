Program for demonstration of Tree Operations - INSERTION . INORDER .
PREORDER . POSTORDER TRAVERSAL

# include<stdio.h>
# include <conio.h>
# include <malloc.h>

struct node
{
struct node *left;
int data;
struct node *right;
}     ;

void main()
{
void insert(struct node **,int);
void inorder(struct node *);
void postorder(struct node *);
void preorder(struct node *);
struct node *ptr;
int will,i,num;
ptr = NULL;
ptr->data=NULL;
clrscr();

printf("
Enter the number of terms you want to add to the tree.
");
scanf("%d",&will);

/* Getting Input */
for(i=0;i<will;i++)
	{
	printf("
Enter the item");
	scanf("%d",&num);
	insert(&ptr,num);
	}

getch();
printf("

		INORDER TRAVERSAL

");
inorder(ptr);
getch();
printf("

		PREORDER TRAVERSAL

");
preorder(ptr);
getch();
printf("

		POSTORDER TRAVERSAL

");
postorder(ptr);
getch();
}



void insert(struct node  **p,int num)
{


if((*p)==NULL)
{       printf("
Leaf node created.");
	(*p)=malloc(sizeof(struct node));
	(*p)->left = NULL;
	(*p)->right = NULL;
	(*p)->data = num;
	return;
}
else
{       if(num==(*p)->data)
		{
		printf("

		REPEATED ENTRY ERROR
		VALUE REJECTED

");
		return;
		}
	if(num<(*p)->data)
		{
			printf("
Directed to left link.");
			insert(&((*p)->left),num);
		}
	else
		{
		printf("
Directed to right link.");
		insert(&((*p)->right),num);
		}
}
return;
}


void inorder(struct node *p)
{
	if(p!=NULL)
		{
		inorder(p->left);
		printf("
Data :%d",p->data);
		inorder(p->right);
		}
	else
		return;
}


void preorder(struct node *p)
{
	if(p!=NULL)
		{
		printf("
Data :%d",p->data);
		preorder(p->left);
		preorder(p->right);
		}
	else
		return;
}


void postorder(struct node *p)
{
	if(p!=NULL)
		{
		postorder(p->left);
		postorder(p->right);
		printf("
Data :%d",p->data);
		}
	else
		return;
}

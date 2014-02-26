#include<iostream.h>
#include<conio.h>
#include<alloc.h>
 
// node structure follwos. each node has 3 parts : Value or info, No. of children, an array of pointers (dynamic) to point to n child nodes
struct GTreeNode
{
     int val;
     int NChild;
     GTreeNode **Child;
}**Root=NULL;
 
void CreateGeneralTree(GTreeNode**,int);
void ShowGeneralTree(GTreeNode*);         //will show  details of all nodes, one by one, not working fine. 
void ShowGTNode(GTreeNode *R);            //will dhow details of one node. ok.
 
void main()
{
	int i, val, n;
	GTreeNode *NewNode ;
	clrscr();
	//Create Root Node.
	cout<<"\nEnter Root Val " ;
	cin>>val ;
	cout<<"Enter No. of Children "  ;
	cin>>n;
 
	NewNode=(GTreeNode *)malloc(sizeof(GTreeNode)*n);
	NewNode->val=val;
	NewNode->NChild=n;   //new node has n children
	for(i=0;i<n;i++)
		NewNode->Child[i]=(GTreeNode*)NULL;  //initiall ymake them all  Null
	Root=&NewNode; // root points to newnode. root is root of tree.
	CreateGeneralTree(Root,n); //now get details of n childern of root & their children
	//ShowGeneralTree(NewNode);
getch();
}
 
void CreateGeneralTree(GTreeNode **r, int n)
{
	int i,k, m;
	char ch ;
 
	//allocate memory for n children.
	(*r)->Child=(GTreeNode**)malloc(n*sizeof(GTreeNode));
	//Enter values of Child Nodes.
	cout<<"\nNode Created at : "<< r<<"\n";
	for(i=0;i<n;i++)
	{
		cout<<"\tEnter value for Child "<< i << " : ";
		cin>>(*r)->Child[i]->val;
		(*r)->Child[i]->NChild=0;
		(*r)->Child[i]->Child=NULL;
	}
	ShowGTNode(**r);  //chek is it ok.
	cout<<"\nDo You Wish to Enter Info of Child Nodes : ";
	ch=getche();
	if(ch=='y' || ch=='Y')
	{
		for(k=0;k<n;k++)
		{
			cout<<"\n "<<k<<" Enter No. of Children of " << (*r)->Child[k]->val<<"  : ";
			cin>>m;
			(*r)->Child[k]->NChild=m ;
			CreateGeneralTree(&((*r)->Child[k]),m);   //recurisive
		}
	}
}
 
void ShowGTNode(GTreeNode *R)
{
	int i, n=R->NChild;
	cout<<"\nNo. Of Children : "<<n ;
	for(i=0;i<n;i++)
		cout<<R->Child[i];
}
 
 
 
void ShowGeneralTree(GTreeNode *r)
{
     int i,n;
     n=r->NChild;
     cout<<"\nAddress : " <<r<<"\tValue : "<<r->val<<"\tChildren : "<<n<<"\t";
     for(i=0;i<n;i++)
	 cout<<"  "<<r->Child[i]->val;
     getch();
     for(i=0;i<n;i++)
	ShowGeneralTree(r->Child[i]);
}

                                  


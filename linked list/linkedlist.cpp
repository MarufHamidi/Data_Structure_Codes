#include<iostream>
#include<cstdlib>

using namespace std;

struct node{
    int num;
    struct node *next;
};

node *head;


void insertfirst(int n)
{
    node *temp;
    temp=(node*)malloc(sizeof(node));

    temp->num=n;
    temp->next=head;
    head=temp;
}

void insertlast(int a)
{
	node *test=new node;
	test->num=a;
	test->next=NULL;
	node *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	test->next=temp->next;
	temp->next=test;
}

void insertafter(int a,int b)
{
    node *newnode=new node;
    newnode->num=b;
    newnode->next=NULL;
    node *temp=head;
    for(;temp;temp=temp->next)
    {
        if(temp->num==a){
            break;
        }
    }
    if(!temp){
        cout<<"Element not found.";
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void search(int a)
{
    node *temp=head;
    for(;temp;temp=temp->next)
    {
        if(temp->num==a){
            cout<<"Found."<<endl;
            return;
        }
    }
    cout<<"Not found."<<endl;
}

void print()
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp=head;
    for(;temp!=NULL;)
    {
        cout<<temp->num<<endl;
        temp=temp->next;
    }
}

int main(void)
{
    head=(node*)malloc(sizeof(node));
    head=NULL;
    insertfirst(5);
    insertfirst(4);
    insertfirst(3);
    insertfirst(2);
    insertfirst(1);
    insertfirst(0);
    insertlast(6);
    insertlast(8);
    insertlast(9);
    insertafter(6,7);
    search(3000);
    search(3);

    //print();
    return 0;
}

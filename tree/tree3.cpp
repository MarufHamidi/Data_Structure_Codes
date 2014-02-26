#include<iostream>
#include<cstdlib>

using namespace std;

struct node{
    int data;
    struct node** container;
};

struct node* root = (node*)malloc(sizeof(node));

void datainput(node *temp)
{
    if(temp==NULL)
    {
        int child;
        cout<<"Enter the root : ";
        cin>>temp->data;
        cout<<"Enter the number of children of the root : ";
        cin>>child;
        if(child==0)return;
        temp->container = (node**)malloc(child*sizeof(node));
        for(int i=0;i<child;i++)
        {
            datainput(*(temp->container+i));
        }
    }
    else
    {
        int child;
        cout<<"Enter the node : ";
        cin>>temp->data;
        cout<<"Enter the number of children of the node <"<<temp->data<<">";
        cin>>child;
        if(child==0)return;
        temp->container = (node**)malloc(child*sizeof(node));
        for(int i=0;i<child;i++)
        {
            datainput(*(temp->container+i));
        }
    }
}

int main(void)
{
    root = (node*)malloc(sizeof(node));
    root=NULL;
    node* temp = (node*)malloc(sizeof(node));
    temp = root;
    datainput(temp);
    return 0;
}

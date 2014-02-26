#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

struct node{
    int data;
    int child;
    node *parent;
    node *container[10];
};

ifstream fin("tree.txt");


void getInput(node *root)
{
    if(root->parent==NULL)
    {
        int n,child;
        node *temp=(node*)malloc(sizeof(node));
        cout<<"Enter the root of the tree:";
        fin>>n;
        cout<<n<<endl;
        temp->data=n;
        cout<<"Enter the number of children of the root <"<<temp->data<<"> : ";
        fin>>child;
        cout<<child<<endl;
        temp->child=child;
        temp->parent=root;
        root=temp;
        //cout<<endl<<endl<<innode->data<<endl<<endl;
        for(int i=0;i<temp->child;i++)
        {
            temp->container[i]=(node*)malloc(sizeof(node));
            temp->container[i]->parent=temp;
            cout<<"Enter child "<<i+1<<" of root <"<<temp->data<<"> : ";
            getInput(temp->container[i]);
        }
    }
    else
    {
        int n2,child2;
        fin>>n2;
        cout<<n2<<endl;
        node *temp2=(node*)malloc(sizeof(node));
        temp2->data=n2;
        cout<<"Enter the number of children of the node <"<<temp2->data<<"> : ";
        fin>>child2;
        cout<<child2<<endl;
        temp2->child=child2;
        root=temp2;
        for(int j=0;j<temp2->child;j++)
        {
            temp2->container[j]=(node*)malloc(sizeof(node));
            temp2->container[j]->parent=temp2;
            cout<<"Enter child "<<j+1<<" of node <"<<temp2->data<<"> : ";
            getInput(temp2->container[j]);
        }
    }
}

void preorderTraversal(node *test)
{
    node *temp=(node*)malloc(sizeof(node));
    temp=test;
    cout<<temp->data<<"  ";
    for(int i=0;i<temp->child;i++)
    {
        preorderTraversal(temp->container[i]);
    }
}

int main(void)
{
    node *root;
    root = (node*)malloc(sizeof(node));
    root->parent = NULL;

    getInput(root);

    cout<<"Data recieved."<<endl;
    if(root!=NULL)cout<<"Not NULL";
    else cout<<"NULL";
    fin.close();
    //preorderTraversal(root);
    return 0;
}

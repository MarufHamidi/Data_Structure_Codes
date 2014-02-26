#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstdlib>

using namespace std;

struct node{
       char key;
       node *parent;
       node *left;
       node *right;
};



int main(void)
{
    ifstream fin("bstinput.txt");
    if(!fin){
             cout<<"Error opening file.";
             getch();
             exit(1);
    }
    char k;
    while(!fin.eof())
    {
        fin>>k;
        cout<<k<<" ";
        
    }
    getch();
    return 0;    
}

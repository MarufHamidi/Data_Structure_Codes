#include<iostream>
using namespace std;

class tree
{
	char data;
public:
	tree *parent;
	int children;
	tree * arr[100];

	tree() {children = 0;}
	int isExternal() { return !children; }
	int isInternal() { return children; }
	char get_data() { return data; }
	void take_data(char c) { data = c; }
} *root ;

void traversal_preorder( tree *ob )
{
	cout << ob->get_data();
	int i;
	for( i=0; i<ob->children ; i++ )
	{
		traversal_preorder( ob->arr[i] );
	}
}

void traversal_postorder( tree *ob )
{
	int i;
	for( i=0; i<ob->children ; i++)
	{
		traversal_postorder( ob->arr[i] );
	}
	cout << ob->get_data();
}



int main()
{
	tree *t = new tree;
	root = t;
	t->take_data('B');
	t->parent = t;
	t->children = 3;

	t->arr[0] = new tree;
	t->arr[0]->take_data('A');
	t->arr[0]->parent = t;

	t->arr[1] = new tree;
	t->arr[1]->take_data('D');
	t->arr[1]->parent = t;
	t->arr[1]->children = 2;

	t->arr[1]->arr[0] = new tree;
	t->arr[1]->arr[0]->take_data('C');
	t->arr[1]->arr[0]->parent = t->arr[1];

	t->arr[1]->arr[1] = new tree;
	t->arr[1]->arr[1]->take_data('E');
	t->arr[1]->arr[0]->parent = t->arr[1];

	t->arr[2] = new tree;
	t->arr[2]->take_data('F');
	t->arr[0]->parent = t;

	traversal_preorder(root);
	cout << '\n';
	traversal_postorder(root);

	return 0;
}
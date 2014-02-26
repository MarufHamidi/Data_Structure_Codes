#include<iostream>
using namespace std;

class b_tree
{
	int element;
public:
	b_tree *left_child;
	b_tree *right_child;
	b_tree *parent;
	int isExternal() { if( left_child == NULL && right_child == NULL ) return 1; else return 0; }
	int isInternal() { if( left_child != NULL || right_child != NULL ) return 1; else return 0; }
	void show_element() { cout << element; }
	void take_element( int n ) { element = n;}
	b_tree * sibling();
	friend void add( b_tree *ob );
};

b_tree *root = NULL;


b_tree * b_tree::sibling()
{
	if( this->parent->left_child == this ) return this->parent->right_child;
	else return this->parent->left_child;
}

void add( b_tree *ob )
{
	if( root == NULL )
	{
		root = ob;
		ob->parent = ob;
		ob->left_child = NULL;
		ob->right_child = NULL;
	}
	else
	{
		int flag = 0;
		b_tree *temp = root;
		b_tree *parent = NULL;

		while( temp != NULL )
		{
			if( ob->element < temp->element )
			{
				flag = 1;
				parent = temp;
				temp = temp->left_child;	
			}
			else
			{
				flag = 2;
				parent = temp;
				temp = temp->right_child;
			}
		}

		ob->parent = parent;
		if( flag == 1 ) parent->left_child = ob;
		else if( flag == 2 ) parent->right_child = ob;
	}
}

void print( b_tree *ob )
{
	ob->show_element();
	cout << '\n'<< "parent is : "; ob->parent->show_element(); 
	cout << '\n';
	//cout << "->";
	if(ob->left_child != NULL )print( ob->left_child );
	cout << "\t";
	if( ob->right_child != NULL )print( ob->right_child );
	cout << '\n';
}

void traversal_inorder( b_tree *ob )
{
	if( ob->isExternal() ) ob->show_element();
	else
	{
		if( ob->left_child != NULL )traversal_inorder(ob->left_child);
		ob->show_element();
		if( ob->right_child != NULL )traversal_inorder( ob->right_child );
	}
}

void traversal_preorder( b_tree *ob )
{
	ob->show_element();
	if( ob->left_child != NULL ) traversal_preorder(ob->left_child);
	if( ob->right_child != NULL ) traversal_preorder( ob->right_child );
}

void traversal_postorder( b_tree *ob )
{
	if( ob->isInternal() )
	{
		if( ob->left_child != NULL ) traversal_postorder( ob->left_child );
		if( ob->right_child != NULL ) traversal_postorder( ob->right_child );
		ob->show_element();
	}
	else
	{
		ob->show_element();
	}
}

int main()
{
	int i,n,k;
	cout << "How many numbers: ";
	cin >> n;

	for( i=0; i<n; i++)
	{
		cin >> k;
		b_tree *t = new b_tree;
		t->take_element(k);
		t->left_child = NULL;
		t->right_child = NULL;
		add(t);
	}
	traversal_inorder(root);
	cout << '\n';
	traversal_preorder(root);
	cout << '\n';
	traversal_postorder(root);
	return 0;
}
#include<iostream>
using namespace std;

class b_tree
{
	char element;
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
	friend void insert( b_tree *ob );
};

b_tree *root = NULL;

struct node
{
	b_tree value;
	node *left;
	node *right;
} *head = 0, *tail = 0;

class queue_dllist
{
	node *head, *tail;
public:
	queue_dllist() { head = tail = 0; }
	void enqueue( b_tree n );
	b_tree dequeue();
	int is_empty() { if( head == 0) return 1; else return 0; };
};

void queue_dllist::enqueue( b_tree n )
{
	node *p = new node;
	p->value = n;

	if(!head) head = p;
	
	p->left = tail;
	if(tail) tail->right = p;

	p->right = 0;
	tail = p;
}

b_tree queue_dllist::dequeue()
{
	if(head==0)
	{
		cout << "Queue is empty\n";
		exit(1);
	}

	node * h = head->right;
	b_tree temp = head->value;
	delete head;
	head = h;
	return temp;
}

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

void insert( b_tree *ob )
{
	char temp;
	cout << "Enter data: ";
	cin >> ob->element;
	cout << "\n";

	cout << "Left child of " << ob->element << "?(y/n) :";
	cin >> temp;

	if( temp == 'y' )
	{
		cout << "Left child of " << ob->element << " : " << endl;
		b_tree *t = new b_tree;
		
		ob->left_child = t;
		t->parent = ob;

		insert(t);
	}
	else ob->left_child = NULL;

	cout << "Right child of " << ob->element << "? (y/n) ";
	cin >> temp;

	if( temp == 'y' )
	{
		b_tree *t = new b_tree ;
		
		ob->right_child = t;
		t->parent = ob;

		insert(t);
	}
	else ob->right_child = NULL;
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

void traversal_levelorder( b_tree *ob )
{
	queue_dllist t;
	t.enqueue(*ob);

	while( !t.is_empty() )
	{
		b_tree temp = t.dequeue();
		if( temp.left_child != NULL ) t.enqueue(*temp.left_child);
		if( temp.right_child != NULL ) t.enqueue(*temp.right_child);
		temp.show_element();
	}
}

int main()
{
	/*
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
	*/
	b_tree *temp = new b_tree;
	root = temp;
	insert(temp);
	cout << "**** Inorder Traversal ****" << endl;
	traversal_inorder(root);
	cout << "\n\n";
	cout << "**** Preorder Traversal ****" << endl;
	traversal_preorder(root);
	cout << "\n\n";
	cout << "**** Postorder Traversal ****" << endl;
	traversal_postorder(root);
	cout << "\n\n";
	cout << "**** Levelorder Traversal ****" << endl;
	traversal_levelorder(root);
	cout << "\n\n";
	return 0;
}

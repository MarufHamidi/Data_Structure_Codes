#include<iostream>
#include<cstdlib>
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
	friend void insert( tree *ob );
} *root ;


struct node
{
	tree value;
	node *left;
	node *right;
} *head = 0, *tail = 0;

class queue_dllist
{
	node *head, *tail;
public:
	queue_dllist() { head = tail = 0; }
	void enqueue( tree n );
	tree dequeue();
	int is_empty() { if( head == 0) return 1; else return 0; };
};

void queue_dllist::enqueue( tree n )
{
	node *p = new node;
	p->value = n;

	if(!head) head = p;

	p->left = tail;
	if(tail) tail->right = p;

	p->right = 0;
	tail = p;
}

tree queue_dllist::dequeue()
{
	if(head==0)
	{
		cout << "Queue is empty\n";
		exit(1);
	}

	node * h = head->right;
	tree temp = head->value;
	delete head;
	head = h;
	return temp;
}


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

void traversal_levelorder( tree *ob )
{
	queue_dllist t;
	t.enqueue(*ob);

	while(!t.is_empty())
	{
		tree temp = t.dequeue();
		int i;
		for(i=0; i<temp.children; i++)
		{
			t.enqueue(*temp.arr[i]);
		}
		cout << temp.get_data();
	}
}

void insert( tree *ob )
{
	cout << "Enter data : ";
	cin >> ob->data;
	cout << "Enter number of children of " << ob->data << " : ";
	cin >> ob->children;
	cout << "\n";

	int i;
	for( i = 0; i< ob->children; i++ )
	{
		tree *t = new tree;
		cout << "For the child no. " << i+1 << " of " << ob->data << endl;

		ob->arr[i] = t;
		t->parent = ob;

		insert(t);
	}
}

int main()
{
	tree * t = new tree;
	root = t;

	insert(root);

	cout << "Preorder traversal:" << endl;
	traversal_preorder(root);
	cout << "\n\n";

	cout << "Postorder traversal:" << endl;
	traversal_postorder(root);
	cout << "\n\n";

	cout << "Level order traversal: " << endl;
	traversal_levelorder(root);
	cout << "\n\n";

	return 0;
}

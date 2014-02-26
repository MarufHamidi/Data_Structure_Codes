/*
#include<iostream>
using namespace std;

struct node
{
	int value;
	node *left;
	node *right;
} *head = 0, *tail = 0;

void insert_first( int n )
{
	node *p = new node;
	p->value = n;

	p->right = head;
	if(head)head->left = p;

	p->left = 0;
	head = p;

	if(p->right == 0) tail = p;
}

void insert_last( int n )
{
	//int i;
	node *temp = head;
	while( temp->right != 0)
		temp = temp->right;

	node *p = new node;
	p->value = n;
	p->left = temp;
	p->right = 0;
	temp->right = p;
	tail = p;
}

void del( int n )
{
	node *temp = head;
	int flag = 0;
	while (temp != 0)
	{
		if(temp->value == n)
		{
			flag = 1;
			if(temp->right) (temp->right)->left = temp->left;
			else tail = temp->left;
			if(temp->left) (temp->left)->right = temp->right;
			else head = temp->right;
			delete temp;
			break;
		}
		temp = temp->right;
	}
	if(!flag) cout << "number not found\n";
}

void show()
{
	node *temp = head;

	while(temp != 0)
	{
		cout << temp->value << "-> ";
		temp = temp->right;
	}
	cout << "\n";
}

void showreverse()
{
	node *temp = tail;
	while( temp != 0 )
	{
		cout << temp->value << "<-";
		temp = temp->left;
	}
	cout << "\n";
}

const int SIZE = 100;

class stack
{
	int top;
	int ar[SIZE];
public:
	stack() { top = 0; }
	void push( int n );
	int pop();
};

void stack::push( int n )
{
	if(top == (SIZE-1) )
	{
		cout << "Stack is full\n";
		return ;
	}

	ar[top] = n;
	top++;
}

int stack::pop()
{
	if(top==0)
	{
		cout << "Stack is empty\n";
		exit(1);
	}
	top--;
	return ar[top];
}

class queue
{
	int head,tail;
	int ar[SIZE];
public:
	queue() { head = 0; tail = 0; }
	void enqueue( int n );
	int dequeue();
};

void queue::enqueue( int n )
{
	if( tail == SIZE-1 )
	{
		cout << "Queue is full\n";
		return ;
	}

	ar[tail] = n;
	tail++;
}

int queue::dequeue()
{
	if( head == tail )
	{
		cout << "Queue is empty\n";
		exit(1);
	}
	return ar[head++];
}

class stack_dllist
{
	node *head;
public:
	stack_dllist() { head = 0; }
	void push( int n );
	int pop();
};

void stack_dllist::push ( int n )
{
	node *p = new node;
	p->value = n;

	p->right = head;
	if( head )head->left = p;

	p->left = 0;
	head = p;
}

int stack_dllist::pop()
{
	if( head == 0)
	{
		cout << "Stack is empty\n";
		exit(1);
	}
	else
	{
		int temp = head->value;
		node *h = head->right;
		delete head;
		head = h;
		return temp;
	}
}

class queue_dllist
{
	node *head, *tail;
public:
	queue_dllist() { head = tail = 0; }
	void enqueue( int n );
	int dequeue();
};

void queue_dllist::enqueue( int n )
{
	node *p = new node;
	p->value = n;

	if(!head) head = p;

	p->left = tail;
	if(tail) tail->right = p;

	p->right = 0;
	tail = p;
}

int queue_dllist::dequeue()
{
	if(head==0)
	{
		cout << "Queue is empty\n";
		exit(1);
	}

	node * h = head->right;
	int temp = head->value;
	delete head;
	head = h;
	return temp;
}


int main()
{

	int i,val;
	node *temp;
	int flag = 0;
	while(1)
	{
		cout << "Enter choice:\n 1 to add first\n 2 to add last\n 3 to delete\n 4 to show\n 5 to showreverse\n";
		cin >> i;

		switch(i)
		{
		case 1:
			cout << "Enter number to add: ";
			cin >> val;
			insert_first(val);
			break;

		case 2:
			cout << "Enter number to add: ";
			cin >> val;
			insert_last(val);
			break;
		case 3:
			cout << "Enter number to delete: ";
			cin >> val;
			del(val);
			break;
		case 4:
			show();
			break;
		case 5:
			showreverse();
			break;
		}
	}


	stack t;
	t.push(5);
	t.push(1);

	cout << t.pop() << endl;
	cout << t.pop() << endl;
	cout << t.pop() << endl;


	queue t;
	t.enqueue(5);
	t.enqueue(4);
	t.enqueue(1);

	cout << t.dequeue() << endl;
	cout << t.dequeue() << endl;
	cout << t.dequeue() << endl;
	cout << t.dequeue() << endl;


	stack_dllist t;
	t.push(5);
	t.push(1);

	cout << t.pop() << endl;
	cout << t.pop() << endl;
	cout << t.pop() << endl;

	queue_dllist t;
	t.enqueue(5);
	t.enqueue(4);
	t.enqueue(1);

	cout << t.dequeue() << endl;
	cout << t.dequeue() << endl;
	cout << t.dequeue() << endl;
	cout << t.dequeue() << endl;

	return 0;
}
*/
/*

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
	int i,n,k;
	*/
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
	/*
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
*/
/*
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
*/
#include<iostream>
#include<stdio.h>
#include<cstdlib>

#define WHITE 1
#define GRAY 2
#define BLACK 3

using namespace std;

struct node
{
	char value;
	node *left;
	node *right;
} *head = 0, *tail = 0;

class queue_dllist
{
	node *head, *tail;
public:
	queue_dllist() { head = tail = NULL; }
	void enqueue( char n );
	char dequeue();
	int is_empty() { if (head == NULL) return 1; else return 0; }
};

void queue_dllist::enqueue( char n )
{
	node *p = new node;
	p->value = n;

	if(!head) head = p;

	p->left = tail;
	if(tail) tail->right = p;

	p->right = 0;
	tail = p;
}

char queue_dllist::dequeue()
{
	if(head==0)
	{
		cout << "Queue is empty\n";
		exit(1);
	}

	node * h = head->right;
	int temp = head->value;
	delete head;
	head = h;
	return temp;
}



class LinkedList
{
	char num;
	LinkedList *next;
	LinkedList *head;
	int length;
	char parent;

public:
	int color;
	int distance;
	int discovery;
	int finish;

	LinkedList() { head = NULL; length = 0; color = WHITE; distance = 9999; parent = 0;discovery = 0; finish=0;}
	void insert(char ch);
	void del(char ch);
	void show();
	void set_parent( char ch ){ parent = ch;}
	void reset() { color = WHITE; parent=0; discovery = 0; finish=0; }
	friend void BFS(LinkedList *a, char pos);
	friend void DFS(LinkedList *a, char pos);
};

void LinkedList::insert( char ch )
{
	LinkedList *temp = new LinkedList;
	temp->num = ch;
	LinkedList *t = head;

	if( head == NULL )
	{
		head = temp;
	}
	else
	{
		while(t->next != NULL)
		{
			t = t->next;
		}
		t->next = temp;
	}
	temp->next = NULL;
	length++;
}

void LinkedList::del( char ch )
{
	LinkedList *prev=NULL;
	LinkedList *cur = head;
	int flag = 0; // not found

	while(cur != NULL)
	{
		if(cur->num == ch )
		{
			flag = 1;
			break;
		}
		prev = cur;
		cur = cur->next;
	}

	if( flag == 1 && prev==NULL)
	{
		LinkedList *temp = head->next;
		delete head;
		head = temp;
	}
	else if( flag == 1 )
	{
		LinkedList *temp = cur->next;
		prev->next = temp;
		delete cur;
	}
	else
	{
		cout << "not found" << endl;
	}
}

void LinkedList::show()
{
	LinkedList *temp = head;
	while( temp != NULL)
	{
		cout << temp->num << ' ';
		temp = temp->next;
	}
}


void BFS(LinkedList *a, char pos )
{
	a[pos].color = GRAY;
	a[pos].distance = 0;
	a[pos].set_parent(0);
	queue_dllist q;
	q.enqueue(pos);

	while( !q.is_empty() )
	{
		char c = q.dequeue();
		LinkedList *temp = a[c].head;
		while(temp != NULL)
		{
			char d = temp->num;
			if(a[d].color == WHITE)
			{
				a[d].color = GRAY;
				a[d].distance = a[c].distance + 1;
				a[d].parent = c;
				q.enqueue(d);
			}
			temp = temp->next;
		}
		a[c].color = BLACK;
		cout << c << ' ';
	}
}

int time = 0;

void DFS( LinkedList *a, char ar)
{
	time = time + 1;
	a[ar].discovery = time;
	a[ar].color = GRAY;
	LinkedList *temp = a[ar].head;

	while( temp != NULL )
	{
		char d = temp->num;
		if( a[d].color == WHITE )
		{
			a[d].set_parent(ar);
			a[d].color = GRAY;
			DFS(a,d);
		}
		temp = temp->next;
	}
	a[ar].color = BLACK;
	time++;
	a[ar].finish = time;
	cout << ar << '(' << a[ar].discovery << ',' << a[ar].finish << ") ";


}


int main()
{
	FILE *fp = fopen("data.txt","r");
	LinkedList a[1000];
	char *ch,e,avoid;
	int no_vertex;
	int no_edge;
	int k,flag;

	fscanf(fp,"%d",&no_vertex);
	fscanf(fp,"%d",&no_edge);
	fscanf(fp,"%c",&avoid);
	cout << "no of vertex: " << no_vertex << endl;
	cout << "no of edge: " << no_edge << endl;
	ch = new char[no_vertex];
	for(k=0; k<no_vertex; k++) ch[k]=0;
	int i,j=0;

	for(i=0; i<no_edge; i++)
	{
		char c,d;
		fscanf(fp,"%c%c%c%c",&c,&avoid,&d,&avoid);
		flag = 0;
		for(k=0; k<=j; k++)
		{
			if(ch[k]==c){
				flag = 1;
				break;
			}
		}
		if( flag == 0) ch[j++] = c;
		a[c].insert(d);
		cout << c << ' ' << d << endl;
	}
	for(i=0; i<no_vertex; i++) cout << "vertex: " << ch[i] << endl ;
	fscanf(fp,"%c",&e);
	cout << "starting vertex: " << e << endl;

	//cout << "Enter number of vertex: ";
	//cin >> size;
	/*int i;
	char data;

	for( i = 0; i<size; i++ )
	{
		cout << "Enter data: ";
		cin >> data;
		ch[i] = data;
		int j;
		int data_size;
		cout << "Enter number of adjacent vertices: ";
		cin >> data_size;

		for( j=0; j<data_size; j++ )
		{
			cout << "Enter adjacent vertex " << j+1 << ": ";
			char cha;
			cin >> cha;
			a[data].insert(cha);
		}
	}

	char e;
	cout << "Enter source vertex: ";
	cin >> e;*/
	cout << "***********BFS**********" << endl;
	BFS(a,e);
	int counter=1;
	for(i=0; i<no_vertex; i++)
	{
		if( a[ch[i]].color == WHITE && ch[i]!=e)
		{
			BFS(a,ch[i]);
			counter++;
		}
	}
	cout << "counter: " << counter << endl;

	cout << "***********BFS**********" << endl;

	for(i=0; i<200; i++)
	{
		a[i].reset();
	}
	counter = 1;

	cout << "***********DFS**********" << endl;

	DFS(a,e);

	for(i=0; i<no_vertex; i++)
	{
		if( a[ch[i]].color == WHITE && ch[i]!=e)
		{
			cout << "ch = " << ch[i] << endl;
			DFS(a,ch[i]);
			counter++;
		}
	}

	//cout << "counter: " << counter << endl;
	cout << "***********DFS**********" << endl;
	return 0;
}

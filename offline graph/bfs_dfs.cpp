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
	cout << "***********DFS**********" << endl;
	return 0;
}

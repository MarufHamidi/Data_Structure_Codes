template<typename ob>

class deque
{
	struct node
	{
		ob e;
		node * next;
		node * prev;

		node(ob o=ob(),node* p = 0 ,node* q = 0)
		{
			e=o;
			prev=p;
			next=q;
		}
	};
	typedef node* nodeptr;
	nodeptr header,trailer;	
	int sz;

public:
	deque()
	{
		sz=0;
		header=new node;
		trailer=new node;
		header->next=trailer;
		trailer->prev=header;
	}
	int size()
	{
		return sz;
	}
	bool isEmpty()
	{
		return (sz==0);
	}
	void insertFirst(ob o)
	{
		nodeptr p = new node(o,header,header->next);
		p->prev->next=p;
		p->next->prev=p;
		sz++;
	}
	void insertLast(ob o)
	{
		nodeptr p = new node(o,trailer->prev,trailer);
		p->prev->next=p;
		p->next->prev=p;
		sz++;
	}
	void removeFirst()
	{
		nodeptr p=header->next;
		header->next=p->next;
		p->next->prev=header;
		delete p;
		sz--;
	}
	void removeLast()
	{
		nodeptr p=trailer->prev;
		trailer->prev=p->prev;
		p->prev->next=trailer;
		delete p;
		sz--;
	}
	ob first()
	{
		return (header->next->e);
	}
	ob last()
	{
		return (trailer->prev->e);
	}
};
/*
int main()
{
	deque<int>d;

	d.insertFirst(3);
	d.insertFirst(5);
	cout << d.first() << endl;
	d.removeFirst();
	d.insertLast(7);
	cout << d.last() << endl;
	d.removeFirst();
	d.removeLast(); 

	return 0;	
}
*/
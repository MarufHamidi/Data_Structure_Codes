#include<iostream>
using namespace std;

template <typename Object>

class deq
{
	int sz;
	struct node
	{
		Object element;
		node * prev;
		node * next;
		node(Object e=0,node * p=NULL,node * n=NULL)
		{
			element=e;
			prev=p;
			next=n;
		}
	};
	typedef node * nodePtr;
	nodePtr header,trailer;

public:
	deq()
	{
		sz=0;
		header=new node;
		trailer=new node;
		header->next=trailer;
		trailer->prev=header;
	}
	void insertFirst(Object o)
	{
		nodePtr v=new node(o,header,header->next);
		v->prev->next=v;
		v->next->prev=v;
	}
	void insertLast(Object o)
	{
		nodePtr v=new node(o,trailer->prev,trailer);
		v->prev->next=v;
		v->next->prev=v;
	}
	void removeFirst()
	{
		nodePtr v=header->next;
		v->prev->next=v->next;
		v->next->prev=v->prev;
		delete v;	
	}
	void removeLast()
	{
		nodePtr v=trailer->prev;
		v->prev->next=v->next;
		v->next->prev=v->prev;
		delete v;
	}
	Object first()
	{
		return (header->next->element);
	}
	Object last()
	{
		return (trailer->prev->element);
	}
	int size()
	{
		return sz;
	}
	bool isEmpty()
	{
		return (sz==0);
	}
};


int main()
{
	deq<int>d;

	d.insertFirst(3);
	d.insertFirst(5);
	cout<<d.first()<<endl;
	d.removeFirst();
	d.insertLast(7);
	cout<<d.last()<<endl;
	d.removeFirst();
	d.removeLast();  

	return 0;
}
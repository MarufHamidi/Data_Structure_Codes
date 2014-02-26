#include<iostream>
using namespace std;

template<typename Object>

class vector
{
	enum {SIZE=100};
	int rank,n;
	Object *v;
public:
	vector()
	{
		n=0;
		v=new Object[SIZE];
	}

	Object elemAtRank(int r)
	{
		if (r>=0 && r<size()) return v[r];
	}

	void replaceAtRank(int r,Object o)
	{
		if (r>=0 && r<size()) 
		{
			v[r]=o;
		}
	}

	void insertAtRank(int r,Object o)
	{
		if (r>=0 && r<=size()) 
		{
			int i;
			
			for(i=n-1;i>=r;i--)
				v[i+1]=v[i];
			
			v[r]=o;
			
			n++;
		}
	}

	void removeAtRank(int r)
	{
		if (r>=0 && r<size()) 
		{
			int i;
			
			for(i=r+1;i<n;i++)
				v[i-1]=v[i];
			
			n--;
		}	
	}

	int size()
	{
		return n;
	}

	bool isEmpty()
	{
		return (n==0);
	}
};

template<typename Object>

class list
{
protected:
	struct Node
	{
		Object element;
		Node* prev;
		Node* next;
		Node(Object e=0,Node* p=NULL,Node* n=NULL)
		{
			element = e;
			prev = p;
			next = n;
		}
	};
	typedef Node* NodePtr;
	
	int sz;
	NodePtr header;
	NodePtr trailer;

public:
	class position
	{
	public:
		NodePtr node;
		
		position(NodePtr n = NULL)
		{
			node=n;
		}

		Object element()
		{
			return node->element;
		}
	};

	NodePtr toPointer(position p)
	{
		return p.node;
	}

	list()
	{
		sz = 0;
		header = new Node;
		trailer = new Node;
		header->next = trailer;
		trailer->prev = header;
	}

	int size()
	{
		return sz;
	}

	bool isEmpty()
	{
		return (sz==0);
	}

	bool isFirst(position p)
	{
		NodePtr v = toPointer(p);
		return (v->prev == header);
	}

	bool isLast(position p)
	{
		NodePtr v = toPointer(p);
		return (v->next == trailer);
	}

	position first()
	{
		return position(header->next);
	}

	position last()
	{
		return position(trailer->prev);
	}

	position before(position p)
	{
		NodePtr v = toPointer(p);
		NodePtr prev = v->prev;
		return position(prev);
	}

	position after(position p)
	{
		NodePtr v = toPointer(p);
		NodePtr next = v->next;
		return position(next);
	}

	void replaceElement(position p,Object e)
	{
		NodePtr v = toPointer(p);
		v->element = e;
	}

	void swapElement(position p, position q)
	{
		Object temp = (toPointer(p))->element;
		(toPointer(p))->element = (toPointer(q))->element;
		(toPointer(q))->element = temp;
	}

	void remove(position p)
	{
		sz--;
		NodePtr v = toPointer(p);
		v->prev->next = v->next;
		v->next->prev = v->prev;
		delete v;
	}

	position insertFirst(Object e)
	{
		NodePtr v = new Node(e,header,header->next);
		sz++;
		v->prev->next = v;
		v->next->prev = v;
		return position(v);
	}

	position insertLast(Object e)
	{
		NodePtr v = new Node(e,trailer->prev,trailer);
		sz++;
		v->next->prev = v;
		v->prev->next = v;
		return position(v);
	}

	position insertBefore(position p,Object e)
	{
		NodePtr v = toPointer(p);
		NodePtr newNode = new Node(e,v->prev,v);
		newNode->prev->next = newNode;
		newNode->next->prev = newNode;
		sz++;
		return position(newNode);
	}

	position insertAfter(position p,Object e)
	{
		NodePtr v = toPointer(p);
		NodePtr newNode = new Node(e,v,v->next);
		newNode->prev->next = newNode;
		newNode->next->prev = newNode;
		sz++;
		return position(newNode);
	}
};

template<typename Object>

class sequence : public list<Object>,public vector<Object>
{
public:
	position atRank(int rank)
	{
		NodePtr v;
		if (rank<=size()/2)
		{
			v = header->next;
			for(int i=0;i<rank;i++)
				v = v->next;
		}
		else
		{
			v = trailer->prev;
			for(int i=1;i<size()-rank;i++)
				v = v->prev;
		}
		return position(v);
	}

	int rankOf(position p)
	{
		NodePtr v = toPointer(first());
		int i=0;
		while(v!=trailer)
		{
			if (v==p.node) return i;
			v = v->next;
			i++;
		}
		return -1;
	}

	int size()
	{
		return sz;
	}
};

int main()
{
	sequence<int>s;

	s.insertFirst(33);
	s.insertFirst(22);
	s.insertFirst(11);
	s.insertLast(99);
	
	cout << s.rankOf(s.last()) << endl;

	cout << s.size() << endl;

	return 0;
}
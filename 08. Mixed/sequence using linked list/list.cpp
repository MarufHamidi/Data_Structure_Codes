/*******************
**** list class ****
*******************/

template <typename Object>

class list
{
protected:
	struct Node
	{
		Object element;
		Node* prev;
		Node* next;
		
		Node(Object e=Object(),Node* p=NULL,Node* n=NULL)
		{
			element = e;
			prev = p;
			next = n;
		}
	};
	
	typedef Node * NodePtr;
	int sz;
	NodePtr header;
	NodePtr trailer;

public:
	class position
	{
	private:
		NodePtr node;

	public:	
		position(NodePtr n=NULL)
		{
			node=n;
		}

		Object element()
		{
			return (node->element);
		}
	
		bool isNull()
		{
			return (node==NULL);
		}
		
		friend class list<Object>;
	};

protected:
	NodePtr toPointer(position p)
	{
		return p.node;
	}

public:
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

	void replaceElement(position p, Object e)
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

	position insertFisrt(Object e)
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

	position insertBefore(position p, Object e)
	{
		NodePtr v = toPointer(p);
		sz++;
		NodePtr newNode = new Node(e,v->prev,v);
		newNode->prev->next = newNode;
		newNode->next->prev = newNode;
		return position(newNode);
	}

	position insertAfter(position p, Object e)
	{
		NodePtr v = toPointer(p);
		sz++;
		NodePtr newNode = new Node(e,v,v->next);
		newNode->prev->next = newNode;
		newNode->next->prev = newNode;
		return position(newNode);
	}
};

typedef list<int>::position pos_int;
typedef list<long>::position pos_long;
typedef list<double>::position pos_double;
typedef list<char>::position pos_char;
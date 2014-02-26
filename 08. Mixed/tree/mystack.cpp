
template <typename Object>
class mystack
{
public:
	struct ll
	{
		Object element;
		struct ll *next;
	};
	typedef struct ll node;
	typedef node* nodeptr;
	
	nodeptr tp;
	int sz;

	mystack()
	{
		tp=NULL;
		sz=0;
	}
	
	void push(Object o)
	{
		nodeptr v = new node;
		v->element = o;
		v->next = tp;
		tp=v;
		sz++;
	}

	Object pop()
	{
		if (!isEmpty()) 
		{
			nodeptr old=tp;
			tp=tp->next;
			sz--;
			Object result = old->element;
			delete old;
			return result;		
		}
	}

	Object top()
	{
		if (!isEmpty()) return tp->element;
	}

	bool isEmpty()
	{
		return (sz==0);
	}

	int size()
	{
		return sz;
	}
};

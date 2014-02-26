/****************************************
**** sequece class using linked list ****
****************************************/

#include"list.cpp"

template<typename Object>

class sequence:public list<Object>
{
public:
	position atRank(int r)
	{
		NodePtr v;
		if (r<=size()/2)
		{
			v = header->next;
			for(int i=0;i<r;i++)
				v = v->next;
		}
		else
		{
			v = trailer->prev;
			for(int i=1;i<size()-r;i++)
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
			if (v==toPointer(p)) return i;
			v = v->next;
			i++;
		}
		return -1;
	}

	Object elemAtRank(int r)
	{
		return (atRank(r).element());
	}

	void insertAtRank(int r, Object e)
	{
		if (r==size()) insertLast(e);
		else insertBefore(atRank(r),e);
	}

	void removeAtRank(int r)
	{
		remove(atRank(r));
	}

	void replaceAtRank(int r, Object e)
	{
		replaceElement(atRank(r),e);
	}
};
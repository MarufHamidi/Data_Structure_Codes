#include<iostream>
#include"list.cpp"
using namespace std;

template<typename Key,typename Element>
class Item
{	
private:
	Key _key;
	Element _elem;
public:
	Item(Key k=Key(),Element e=Element())
	{
		_key = k;
		_elem = e;
	}
	Key& key()
	{
		return _key;
	}
	Element& element()
	{
		return _elem;
	}
	void setKey(Key& k)
	{
		_key = k;
	}
	void setElement(Element& e)
	{
		_elem = e;
	}
};

template <typename Key, typename Element>
class priorityQueue
{
public:
	typedef Item<Key,Element> item;
	typedef list<item> List;
	typedef List::position Position;
	
	List l;
	
	int compare(Key k1,Key k2)
	{
		if (k1>k2) return 1;
		else if (k1<k2) return -1;
		else return 0;
	}

	Key& key(Position& p)
	{
		return p.element().key();
	}

	Element& element(Position& p)
	{
		return p.element().element();
	}

	int Size()
	{
		return l.size();
	}

	bool IsEmpty()
	{
		return (l.isEmpty());
	}

	void insertItem(Key k, Element e)
	{
		if (IsEmpty())
			l.insertFirst(item(k,e));
		else if (compare(k,key(l.last()))>0)
			l.insertAfter(l.last(),item(k,e));
		else
		{
			Position p = l.first();

			while(compare(k,key(p))>0)
			{
				p = l.after(p);	
			}

			l.insertBefore(p,item(k,e));
		}
	}

	Element minElement()
	{
		if (!IsEmpty()) return element(l.first());
	}

	Key& minKey()
	{
		if (!IsEmpty()) return key(l.first());
	}

	void removeMin()
	{
		if (!IsEmpty()) l.remove(l.first());
	}

};

int main()
{
	priorityQueue<int,char> pq;

	pq.insertItem(5,'A'); 
	
	pq.insertItem(9,'C'); 
	
	pq.insertItem(3,'B'); 
	
	pq.insertItem(7,'D');
	
	cout << pq.minElement() << endl;
	
	cout << pq.minKey() << endl;
	
	pq.removeMin();
	
	cout << pq.Size() << endl;

	cout << pq.minElement() << endl;
	
	pq.removeMin();
	
	pq.removeMin();
	
	pq.removeMin();
	
	printf("%s\n",pq.IsEmpty()?"true":"false" );

	return 0;
}
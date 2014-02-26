#include<iostream>
using namespace std;

template<typename Object>

class queue
{
	enum {SIZE=5};
	int f,r;
	Object *q;
public:
	queue()
	{
		f=r=0;
		q = new Object[SIZE];
	}

	void enqueue(Object n)
	{
		if (size()<SIZE-1) 
		{
			q[r]=n;
			r=(r+1)%SIZE;
		}
	}
		
	Object deque()
	{
		if (!isEmpty())
		{
			Object DQ=q[f];
			f=(f+1)%SIZE;
			return DQ;
		}
		return 0;
	}
	
	Object front()
	{
		if (!isEmpty()) return q[f];
		return 0;
	}
		
	int size()
	{
		return (SIZE-f+r)%SIZE;
	}
	
	bool isEmpty()
	{
		return (f==r);
	}	
};

int main()
{
	queue<int>Q;

	Q.enqueue(11); 
	Q.enqueue(12);
	
	cout<<Q.deque()<<" "; 

	Q.enqueue(13);
	Q.enqueue(14);
	Q.enqueue(15);

	cout << "Size : " << Q.size() << " ";
	cout << "isEmpty : " << Q.isEmpty() << endl;

	cout<<Q.deque()<<" ";
	cout<<Q.deque()<<" ";
	cout<<Q.deque()<<" ";
	cout<<Q.deque()<<" ";
	cout<<Q.deque()<<" ";
	cout << endl;

	cout << "Size : " << Q.size() << " ";
	cout << "isEmpty : " << Q.isEmpty() << endl;

	return 0;
}
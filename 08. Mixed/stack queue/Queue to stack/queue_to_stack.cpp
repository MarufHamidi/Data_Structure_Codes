#include<iostream>
using namespace std;


class queue
{
	int f,r,SIZE;
	int *q;
public:
	queue(int len=10)
	{
		SIZE=len;
		f=r=0;
		q = new int[SIZE];
	}

	void enqueue(int o)
	{
		if (size()<SIZE-1) 
		{
			q[r]=o;
			r=(r+1)%SIZE;
		}
	}
		
	int dequeue()
	{
		if (!isEmpty())
		{
			int DQ=q[f];
			f=(f+1)%SIZE;
			return DQ;
		}
		return 0;
	}
	
	int front()
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

queue Q;

void push(int n)
{
	Q.enqueue(n);
}

int pop()
{
	int i,temp;

	for(i=1;i<Q.size();i++)
	{
		temp=Q.dequeue();
		Q.enqueue(temp);
	}

	return Q.front();
}

void show()
{
	int i,j,temp;

	for(i=1;i<=Q.size();i++)
	{
		for(j=1;j<Q.size();j++)
		{
			temp=Q.dequeue();
			Q.enqueue(temp);
		}
		cout << Q.front() << " ";
	}
}

int main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);

	cout << "Output : ";

	int s = Q.size();
	
	cout << pop() << " ";
	cout << pop() << " ";
	cout << pop() << " ";
	cout << pop() << " ";
	cout << pop() << endl;

	cout<<endl<<"Stack show : ";
	show();
	cout<<endl;
	
	return 0;
}
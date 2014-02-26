#include<iostream>
using namespace std;
#define N 100
#include "Queue.cpp"

class Stack
{
private:
	Queue q;
public:
	Stack()
	{

	}
	int size()
	{
		return q.size();
	}
	int isEmpty()
	{
		return q.isEmpty();
	}
	void push(int x)
	{
		q.enqueue(x);
	}
	int pop()
	{
		int size=q.size();
		for(int i=0;i<size-1;i++)
		{
			q.enqueue(q.dequeue());
		}
		return q.dequeue();
	}
	int top()
	{
		int size=q.size();
		for(int i=0;i<size-1;i++)
		{
			q.enqueue(q.dequeue());
		}
		int returned=q.first();
		q.enqueue(q.dequeue());
		return returned;
	}
	void show()
	{
		int size=q.size();
		
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size-1;j++)
			{
				q.enqueue(q.dequeue());
			}
			cout << q.first() << "\t";
		}

		cout << endl;
	}
};



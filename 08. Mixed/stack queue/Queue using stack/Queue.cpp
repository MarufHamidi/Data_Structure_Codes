#include<iostream>
using namespace std;
#include "Stack.cpp"

class Queue
{
private:
	Stack s;
	Stack temp;
public:
	Queue()
	{

	}
	int size()
	{
		return s.size();
	}
	int isEmpty()
	{
		return s.isEmpty();
	}
	void enqueue(int x)
	{
        s.push(x);
	}
	int dequeue()
	{
	    int size=s.size();
	    
		for(int i=0;i<size-1;i++)
	    {
	        temp.push(s.pop());
	    }
	    
		int returned=s.pop();
	    
		while(!temp.isEmpty())
	    {
	        s.push(temp.pop());
	    }
	    
		return returned;
	}
	int first()
	{
		int size=s.size();
	    
		for(int i=0;i<size-1;i++)
	    {
	        temp.push(s.pop());
	    }
	    
		int returned=s.top();
	    
		while(!temp.isEmpty())
	    {
	        s.push(temp.pop());
	    }
	    
		return returned;
	}
	void show()
	{
		int size=s.size();
		
		while(!s.isEmpty())
		{
			temp.push(s.pop());
		}
		
		while(!temp.isEmpty())
		{
			int x=temp.pop();
			cout << x<< "\t";
			s.push(x);
		}
		
		cout << endl;	
	}
};


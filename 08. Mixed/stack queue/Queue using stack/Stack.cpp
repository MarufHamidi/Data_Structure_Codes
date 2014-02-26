#include<iostream>
using namespace std;

#define N 100

class Stack
{
private:
	int a[N],t;

public:
	Stack()
	{
	    t=-1;
	}
	int size()
	{
		return t+1;
	}
	int isEmpty()
	{
		return t<0;
	}
	void push(int x)
	{
	    a[++t]=x;
    }
	int pop()
	{
		return a[t--];
	}
	int top()
	{
		return a[t];
	}
};
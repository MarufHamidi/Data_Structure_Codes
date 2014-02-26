#include<iostream>
using namespace std;
#define N 100

class Queue
{
private:
	int a[N],f,r;
public:	
	Queue()
	{
		f=r=0;		
	}
	int size()
	{
		return (N-f+r)%N;
	}
	int isEmpty()
	{
		return f==r;
	}
	void enqueue(int x)
	{
		a[r]=x;
		r=(r+1)%N;
	}
	int dequeue()
	{
		int returned=a[f];
		f=(f+1)%N;
		return returned;			
	}
	int first()
	{
		return a[f];
	}	
};


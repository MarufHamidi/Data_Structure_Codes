#include<iostream>
using namespace std;
#include "Queue.cpp"

int main(void)
{
	Queue q;
	
	for(int i=1;i<=10;i+=2) 
		q.enqueue(i);
    
	cout << q.first() << endl;
	
	while(!q.isEmpty())
	{
	    q.show();
		cout << q.dequeue() << endl;
	}

	return 0;
}

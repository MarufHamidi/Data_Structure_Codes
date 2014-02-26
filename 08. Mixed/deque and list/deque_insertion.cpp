#include<iostream>
#include"deque.cpp"
using namespace std;

int main()
{
	deque<int> d1;
	deque<int> d2;
	int i,n=4,temp;

	for(i=1;i<=7;i++)
		d1.insertLast(i);

	for(i=1;i<=4;i++)
		d2.insertLast(i*10);

	int l=d1.size() - n;
	int m=d2.size();
	
	for(i=1;i<=l;i++)
	{
		temp=d1.last();
		d1.removeLast();
		d1.insertFirst(temp);
	}

	for(i=1;i<=m;i++)
	{
		temp=d2.first();
		d1.insertLast(temp);
		d2.removeFirst();
		d2.insertLast(temp);
	}

	for(i=1;i<=l;i++)
	{
		temp=d1.first();
		d1.removeFirst();
		d1.insertLast(temp);
	}

	for(i=1;i<=d1.size();i++)
	{
		temp=d1.first();
		cout << temp << " ";
		d1.removeFirst();
		d1.insertLast(temp);
	}
	
	cout << endl;	

	return 0;
}
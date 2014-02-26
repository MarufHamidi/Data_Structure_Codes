#include<iostream>
#include"deque.cpp"
using namespace std;

int main()
{
	deque<int>d;
	
	d.insertLast(4);
	d.insertLast(3);
	d.insertLast(1);
	d.insertLast(4);
	d.insertLast(2);
	d.insertLast(2);
	d.insertLast(1);

	int i,temp,j,comp,dupli=0,t,times=0;

	for(i=1;i<=d.size();i++)
	{
		temp=d.first();
		d.removeFirst();
		d.insertLast(temp);
		
		times=0;
		
		int l=d.size();
		for(j=1;j<=l-2;j++)
		{
			comp=d.first();
			d.removeFirst();
			if (comp!=temp) d.insertLast(comp);
		}

		for(j=1;j<=2;j++)
		{
			comp=d.first();
			d.removeFirst();
			d.insertLast(comp);
		}

		for(int k=1;k<=d.size();k++)
		{
			temp=d.first();
			cout << temp << " " ;
			d.removeFirst();
			d.insertLast(temp);
		}
		cout << endl;

	}

	for(i=1;i<=d.size();i++)
	{
		temp=d.first();
		cout << temp << " " ;
		d.removeFirst();
		d.insertLast(temp);
	}
	cout << endl;
	return 0;
}
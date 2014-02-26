#include<iostream>
using namespace std;

template<typename Object>

class vector
{
	enum {SIZE=100};
	int rank,n;
	Object *v;
public:
	vector()
	{
		n=0;
		v=new Object[SIZE];
	}

	Object elemAtRank(int r)
	{
		if (r>=0 && r<size()) return v[r];
	}

	void replaceAtRank(int r,Object o)
	{
		if (r>=0 && r<size()) 
		{
			v[r]=o;
		}
	}

	void insertAtRank(int r,Object o)
	{
		if (r>=0 && r<=size()) 
		{
			int i;
			
			for(i=n-1;i>=r;i--)
				v[i+1]=v[i];
			
			v[r]=o;
			
			n++;
		}
	}

	void removeAtRank(int r)
	{
		if (r>=0 && r<size()) 
		{
			int i;
			
			for(i=r+1;i<n;i++)
				v[i-1]=v[i];
			
			n--;
		}	
	}

	int size()
	{
		return n;
	}

	bool isEmpty()
	{
		return (n==0);
	}
};

int main()
{
	vector<int>V;

	cout << "SIZE : " << V.size() << " isEmpty : " << V.isEmpty() << endl;

	V.insertAtRank(0,60);
	V.insertAtRank(1,50);
	V.insertAtRank(2,20);
	V.insertAtRank(3,10);
	V.insertAtRank(4,30);
	V.insertAtRank(5,40);
	V.insertAtRank(6,70);
	
	cout<<endl;
	for(int i=0;i<V.size();i++)
		cout << V.elemAtRank(i) << " "; 
	cout<<endl;

	V.replaceAtRank(3,999); 
	
	cout<<endl;
	for(i=0;i<V.size();i++)
		cout << V.elemAtRank(i) << " "; 
	cout<<endl;

	V.removeAtRank(0);
	V.removeAtRank(1);
	V.removeAtRank(3);
	
	cout<<endl;
	for(i=0;i<V.size();i++)
		cout << V.elemAtRank(i) << " "; 
	cout<<endl;
	cout<<endl;

	cout << "SIZE : " << V.size() << " isEmpty : " << V.isEmpty() << endl;
	
	return 0;
}
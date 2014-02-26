#include<iostream>
using namespace std;

void insertionSort(int A[],int length)
{
	for(int j=1;j<length;j++)
	{
		int key = A[j];

		int i=j-1;

		while( (i>=0) && (A[i]>key) )
		{
			A[i+1] = A[i];
			i--;
		}
		
		A[i+1]=key;
	}
}

int main()
{
	int a[] = {5,2,4,7,1,3,2,6,8,4};
	int i;

	cout<<"Before sorting : \n";
	
	for(i=0;i<10;i++)
	{
		cout << a[i] << " ";
	}
	
	insertionSort(a,10);

	cout<<"\n\nSorted array : \n";

	for(i=0;i<10;i++)
	{
		cout << a[i] << " ";
	}

	cout << endl<<endl;

	return 0;
}
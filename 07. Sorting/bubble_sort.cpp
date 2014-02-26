#include<iostream>
using namespace std;

void bubbleSort(int A[],int length)
{
	for(int i=0;i<length;i++)
	{
		for(int j=length-1;j>=i+1;j--)
		{
			if (A[j]<A[j-1])
			{
				swap(A[j],A[j-1]);
			}
		}
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
	
	bubbleSort(a,10);

	cout<<"\n\nSorted array : \n";

	for(i=0;i<10;i++)
	{
		cout << a[i] << " ";
	}

	cout << endl<<endl;

	return 0;
}
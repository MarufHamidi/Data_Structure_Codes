#include<iostream>
using namespace std;

void countingSort(int A[],int length,int B[],int k)
{
	int i,j,*C;

	C = new int[k+1];

	for(i=0;i<=k;i++)
	{
		C[i] = 0;
	}

	for(j=0;j<length;j++)
	{
		C[A[j]]++;
	}

	for(i=1;i<=k;i++)
	{
		C[i] += C[i-1]; 
	}

	for(j=length-1;j>=0;j--)
	{
		B[C[A[j]]-1] = A[j];
		C[A[j]]--;
	}

}

int main()
{
	int a[] = {5,2,4,7,1,3,2,6,8,4};
	int i,max=-1,*b;

	b = new int[10];

	cout<<"Before sorting : \n";
	
	for(i=0;i<10;i++)
	{
		if (a[i]>max) max=a[i];
		cout << a[i] << " ";
	}
	
	countingSort(a,10,b,max);

	cout<<"\n\nSorted array : \n";

	for(i=0;i<10;i++)
	{
		cout << b[i] << " ";
	}

	cout << endl<<endl;

	return 0;
}
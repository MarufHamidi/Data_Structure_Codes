#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

void quickSort(int A[],int a,int b)
{
	if (a>=b) return;
	
	int p=A[b];
	int l=a;
	int r=b-1;

	while(l<=r)
	{
		while( (A[l]<=p) && (l<=r) )
		{
			l++;
		}
		while( (A[r]>=p) && (r>=l) )
		{
			r--;
		}
		
		if (l<r) swap(A[l],A[r]);				
	}
		
	swap(A[l],A[b]);

	quickSort(A,a,l-1);
	quickSort(A,l+1,b);	
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
	
	quickSort(a,0,9);

	cout<<"\n\nSorted array : \n";

	for(i=0;i<10;i++)
	{
		cout << a[i] << " ";
	}

	cout << endl<<endl;

	return 0;









	return 0;
}
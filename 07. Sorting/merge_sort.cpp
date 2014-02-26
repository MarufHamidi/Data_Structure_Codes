#include<iostream>
#include<cmath>
using namespace std;

#define MaxInt 1000

void merge(int A[],int p,int q,int r)
{
	int n1 = q-p+1;
	int n2 = r-q;

	int *L,*R,i,j,k;

	L = new int[n1+1];
	R = new int[n2+2];

	for(i=0;i<n1;i++)
	{
		L[i]=A[p+i];
	}
	
	for(j=0;j<n2;j++)
	{
		R[j]=A[q+j+1];
	}

	L[n1] = MaxInt;
	R[n2] = MaxInt;

	i=0;
	j=0;

	for(k=p;k<=r;k++)
	{
		if (L[i]<=R[j])
		{
			A[k]=L[i];
			i++;
		}
		else
		{
			A[k]=R[j];
			j++;
		}
	}

}

void mergeSort(int A[],int p,int r)
{
	if (p<r)
	{
		int q=(floor)((p+r)/2);
		mergeSort(A,p,q);
		mergeSort(A,q+1,r);
		merge(A,p,q,r);	
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
	
	mergeSort(a,0,9);

	cout<<"\n\nSorted array : \n";

	for(i=0;i<10;i++)
	{
		cout << a[i] << " ";
	}

	cout << endl<<endl;

	return 0;
}
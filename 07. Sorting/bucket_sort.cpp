#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector< vector<int> > buckets;

void bubbleSort(vector<int>& v)
{
	int length = v.size();
	int i;

	for(i=0;i<length;i++)
	{
		for(int j=length-1;j>=i+1;j--)
		{
			if ( v[j] < v[j-1] )
			{
				int temp = v[j];
				v[j] = v[j-1];
				v[j-1] = temp;
			}
		}
	}
}

int key(int data)
{
	return (data/2);
}

void bucketSort(int A[],int length)
{
	int i;
	
	buckets.resize(length);
	
	for(i=0;i<length;i++)
	{
		buckets[key(A[i])].push_back(A[i]);	
	}

	for(i=0;i<length;i++)
	{
		bubbleSort(buckets[i]);
	}

	int counter=0;

	for(i=0;i<length;i++)
	{
		for(int j=0;j<buckets[i].size();j++)
		{
			A[counter++] = 	buckets[i][j];
		}

		buckets[i].clear();
	}

	buckets.clear();
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
	
	bucketSort(a,10);

	cout<<"\n\nSorted array : \n";

	for(i=0;i<10;i++)
	{
		cout << a[i] << " ";
	}

	cout << endl<<endl;

	return 0;
}
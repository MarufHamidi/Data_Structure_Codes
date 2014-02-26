#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector< vector<int> > buckets;

void radixSort(int A[],int length)
{
    int temp;
    int counter=0,i,j,k,l,maxDigits,max=-1;

	//what's tha maximum
	for(i=0;i<length;i++)
	{
		if (A[i]>max) 
			max=A[i];
	}

	//how many digits have the maximum
	for(i=0;i<10;i++)
	{
		if ((int)( max / pow(10,i) )==0)
		{
			maxDigits=i;
			break;
		}
	}

    //i select the digit upon which sorts
    for(i=0;i<maxDigits;i++)
	{
        //all numbers should go any of the buckets
        for(j=0;j<length;j++)
		{
            temp=(int)( (A[j])/pow(10,i) )%10;
            buckets[temp].push_back((A[j]));
        }

        //sort the buckets individually
        for(k=0;k<10;k++)
		{
            for(l=0;l<buckets[k].size();l++)
			{
				A[counter++]=buckets[k][l];
            }
        	
			buckets[k].clear();
		}
    
		counter=0;    
	}
    
	//clear the buckets
	buckets.clear();
}

int main()
{
    int a[] = {125,552,354,217,556,364,665,786,110,412};
	int i;
	
	//initialize buckets size 10 with 10 empty vectors for using
	buckets.resize(10);
    
	cout<<"Before sorting : \n";
	
	for(i=0;i<10;i++)
	{
		cout << a[i] << " ";
	}
	
	radixSort(a,10);

	cout<<"\n\nSorted array : \n";

	for(i=0;i<10;i++)
	{
		cout << a[i] << " ";
	}

	cout << endl<<endl;

	return 0;
}

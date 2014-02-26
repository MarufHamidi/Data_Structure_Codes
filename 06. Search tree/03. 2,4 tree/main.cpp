#include<iostream>
#include"twoFourTree.cpp"
using namespace std;

int main()
{
	twoFourTree<int> T;
		
	T.insert(4);
	T.insert(4);
	
	T.insert(6);	
	T.insert(12);	
	T.insert(15);
	T.insert(3);	
	T.insert(5);	
	T.insert(8);	
	T.insert(13);	
	T.insert(14);	
	T.insert(10);	
	T.insert(11);	
	T.insert(17);	

	T.remove(13);
	T.remove(3);	
	T.remove(4);
	T.remove(12);
	T.remove(14);
	
	cout<<"Tree traverse : ";
	T.traverse(T.Root());
	cout<<endl;

	return 0;
}
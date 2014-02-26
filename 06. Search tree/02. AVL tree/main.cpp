#include<iostream>
#include"BST.cpp"
using namespace std;

int main()
{
	BST<int> bst;

	bst.insertion(10);
	bst.insertion(5);
	bst.insertion(15);
	bst.insertion(20);
	bst.insertion(5);
	bst.insertion(25);
	
	bst.inorder(bst.toPointer(bst.root()));
	cout << endl;
	
	bst.deletion(10);
	bst.inorder(bst.toPointer(bst.root()));
	cout << endl;

	return 0;
}
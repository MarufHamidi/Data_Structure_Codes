// RedBlackTree - 0805051 

#include<iostream>
#include"BST.cpp"
using namespace std;

#define red 0
#define black 1

template<typename object>
class RedBlackTree
{
private:
	BST<object> T;
	typedef Node<object>* nodePtr;
	typedef BST<object>::position Position;

public:	
	void leftRotate(nodePtr x) //leftRotate
	{
		nodePtr y = x->right;
		x->right = y->left;
		y->left->parent = x;
		y->parent = x->parent;

		if (x->parent==0)
			T.setRoot(y);
		else if (x==x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		
		y->left = x;
		x->parent = y;
	}

	void rightRotate(nodePtr y) //rightRotate
	{
		nodePtr x = y->left;
		y->left = x->right;
		x->right->parent = y;
		x->parent = y->parent;

		if (y->parent==0)
			T.setRoot(x);
		else if (y==y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;
		
		x->right = y;
		y->parent = x;
	}
	
	void insertFixup(nodePtr z) //fixup problems occuring while insertion
	{
		nodePtr y;

		while((z->parent!=0) && (z->parent->color==red))
		{
			if (z->parent==z->parent->parent->left)
			{
				y = z->parent->parent->right;

				if (y->color==red) //case1
				{
					z->parent->color = black;
					y->color = black;
					z->parent->parent->color = red;
					z = z->parent->parent;
				}
				else 
				{
					if (z==z->parent->right) //case2
					{
						z = z->parent;
						leftRotate(z);
					}
					z->parent->color = black; //case3
					z->parent->parent->color = red;
					rightRotate(z->parent->parent);
				}
			}
			else if (z->parent==z->parent->parent->right)
			{
				y = z->parent->parent->left;

				if (y->color==red) //case1
				{
					z->parent->color = black;
					y->color = black;
					z->parent->parent->color = red;
					z = z->parent->parent;
				}
				else
				{
					if (z==z->parent->left) //case2
					{
						z = z->parent;
						rightRotate(z);
					}
					z->parent->color = black; //case3
					z->parent->parent->color = red;
					leftRotate(z->parent->parent);
				}
			}

		}

		T.toPointer(T.root())->color = black;
	}

	void Insert(object e) //insert an element
	{
		nodePtr z = T.insertion(e); //insert like a bst
		insertFixup(z); //fixup insertion errors
	}

	void deleteFixup(nodePtr x) //fixup problems occuring while deletion
	{
		while( (x!=T.toPointer(T.root())) && (x->color==black) && (T.isInternal(x->sibling())) )
		{
			nodePtr w;

			if (x==x->parent->left)
			{
				w = x->parent->right;

				if (w->color==red) //case1
				{
					w->color = black;
					x->parent->color = red;
					leftRotate(x->parent);
					w = x->parent->right;
				}
				else if ( (w->left->color==black) && (w->right->color==black) ) //case2
				{
					w->color = red;
					x = x->parent;
				}
				else
				{
					if (w->right->color==black) //case3
					{
						w->left->color = black;
						w->color = red;
						rightRotate(w);
						w = x->parent->right;
					}
					w->color = x->parent->color; //case4
					x->parent->color = black;
					w->right->color = black;
					leftRotate(x->parent);
					x = T.toPointer(T.root());
				}
			}
			else if (x==x->parent->right) 
			{
				w = x->parent->left;

				if (w->color==red) //case1
				{
					w->color = black;
					x->parent->color = red;
					rightRotate(x->parent);
					w = x->parent->left;
				}
				else if ( (w->left->color==black) && (w->right->color==black) ) //case2
				{
					w->color = red;
					x = x->parent;
				}
				else
				{
					if (w->left->color==black) //case3
					{
						w->right->color = black;
						w->color = red;
						leftRotate(w);
						w = x->parent->left;
					}
					w->color = x->parent->color; //case4
					x->parent->color = black;
					w->left->color = black;
					rightRotate(x->parent);
					x = T.toPointer(T.root());
				}
			}
		}

		x->color = black;
	}

	void Delete(object e) //delete an element
	{
		nodePtr x = T.deletion(e); //delete like a bst
		deleteFixup(x); //fixup deletion errors
	}

	void show() //show tree's element inorderly
	{
		T.inorder(T.toPointer(T.root()));
	}

	void levelWisePrint()
	{
		T.printByLevel();
	}
};

int main()
{
	//freopen("input.txt","r",stdin);

	RedBlackTree<int> RBT;
	int input,number;

	cout << "Type negative number to terminate input\n";

	while(cin >> input)
	{
		if (input<0)
			break;
		else
			RBT.Insert(input);
	}

	cout<<"_______________________________\n\n";
	cout << "Inorderly show = 1 , Level wise show = 2 , Insert = 3 , Delete = 4\n";

	while(cin >> input)
	{
		if (input==1)
		{
			cout << endl;
			RBT.show();
		}
		else if (input==2)
		{
			cout << endl;
			RBT.levelWisePrint();
		}
		else if (input==3)
		{
			cout << "Enter number you want to insert : ";
			cin >> number;
			cout << endl;
		
			RBT.Insert(number);
		}
		else if (input==4)
		{
			cout << "Enter number you want to delete : ";
			cin >> number;
			cout << endl;
		
			RBT.Delete(number);
		}

		cout<<"_______________________________\n\n";
		cout << "Inorderly show = 1 , Level wise show = 2 , Insert = 3 , Delete = 4\n";
	}
	
	return 0;
}

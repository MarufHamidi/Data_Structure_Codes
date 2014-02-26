#include<iostream>
#include"BST.cpp"
using namespace std;

#define max(a,b) a>=b?a:b

template<typename object>
class AVL
{
public:
	BST<object> B;
	typedef Node<object>* nodePtr;
	typedef BST<object>::position Position;
	
	int height(nodePtr ptr)
	{
		if (B.isExternal(Position(ptr)))
			return 0;
		else
		{
			int h=0;
			
			h = max(height(ptr->left),height(ptr->right));

			return (1+h);
		}
	}

	void insertInAVL(object e)
	{
		B.insertion(e);
		
		Position posW = B.treeSearch(e,B.root());
		
		nodePtr w = B.toPointer(posW);

		//let z be the 1st unbalanced nodePtr
		nodePtr z;
		
		if (!B.isRoot(w))
		{
			bool problem=0;

			while(!B.isRoot(w))
			{
				if ( ( height(w)-height(w->sibling())>1 ) || ( height(w->sibling())-height(w)>1 ) )
				{
					z=w->parent;
					problem=1;
					break;
				} 
				else
					w=w->parent;
			}
		
			if (problem)
			{
				//y is the max-height-child of z
				nodePtr y;

				if ( height(z->left) >= height(z->right) )
					y = z->left;
				else
					y = z->right;

				//x is the max-height-child of y
				nodePtr x;

				if ( height(y->left) >= height(y->right) )
					x = y->left;
				else
					x = y->right;

				//now a,b,c should be inorderly x,y,z
				nodePtr a,b,c;

				if ( (x->element > y->element) && (x->element > z->element) )
				{
					if ( y->element > z->element )
					{
						a=z;
						b=y;
						c=x;
					}
					else if ( z->element > y->element )
					{
						a=y;
						b=z;
						c=x;
					}
				}
				else if ( (y->element > x->element) && (y->element > z->element) )
				{
					if ( x->element > z->element )
					{
						a=z;
						b=x;
						c=y;
					}
					else if ( z->element > x->element )
					{
						a=x;
						b=z;
						c=y;
					}
				}
				else if ( (z->element > x->element) && (z->element > y->element) )
				{
					if ( x->element > y->element )
					{
						a=y;
						b=x;
						c=z;
					}
					else if ( y->element > x->element )
					{
						a=x;
						b=y;
						c=z;
					}
				}
				
				//now time to rotate
				nodePtr t0,t1,t2,t3;
				
				//t0
				t0 = a->left;
				
				//t1
				if ( ( a->right == b ) || ( a->right == c ) )
					t1 = b->left;
				else
					t1 = a->right;
				
				//t2
				if ( b->right == c )
					t2 = c->left;
				else
					t2 = b->right;
				
				//t3
				t3 = c->right;
				
				//t0,t1,t2,t3 has been found
				
				//set b
				if (!B.isRoot(z))
				{
					if ( z->parent->left == z )
						z->parent->left = b;
					else if ( z->parent->right == z )
						z->parent->right = b;
				
					b->parent = z->parent;	
				}
				else
					B.setRoot(b);
				
				b->left = a;
				a->parent = b;
				
				b->right = c;
				c->parent = b;

				//set a's child
				a->left = t0;
				if (t0!=0) t0->parent = a;
				
				a->right = t1;
				if (t1!=0) t1->parent = a;

				//set b's child
				c->left = t2;
				if (t2!=0) t2->parent = c;
				
				c->right = t3;
				if (t3!=0) t3->parent = c;
			}
		}
	}

};

int main()
{
	AVL<int> avlTree;

	avlTree.B.insertion(44);
	avlTree.B.insertion(17);
	avlTree.B.insertion(88);
	avlTree.B.insertion(97);
	avlTree.B.insertion(65);
	avlTree.B.insertion(82);
	avlTree.B.insertion(54);
	avlTree.B.insertion(32);
	
	avlTree.insertInAVL(72); 

	avlTree.B.inorder( avlTree.B.toPointer(avlTree.B.root()) );

	return 0;
}
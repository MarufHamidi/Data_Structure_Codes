// BinarySearchTree - 0805051 

#include<iostream>
#include"node.cpp"
#include<queue>
using namespace std;

template<typename object>
class BST
{	
private:
	typedef Node<object> node;
	typedef node* nodeptr;
	nodeptr theRoot;
	int sz;

public:
	class position
	{
	private:
		nodeptr ptr;
	public:
		position(nodeptr n=0)	
		{ 
			ptr=n;
		}
		object element()		
		{ 
			return (ptr->element);
		}
		bool isNull()    		
		{
			return (ptr==0);
		}	
		nodeptr pointer()			
		{ 
			return ptr; 
		}
	};

public:
	nodeptr toPointer(position P) //return the pointer saved in position P
	{
		return P.pointer();
	}
	
	BST() //constructor
	{
		theRoot = 0;
		sz=0;
	}
	
	int size() //return size
	{
		return sz;
	}
	
	bool isEmpty() //return whether size=0 or not
	{
		return (sz==0);
	}
	
	position root() //return root
	{
		return (position(theRoot));
	}
	
	bool isRoot(position P) //return true if P's  pointer is root
	{
		return (toPointer(P)==theRoot);
	}

	position leftChild(position P) //return leftChild of P
	{
		return position(toPointer(P) -> left);
	}
	
	position rightChild(position P) //return rightChild of P
	{
		return position(toPointer(P) -> right);
	}
	
	bool isExternal(position P) //return true if P is external node
	{
		return (toPointer(P)->left == 0) && (toPointer(P)->right == 0);	
	}
	
	bool isInternal(position P) //return true if P is internal node 
	{
		return (isExternal(P)==0);
	}
	
	void replaceElement(position P,object e) //replace P's element with e
	{
		toPointer(P)->element = e;
	}
	
	void swapElements(position P,position Q) //swap P's and Q's elements
	{
		object temp = toPointer(P)->element;
		toPointer(P)->element = toPointer(Q)->element;
		toPointer(Q)->element = temp;
	}
	
	void expandExternal(position P) //convert P from an external to an internal node
	{
		nodeptr n = toPointer(P);
		
		n->color = 0; //color red
		
		n->left = new node;
		n->left->color = 1; //leftChild black
		n->left->parent = n;
		
		n->right = new node;
		n->right->color = 1; //rightChild black
		n->right->parent = n;
	}
	
	void setRoot(nodeptr ptr) //set P as the new root
	{
		theRoot = ptr;
	}
	
	position removeAboveExternal(position P) //remove P with it's parent and P's sibling is new parent
	{
		nodeptr n = toPointer(P);
		nodeptr p = n->parent;
		nodeptr s = n->sibling();
		
		if (isRoot(p)) setRoot(s);
		else
		{
			nodeptr g = p->parent;

			if (p==g->left) g->left = s;
			else g->right = s;
			
			s->parent = g;
		}

		delete n;
		delete p;
		
		sz-=2;

		return position(s);
	}

	position treeSearch(object e,position P) //return a position after searching an element
	{
		if (isExternal(P))
			return P;

		if (P.element()==e)
			return P;
		else if (e<P.element())
			return treeSearch(e,leftChild(P));
		else 
			return treeSearch(e,rightChild(P));
	}

	nodeptr insertion(object e) //insert node containing e in the tree
	{
		if (isEmpty()) 
		{
			nodeptr n = new node(e,1); //black colored 
			expandExternal(position(n));
			setRoot(n);	
			sz++;
			return n;
		}
		else
		{
			position myNode = treeSearch(e,root());
			
			if (isInternal(myNode)) 
				cout << e << " is already inserted in tree." << endl;
			else
			{
				expandExternal(myNode);
				replaceElement(myNode,e);
				sz++;
			}

			return toPointer(myNode);
		}
	}

	nodeptr deletion(object e) //delete node containing e from the tree
	{
		position myNode = treeSearch(e,root());
		nodeptr retNode=0;

		if (isExternal(myNode)) 
		{
			cout << e << " not found in tree." << endl; 
		}
		else if ( isExternal(leftChild(myNode)) && isExternal(rightChild(myNode)) )
		{
			if (!isRoot(myNode)) 
			{
				nodeptr n = new node;
				n->parent = toPointer(myNode)->parent;
				n->color = 1; //color black

				retNode=n;

				if ( toPointer(myNode)->parent->left == toPointer(myNode) )
					toPointer(myNode)->parent->left = n;
				else 
					toPointer(myNode)->parent->right = n;
			}
			else
				setRoot(0);

			delete toPointer(myNode);
			sz--;
		}
		else if ( isExternal(leftChild(myNode)) || isExternal(rightChild(myNode)) )
		{
			if (isExternal(leftChild(myNode)))
			{
				retNode=toPointer(rightChild(myNode));
				removeAboveExternal(leftChild(myNode));
			}
			else
			{
				retNode=toPointer(leftChild(myNode));
				removeAboveExternal(rightChild(myNode));
			}

			sz--;
		}
		else
		{
			position P = rightChild(myNode);

			while(isInternal(leftChild(P)))
			{
				P = leftChild(P);
			}

			replaceElement(myNode,P.element());
			
			if (isExternal(leftChild(P)))
			{
				retNode = toPointer(rightChild(P));
				removeAboveExternal(leftChild(P));
			}
			else
			{
				retNode = toPointer(leftChild(P));
				removeAboveExternal(rightChild(P));
			}

			sz--;
		}

		return retNode;
	}

	int depth(nodeptr ptr) //return depth of ptr
	{
		if ( toPointer(root()) == ptr )
			return 0;
		else
			return ( 1 + depth(ptr->parent) );
	}
	
	void inorder(nodeptr ptr) //inorderly traverse the tree
	{
		if (ptr->left!=0) inorder(ptr->left);
		
		if (isInternal(position(ptr))) 
		{
			printf("%-4d",ptr->element);
			cout << "level: " << depth(ptr) << " color: ";

			if (ptr->color==0) 
				cout << "red" << endl;
			else if (ptr->color==1) 
				cout << "black" << endl;
		}

		if (ptr->right!=0) inorder(ptr->right);
	}

	void printByLevel() //prints element according to their levels
	{
		queue<nodeptr> Q;
		nodeptr ptr;

		Q.push(theRoot);

		while(!Q.empty())
		{
			ptr = Q.front();
			Q.pop();
			
			if ( isInternal(position(ptr->left)) )
				Q.push(ptr->left);

			if ( isInternal(position(ptr->right)) )
				Q.push(ptr->right);
						
			printf("%-4d",ptr->element);
			cout << "level: " << depth(ptr) << " color: ";

			if (ptr->color==0) 
				cout << "red" << endl;
			else if (ptr->color==1) 
				cout << "black" << endl;
		}
	}
};

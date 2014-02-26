#include<iostream>
using namespace std;

template<typename object>
class BST
{	
	protected:
	//*****************************
	struct node
	{
		object element;
		node *parent,*left,*right;
		node(object e=-1)
		{
			element=e;
			parent=left=right=0;			
		}
		node* sibling()
		{
			return (this==parent->left? parent->right:parent->left);
		}
	};
	typedef node* nodeptr;
	//*****************************
public:
	class position
	{
	protected:
		nodeptr ptr;
	public:
		position(nodeptr n=0)		{ ptr=n;}
		object element()			{ return (ptr->element);}
		bool isNull()    			{ return (ptr==0);}	
		nodeptr toptr(position v)	{ return v.ptr; }
	};
	//**************************
private:
	nodeptr theRoot;
	int sz;
public:
	nodeptr toPointer(position v)
	{
		return v.toptr(v);
	}
	
	BST()
	{
		theRoot = 0;
		sz=0;
	}
	
	int size()
	{
		return sz;
	}
	
	bool isEmpty()
	{
		return (sz==0);
	}
	
	position root()
	{
		return (position(theRoot));
	}
	
	position leftChild(position v)
	{
		return position(toPointer(v) -> left);
	}
	
	position rightChild(position v)
	{
		return position(toPointer(v) -> right);
	}
	
	bool isRoot(position v)
	{
		return (toPointer(v)==theRoot);
	}
	
	bool isExternal(position v)
	{
		return (toPointer(v) -> left == 0) && (toPointer(v) -> right == 0);	
	}
	
	bool isInternal(position v)
	{
		return (isExternal(v)==0);
	}
	
	void replaceElement(position v,object e)
	{
		toPointer(v)->element = e;
	}
	
	void swapElements(position v,position w)
	{
		object temp = toPointer(v)->element;
		toPointer(v)->element = toPointer(w)->element;
		toPointer(w)->element = temp;
	}
	
	void expandExternal(position v)
	{
		nodeptr n = toPointer(v);
		n->left = new node;
		n->left->parent = n;
		n->right = new node;
		n->right->parent = n;
	}
	
	void setRoot(nodeptr p)
	{
		theRoot = p;
	}
	
	void removeAboveExternal(position v)
	{
		nodeptr n = toPointer(v);
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
	}

	position treeSearch(object o,position v)
	{
		if (isExternal(v))
			return v;

		if (o==v.element())
			return v;
		else if (o<v.element())
			return treeSearch(o,leftChild(v));
		else 
			return treeSearch(o,rightChild(v));
	}

	void insertion(object o)
	{
		if (isEmpty()) 
		{
			nodeptr n = new node(o);
			expandExternal(position(n));
			setRoot(n);	
			sz++;
		}
		else
		{
			position myNode = treeSearch(o,root());
			
			if (isInternal(myNode)) 
				cout << o << " is already inserted in tree." << endl;
			else
			{
				expandExternal(myNode);
				replaceElement(myNode,o);
				sz++;
			}
		}
	}

	void deletion(object o)
	{
		position myNode = treeSearch(o,root());
	
		if (isExternal(myNode)) cout << o << " not found in tree." << endl; 
		else if ( isExternal(rightChild(myNode)) && isExternal(rightChild(myNode)) )
		{
			if (!isRoot(myNode)) 
			{
				nodeptr n = new node;
				n->parent = toPointer(myNode)->parent;
				if (toPointer(myNode)->parent->left==toPointer(myNode))
					toPointer(myNode)->parent->left = n;
				else 
					toPointer(myNode)->parent->right = n;
			}
			delete toPointer(myNode);
			sz--;
		}
		else if ( isExternal(rightChild(myNode)) || isExternal(rightChild(myNode)) )
		{
			if (isExternal(rightChild(myNode)))
				removeAboveExternal(rightChild(myNode));
			else
				removeAboveExternal(leftChild(myNode));
			
			sz--;
		}
		else
		{
			position p = rightChild(myNode);

			while(isInternal(leftChild(p)))
			{
				p = leftChild(p);
			}

			replaceElement(myNode,p.element());
			
			if (isExternal(rightChild(p)))
				removeAboveExternal(rightChild(p));
			else
				removeAboveExternal(leftChild(p));
			
			sz--;
		}
	}
	
	void inorder(nodeptr pt)
	{
		if (pt->left!=0) inorder(pt->left);
		if (pt->element!=-1) cout << pt->element << " ";
		if (pt->right!=0) inorder(pt->right);
	}
};

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
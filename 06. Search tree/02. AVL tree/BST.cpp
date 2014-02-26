#include<iostream>
#include"node.cpp"
using namespace std;

template<typename object>
class BST
{	
protected:
	typedef Node<object> node;
	typedef node* nodeptr;

public:
	class position
	{
	protected:
		nodeptr ptr;
	public:
		position(nodeptr n=0)	{ ptr=n;}
		object element()		{ return (ptr->element);}
		bool isNull()    		{ return (ptr==0);}	
		nodeptr toptr()			{ return ptr; }
	};

private:
	nodeptr theRoot;
	int sz;
public:
	nodeptr toPointer(position v)
	{
		return v.toptr();
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
	
	position shibling(position v)
	{
		return position(toPointer(v) -> sibling());
	}
	
	position parent(position v)
	{
		return position(toPointer(v) -> parent);
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
	
	position removeAboveExternal(position v)
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

		return position(s);
	}

	position treeSearch(object e,position v)
	{
		if (isExternal(v))
			return v;

		if (v.element()==e)
			return v;
		else if (e<v.element())
			return treeSearch(e,leftChild(v));
		else 
			return treeSearch(e,rightChild(v));
	}

	void insertion(object e)
	{
		if (isEmpty()) 
		{
			nodeptr n = new node(e);
			expandExternal(position(n));
			setRoot(n);	
			sz++;
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
		}
	}

	void deletion(object e)
	{
		position myNode = treeSearch(e,root());
	
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
				removeAboveExternal(leftChild(myNode));
			else
				removeAboveExternal(rightChild(myNode));
			
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
			
			if (isExternal(leftChild(p)))
				removeAboveExternal(leftChild(p));
			else
				removeAboveExternal(rightChild(p));
			
			sz--;
		}
	}
	
	void inorder(nodeptr pt)
	{
		if (pt->left!=0) inorder(pt->left);
		if (isInternal(position(pt))) cout << pt->element << " ";
		if (pt->right!=0) inorder(pt->right);
	}
};

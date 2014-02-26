#include<iostream>
using namespace std;

template<typename object>
class tree
{
protected:
	//*****************************
	struct node
	{
		object element;
		node * parent;
		node * left;
		node * right;
		node(object e=0)
		{
			element=e;
			parent=left=right=0;			
		}
		node * sibling()
		{
			return (this==parent->left? parent->right:parent->left);
		}
	};
	typedef node * nodeptr;
	//*****************************
public:
	class position
	{
	protected:
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
		nodeptr toptr(position v)
		{
			return v.ptr;
		}
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
	tree()
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
		return (toPointer(v) -> left == 0) && (toPointer(v) -> right == 0)	
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
		sz+=2;
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
	}

	void insert(int x)
	{
		if (size()==0) 
		{
			nodeptr n = new node(x);
			setRoot(n);	
			sz++;
		}
		else
		{
			nodeptr p=toPointer(root());
			nodeptr par;

			while(1)
			{
				if ( x > (p->element) ) 
				{
					if (p->right==0) {p->right=new node(x);break;}
					p = p->right;
				}
				else 
				{
					if (p->left==0) {p->left=new node(x);break;}
					p = p->left; 
				}
			}

			p=new node(x);
		}
	}

	void preorder(nodeptr pt)
	{
		cout << pt->element << " ";
		if (pt->left!=0) preorder(pt->left);
		if (pt->right!=0) preorder(pt->right);
	}
	
	void postorder(nodeptr pt)
	{
		if (pt->left!=0) postorder(pt->left);
		if (pt->right!=0) postorder(pt->right);
		cout << pt->element << " ";
	}
	
	void inorder(nodeptr pt)
	{
		if (pt->left!=0) inorder(pt->left);
		cout << pt->element << " ";
		if (pt->right!=0) inorder(pt->right);
	}

};

tree<int>t;

int main()
{
	int x;

	while(cin>>x)
	{
		if (x<0) break;
		t.insert(x);
	}

	t.preorder(t.toPointer(t.root()));
	cout<<endl;
	
	t.postorder(t.toPointer(t.root()));
	cout<<endl;

	t.inorder(t.toPointer(t.root()));
	cout<<endl;

	return 0;
}
#include<iostream>
#include"position.cpp"
#include"mystack.cpp"
using namespace std;

template<typename object>
class tree:protected node<object>,public position<object>
{
private:
	nodeptr theRoot;
	int sz;
public:
	nodeptr toPointer(position<object> v)
	{
		return toptr(v);
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
	position<object> root()
	{
		return (position<object>(theRoot));
	}
	position<object> parent(position<object> v)
	{
		return position<object>(toPointer(v) -> parent);
	}
	position<object> leftChild(position<object> v)
	{
		return position<object>(toPointer(v) -> left);
	}
	position<object> rightChild(position<object> v)
	{
		return position<object>(toPointer(v) -> right);
	}
	bool isRoot(position<object> v)
	{
		return (toPointer(v)==theRoot);
	}
	bool isExternal(position<object> v)
	{
		return (toPointer(v) -> left == 0) && (toPointer(v) -> right == 0);	
	}
	bool isInternal(position<object> v)
	{
		return (isExternal(v)==0);
	}
	void replaceElement(position<object> v,object e)
	{
		toPointer(v)->element = e;
	}
	void swapElements(position<object> v,position<object> w)
	{
		object temp = toPointer(v)->element;
		toPointer(v)->element = toPointer(w)->element;
		toPointer(w)->element = temp;
	}
	void expandExternal(position<object> v)
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
	position<object> removeAboveExternal(position<object> v)
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
		return position<object>(s);
	}

	void insert(int x)
	{
		if (size()==0) 
		{
			nodeptr n = new node<object>(x);
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
					if (p->right==0) {p->right=new node<object>(x);p->right->parent=p;break;}
					p = p->right;
				}
				else 
				{
					if (p->left==0) {p->left=new node<object>(x);p->left->parent=p;break;}
					p = p->left; 
				}
			}
			sz++;
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

typedef node<int>* nodint;
mystack<node<int>*>s;
typedef position<int> posint;
nodint pp;

int depth(tree<int> t, posint v)
{
	if (t.isRoot(v))
		return 0;
	else 
		return (1 + depth( t, posint(t.parent(v)) ) );
}

void traverse(tree<int> t, nodint p)
{
	if (p->left!=0) traverse(t,p->left);
	if (p->left==0 && p->right==0) {s.push(p);cout<<p->element<<" d:" << depth(t,posint(p)) << endl;}
	if (p->right!=0) traverse(t,p->right);
}

int height(tree<int>t)
{
	int h=0;

	while(s.isEmpty()==0)
	{
		int d= depth(t,position<int>(s.top()));
		if (d>h) h=d;
		s.pop();	
	}

	return h;
}

tree<int>t;

int main()
{
	freopen("in.txt","r",stdin);

	int x;

	while(cin>>x)
	{
		if (x<0) break;
		t.insert(x);
	}



	/*
	t.preorder(t.toPointer(t.root()));
	cout<<endl;
	
	t.postorder(t.toPointer(t.root()));
	cout<<endl;
	
	t.inorder(t.toPointer(t.root()));
	cout<<endl;
	*/
	traverse( t , t.toPointer(t.root()) );
	cout << "size : " << t.size()<< endl;
	cout << "height : " << height(t) << endl;	

	return 0;
}
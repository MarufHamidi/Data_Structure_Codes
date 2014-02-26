// node - 0805051

template<typename object>
struct Node
{
	object element;
	bool color;
	Node *parent,*left,*right;
	
	Node(object e=-1,bool c=0) //constructor
	{
		element=e;
		color=c;
		parent=left=right=0;			
	}

	Node* sibling() //returns sibling
	{
		return (this==parent->left? parent->right:parent->left);
	}
};
	
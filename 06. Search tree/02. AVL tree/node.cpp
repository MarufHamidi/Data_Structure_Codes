
template<typename object>
struct Node
{
	object element;
	Node *parent,*left,*right;
	Node(object e=-1)
	{
		element=e;
		parent=left=right=0;			
	}
	Node* sibling()
	{
		return (this==parent->left? parent->right:parent->left);
	}
};
	
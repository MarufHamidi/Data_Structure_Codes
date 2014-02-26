
template<typename object>
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

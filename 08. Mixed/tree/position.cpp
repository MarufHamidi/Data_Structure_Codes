#include"node.cpp"

template<typename object>
class position
{
public:
	typedef node<object>* nodeptr;
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

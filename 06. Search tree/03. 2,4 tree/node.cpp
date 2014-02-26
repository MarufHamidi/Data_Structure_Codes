#include<algorithm>

#define max_int 1000

template<typename object>
class node
{
public:
	int size;
	node *parent,*child[5];
	object element[4];
	
	//constructor
	node()
	{
		size=0;
		parent=0;
		
		for(int i=0;i<=4;i++)
		{
			if (i!=4) element[i]=max_int; 
			child[i]=0;			
		}	
	}	
	
	//returns 1 if a specific value exists
	bool hasElement(int value)
	{
		for(int i=0;i<size;i++)
			if (element[i]==value)	
				return 1;
		
		return 0;
	}
	
	//returns the nth child while searching
	node* searchPath(int value)
	{
		for(int i=0;i<=3;i++)
			if (value<=element[i]) 
				return child[i];	
		
		return child[4];	
	}
	
	//return true if all children are external
	bool isAllChildExternal()
	{
		return (child[0]==0 && child[1]==0 && child[2]==0 && child[3]==0 && child[4]==0);
	}
	
	//set ch as nth child
	void setChild(node* ch,int n)
	{
		child[n]=ch;
		if (ch!=0) ch->parent=this;
	}
	
	//inserts a value in a node
	void insertElement(int value)
	{
		element[size++]=value;
		sort(element+0,element+4);	
	}
	
	//remove a value from elements
	void removeElement(int value)
	{
		for(int i=0;i<size;i++)
			if (element[i]==value) 
				element[i]=max_int;
		
		sort(element+0,element+4);	
		size--;
	}

	//removes the first inserted element
	void removeFirstElement()
	{
		removeElement(element[0]);
	}
	
	//removes the last inserted element
	void removeLastElement()
	{
		removeElement(element[size-1]);
	}

	//returns the last inserted element
	object lastElement()
	{
		return element[size-1];
	}
};

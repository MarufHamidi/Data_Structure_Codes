#include<iostream>
#include"node.cpp"
using namespace std;

#define max_int 1000

template<typename object>
class twoFourTree
{
private:
	typedef node<object> Node;
	typedef Node* nodeptr;
	nodeptr root;
	bool found;

public:

	//constructor
	twoFourTree()
	{	
		root = new Node();
		found=0;
	}	
	
	//search & return the node containing a value
	nodeptr search(int value)
	{
		nodeptr p=root;
		found=0;

		while(true)
		{
			if (p->hasElement(value)) {found=1;break;}
			else if (p->searchPath(value)==0) break;  
			else p=p->searchPath(value); 	
		}

		return p;
	}

	//insert a value in tree
	void insert(object value)
	{
		cout << "inserting " << value << endl;

		nodeptr p = search(value);
		
		if (found==1) cout << "Tree already contains " << value << ".\n";
		else
		{
			p->insertElement(value);
			
			while(p->size==4)
			{
				nodeptr node1 = new Node();
				nodeptr node2 = new Node();
				
				//node1
				node1->insertElement(p->element[0]);
				node1->insertElement(p->element[1]);
				
				node1->setChild(p->child[0],0);
				node1->setChild(p->child[1],1);
				node1->setChild(p->child[2],2);
				
				//node2
				node2->insertElement(p->element[3]);
				
				node2->setChild(p->child[3],0);
				node2->setChild(p->child[4],1);
				
				if (p==root)
				{
					root = new Node();
					root->insertElement(p->element[2]);
					
					root->setChild(node1,0);
					root->setChild(node2,1);

					delete p;
					break;
				}
				else
				{
					p->parent->insertElement(p->element[2]);
					
					for(int i=0;i<=3;i++)
						if (p->parent->child[i]==p)
						{
							for(int j=4;j>=i+2;j--)
								p->parent->child[j]=p->parent->child[j-1];
							
							p->parent->setChild(node1,i);
							p->parent->setChild(node2,i+1);
						}
					
					nodeptr tempPtr=p;
					p=p->parent;
					delete tempPtr;
				}
			}		
		}	
	}	
	
	//remove a value from tree
	void remove(int value)
	{
		cout << "removing " << value << endl;

		nodeptr p = search(value);
	
		if (found==1)
		{
caseOneTwoThree:			
			if ( (p->size>1) && (p->isAllChildExternal()) )//all external child & no. of elements>1 
			{
				p->removeElement(value);//simply remove the element
			}
			else if ((p->size==1) && (p->isAllChildExternal()))//all external child & no. of element=1
			{
				bool has3NodeShibling=0;

				p->removeElement(value);//causes underflow
caseTwoThree:											
				for(int i=0;i<=3;i++)//has a 3-node sibling
				{
					if ( (i<=2) && (p->parent->child[i]==p) && (p->parent->child[i+1]!=0) && (p->parent->child[i+1]->size>1) )
					{
						has3NodeShibling=1;
						p->insertElement(p->parent->element[i]);
						p->parent->element[i]=p->parent->child[i+1]->element[0];
						p->parent->child[i+1]->removeFirstElement();
					}
					else if ( (i>=1) && (p->parent->child[i]==p) && (p->parent->child[i-1]!=0) && (p->parent->child[i-1]->size>1) )
					{
						has3NodeShibling=1;
						p->insertElement(p->parent->element[i-1]);
						p->parent->element[i-1]=p->parent->child[i-1]->lastElement();
						p->parent->child[i-1]->removeLastElement();
					}
				}

				if (has3NodeShibling==0)//has no 3-node sibling (FUSION)
				{
					if ( (p->parent->size>=1) && (p->parent->child[0]==p) )
					{
						p->parent->child[1]->insertElement( p->parent->element[0] );
						
						p->parent->child[1]->child[1]=p->parent->child[1]->child[0];
						p->parent->child[1]->child[2]=p->parent->child[1]->child[1];

						p->parent->child[1]->setChild(p->child[0],0);

						p->parent->removeElement( p->parent->element[0] );
						p->parent->child[0]=p->parent->child[1];
						p->parent->child[1]=p->parent->child[2];
						p->parent->child[2]=p->parent->child[3];
						p->parent->child[3]=0;
					}
					else if ( (p->parent->size>=1) && (p->parent->child[1]==p) )
					{
						p->parent->child[0]->insertElement( p->parent->element[0] );
						
						p->parent->child[0]->setChild(p->child[0],2);

						p->parent->removeElement( p->parent->element[0] );
						p->parent->child[1]=p->parent->child[2];
						p->parent->child[2]=p->parent->child[3];
						p->parent->child[3]=0;
					}
					else if ( (p->parent->size>=2) && (p->parent->child[2]==p) )
					{
						p->parent->child[1]->insertElement( p->parent->element[1] );
						
						p->parent->child[1]->setChild(p->child[0],2);

						p->parent->removeElement( p->parent->element[1] );
						p->parent->child[2]=p->parent->child[3];
						p->parent->child[3]=0;
					}
					else if ( (p->parent->size>=3) && (p->parent->child[3]==p) )
					{
						p->parent->child[2]->insertElement( p->parent->element[2] );
						
						p->parent->child[2]->setChild(p->child[0],2);

						p->parent->removeElement( p->parent->element[2] );
						p->parent->child[3]=0;
					}

					if ((p->parent->size==0) && (p->parent==root))
					{
						root=root->child[0];
						root->parent=0;
					}
					else if ((p->parent->size==0) && (p->parent!=root))
					{
						p=p->parent;
						goto caseTwoThree;
					}
				}
			}
			else
			{
				int ch=-1;

				for(int i=0;i<p->size;i++)
				{
					if (p->element[i]==value) 
					{
						ch=i;
						break;
					}
				}
				
				nodeptr now=p->child[ch];
				
				while(!(now->isAllChildExternal()))
				{
					now=now->child[now->size];
				}
				
				object temp=now->element[(now->size)-1];
				now->element[(now->size)-1]=p->element[ch];
				p->element[ch]=temp;
				
				p=now;
				
				goto caseOneTwoThree;
			}

		}
		else//not found in tree
		{
			cout << "Tree does not contain " << value << ".\n";
		}
	
	}
	
	//traverse the tree inorderly
	void traverse(nodeptr p)
	{
		for(int i=0;i<=3;i++)
		{
			if (p->child[i]!=0) traverse(p->child[i]);
			if ( (i!=3) && (p->element[i]!=max_int)) cout<<p->element[i]<<" ";
		}
	}
	
	//return the root of tree
	nodeptr Root()
	{
		return root;	
	}
	
};



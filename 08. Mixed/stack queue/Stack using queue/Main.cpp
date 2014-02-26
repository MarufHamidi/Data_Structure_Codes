#include<iostream>
using namespace std;
#include "Stack.cpp"

int main(void)
{
	Stack s;

	for(int i=1;i<=10;i++) 
		s.push(i);
	
	s.show();
	
	while(!s.isEmpty())
	{
		cout << s.pop() << endl;
		s.show();
	}

	cout << "Out of while loop : \n";
	s.show();
	
	return 0;
}

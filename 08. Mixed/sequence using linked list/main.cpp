/***********************************
**** Sequence using linked list ****
****----------------------------****
****    Mohammad Minhazul Haq   ****
****           0805051          ****
************************************/

#include<iostream>
#include"sequence.cpp"
using namespace std;

int main()
{
	sequence<int>s;

	s.insertFisrt(10);	//10
	s.insertFisrt(20);	//20,10
	s.insertLast(99);	//20,10,99
	
	cout << "elemAtRank(0) : " << s.elemAtRank(0) << endl;	//20 

	s.replaceAtRank(0,30);	//30,10,99
	s.insertAtRank(2,45);	//30,10,45,99
	s.removeAtRank(3);		//30,10,45
	
	cout << "last element : " << (s.last()).element() <<endl; //45
	
	pos_int p = s.first(); 

	cout << "first element : " << p.element()<<endl;	//30
	cout << "size : " << s.size() << endl;	//3

	return 0;
}

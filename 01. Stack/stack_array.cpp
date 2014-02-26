#include<iostream.h>
//using namespace std;

template <typename Object>

class stack
{
	enum {SIZE=100};
	Object *s;
	int t;
public:
	stack()
	{
		t=-1;
		s = new Object[SIZE]; 
	}

	void push(Object o)
	{
		if (t<(SIZE-1)) s[++t]=o;
	}

	Object pop()
	{
		if (!isEmpty()) return s[t--];
	}

	Object top()
	{
		if (!isEmpty()) return s[t];
	}

	bool isEmpty()
	{
		return (t<0);
	}

	int size()
	{
		return (t+1);
	}
};

int main()
{
	stack<int>s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	cout << "size : " << s.size() << endl;

	cout << "isEmpty : " << s.isEmpty() << endl;

	cout << s.top() << endl;

	cout << s.pop() << " " ;
	cout << s.pop() << " " ;
	cout << s.pop() << " " ;
	cout << s.pop() << " " ;
	cout << s.pop() << " " ;
	cout << s.pop() << endl;

	return 0;
}

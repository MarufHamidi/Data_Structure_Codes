/*****************************************
** Program:Infix to Postfix converter   **
** By : Mohammad Minhazul Haq (0805051) **
*****************************************/

#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

template <typename Object>

class stack
{
	enum {SIZE=100};
	Object *S;
	int t;
public:
	stack()
	{
		t=-1;
		S = new Object[SIZE]; 
	}

	void push(Object c)
	{
		if (t<(SIZE-1)) S[++t]=c;
	}

	Object pop()
	{
		if (!isEmpty()) return S[t--];
	}

	Object top()
	{
		if (!isEmpty()) return S[t];
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

int Prec(char x)
{
	if (x=='+' || x=='-') return 1;
	else if (x=='*' || x=='/') return 2;
	else return -1;
}

int main()
{
	freopen("in.txt","r",stdin);
	
	stack<char>s;
	char a[100],cp;
	int i;

	while(cin>>a)
	{
		s.push('#');

		for(i=0;i<strlen(a);i++)
		{
			if (isalpha(a[i])) cout << a[i];
			else if (a[i]=='(') s.push('(');
			else if (a[i]==')')
			{
				while((cp=s.pop())!='(')
				{
					cout << cp;
				}
			}
			else if (a[i]=='*' || a[i]=='/' || a[i]=='+' || a[i]=='-')
			{
				while(Prec(s.top()) >= Prec(a[i]))
				{
					cout << s.pop();
				}
				s.push(a[i]);
			}
		}

		s.push('$');
		s.pop();

		while((cp=s.pop())!='#')
		{
			cout << cp;
		}

		cout << endl;
	}
	
	return 0;
}

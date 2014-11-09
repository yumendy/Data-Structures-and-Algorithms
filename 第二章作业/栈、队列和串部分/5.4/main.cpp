#include<iostream>
#include"MyStack.h"
using namespace std;
int main()
{
	MyStack <char> a(80);
	char s[80];
	cin>>s;
	char tmp;
	for(int i=0;i<strlen(s);i++)
	{
		switch(s[i])
		{
			case '(':
				a.push('(');
				break;
			case ')':
				if(a.get_top_element()=='(')
					a.pop(tmp);
				else
				{
					cout<<"() is not matched"<<endl;
					return 0;
				}
				break;
			case '[':
				a.push('[');
				break;
			case ']':
				if(a.get_top_element()=='[')
					a.pop(tmp);
				else
				{
					cout<<"[] is not matched"<<endl;
					return 0;
				}
				break;
			case '{':
				a.push('{');
				break;
			case '}':
				if(a.get_top_element()=='{')
					a.pop(tmp);
				else
				{
					cout<<"{} is not matched"<<endl;
					return 0;
				}
				break;
		}
	}
	cout<<"All is matched"<<endl;
	return 0;
}

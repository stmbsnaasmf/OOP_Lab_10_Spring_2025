#include <iostream>
#include <stack>
using namespace std;

bool isBracketSequenceValid(string str)
{
	bool isValid;
	stack<char> s;
	for (int i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if (c == '(' || c == '{' || c == '[' || c == '<')
		{
			cout << "Pushed " << c << "\n";
			s.push(c);
		}
		if (c == ')')
		{
			if (s.top() == '(')
			{
				cout << "Popped " << s.top() << "\n";
				s.pop();
			}
		}
		if (c == '}')
		{
			if (s.top() == '{')
			{
				cout << "Popped " << s.top() << "\n";
				s.pop();
			}
		}
		if (c == ']')
		{
			if (s.top() == '[')
			{
				cout << "Popped " << s.top() << "\n";
				s.pop();
			}
		}
		if (c == '>')
		{
			if (s.top() == '<')
			{
				cout << "Popped " << s.top() << "\n";
				s.pop();
			}
		}
	}
	
	if (s.empty())
	{
		isValid = true;
	}
	else
	{
		isValid = false;
	}
	
	return isValid;
}

int main(void)
{
	string str = "()(){({})}";
//	string str = "()";
	if (isBracketSequenceValid(str))
	{
		cout << "\nValid\n";
	}
	else
	{
		cout << "\nNot valid\n";
	}
	return 0;
}
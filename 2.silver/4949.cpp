#include <iostream>
#include <stack>

using namespace	std;

bool	check(string str) {
	stack<char>	st;
	st.push('!');
	for (int i = 0; str[i] != '.'; i++)
	{
		if (str[i] == '(')
			st.push('(');
		else if (str[i] == '{')
			st.push('{');
		else if (str[i] == '[')
			st.push('[');
		else if (str[i] == ')')
		{
			if (st.top() != '(')
				return (false);
			st.pop();
		}
		else if (str[i] == '}')
		{
			if (st.top() != '}')
				return (false);
			st.pop();
		}
		else if (str[i] == ']')
		{
			if (st.top() != '[')
				return (false);
			st.pop();
		}
	}
	if (st.top() != '!')
			return (false);
	return (true);
}

int main() {
	string		str;
	while (1)
	{
		getline(cin, str);
		if (!str.compare("."))
			break ;
		if (check(str))
			cout << "yes\n";
		else
			cout << "no\n";
	}
}
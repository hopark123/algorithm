#include <iostream>
#include <stack>

using namespace	std;

bool	check(string str) {
	stack<char>	st;
	st.push('!');
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '(')
			st.push('(');
		else if (str[i] == ')')
		{
			if (st.top() != '(')
				return (false);
			st.pop();
		}
	}
	if (st.top() != '!')
			return (false);
	return (true);
}

int main() {
	int		T;
	string		str;
	cin >> T;
	while (T--)
	{
		cin >> str;
		if (check(str))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
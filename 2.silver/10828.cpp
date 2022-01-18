#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int>		st;

void	str_to_func (string str) {
	if (!str.compare("pop")) {
		if (st.empty())
			cout << "-1\n";
		else
		{
			cout << st.top() << "\n"; st.pop();
		}
	}
	else if (!str.compare("size")) {
		if (st.empty())
			cout << "0\n";
		else
			cout << st.size() << "\n";
	}
	else if (!str.compare("empty")) {
		cout << st.empty() << "\n";
	}

	else if (!str.compare("top")) {
		if (st.empty())
			cout << "-1\n";
		else
			cout << st.top() << "\n";
	}

}

int main() {
	int		N;
	cin >> N;
	while (N--) {
		string	temp;
		cin >> temp;
		if (!temp.compare("push"))
		{
			int		num;
			cin >> num;
			st.push(num);
		}
		else
			str_to_func(temp);
	}

}
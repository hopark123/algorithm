#include <iostream>
#include <stack>
using namespace std;

string		str;
// +, -, *, /, (, )
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	stack<char> st;

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			cout << str[i];
		else if (str[i] == '+' || str[i] == '-') {
				while (!st.empty() && (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')) {
					cout << st.top(); st.pop();
				}
			st.push(str[i]);
		}
		else if (str[i] == '*' || str[i] == '/') {
				while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
					cout << st.top(); st.pop();
				}
			st.push(str[i]);
		}
		else if (str[i] == ')') {
			while (!st.empty() && st.top() != '(') {
				cout << st.top(); st.pop();
			}
			st.pop();
		}
		else
			st.push(str[i]);
	}
	while (!st.empty()) {
		cout << st.top(); st.pop();
	}
}
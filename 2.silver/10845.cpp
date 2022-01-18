#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int>		q;

void	str_to_func (string str) {
	if (!str.compare("pop")) {
		if (q.empty())
			cout << "-1\n";
		else
		{
			cout << q.front() << "\n"; q.pop();
		}
	}
	else if (!str.compare("size")) {
		if (q.empty())
			cout << "0\n";
		else
			cout << q.size() << "\n";
	}
	else if (!str.compare("empty")) {
		cout << q.empty() << "\n";
	}
	else if (!str.compare("front")) {
		if (q.empty())
			cout << "-1\n";
		else
			cout << q.front() << "\n";
	}
	else if (!str.compare("back")) {
		if (q.empty())
			cout << "-1\n";
		else
			cout << q.back() << "\n";
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
			q.push(num);
		}
		else
			str_to_func(temp);
	}

}
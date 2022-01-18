#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque<int>		dq;

void	str_to_func (string str) {
	if (!str.compare("pop_front")) {
		if (dq.empty())
			cout << "-1\n";
		else
		{
			cout << dq.front() << "\n"; dq.pop_front();
		}
	}
	else if (!str.compare("pop_back")) {
		if (dq.empty())
			cout << "-1\n";
		else
		{
			cout << dq.back() << "\n"; dq.pop_back();
		}
	}
	else if (!str.compare("size")) {
		if (dq.empty())
			cout << "0\n";
		else
			cout << dq.size() << "\n";
	}
	else if (!str.compare("empty")) {
		cout << dq.empty() << "\n";
	}
	else if (!str.compare("front")) {
		if (dq.empty())
			cout << "-1\n";
		else
			cout << dq.front() << "\n";
	}
	else if (!str.compare("back")) {
		if (dq.empty())
			cout << "-1\n";
		else
			cout << dq.back() << "\n";
	}

}

int main() {
	int		N;
	cin >> N;
	while (N--) {
		string	temp;
		cin >> temp;
		if (!temp.compare("push_front"))
		{
			int		num;
			cin >> num;
			dq.push_front(num);
		}
		else if (!temp.compare("push_back"))
		{
			int		num;
			cin >> num;
			dq.push_back(num);
		}
		else
			str_to_func(temp);
	}

}
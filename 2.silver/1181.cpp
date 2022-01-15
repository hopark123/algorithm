#include <iostream>
#include <string>
#include <set>

using namespace std;

struct Compare {
	bool operator() (const string &a, const string &b) const{
		if (a.size() == b.size())
			return a < b;
		else
			return a.size() < b.size();
	}
};


int main()
{
	int		N;
	string	str;
	std::set<string, Compare> _set;
	cin >> N;
	while (N--)
	{
		cin >> str;
		_set.insert(str);
	}
	for (set<string>::iterator it = _set.begin(); it != _set.end(); ++it)
		cout << *it << endl;
}
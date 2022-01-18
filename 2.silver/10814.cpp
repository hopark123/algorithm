#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,string> a, pair<int,string> b)
{
	return (a.first < b.first);
}

int main() {
	vector<pair<int, string> > vec;
	int		T;
	cin >> T;
	while (T--) {
		int		temp;
		string	str;
		cin >> temp >> str;
		vec.push_back(make_pair(temp, str));
	}
	stable_sort(vec.begin(), vec.end(), compare);
	// while (!vec.empty()) {
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i].first << " " << vec[i].second << "\n";
}
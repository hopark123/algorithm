#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string, int>	_map;
vector<string>		ans;

int main() {
	int		n, k;
	string	temp;
	cin >> n >> k;
	while (n--) {
		cin >> temp;
		_map.insert(make_pair(temp, 0));
	}
	while (k--) {
		cin >> temp;
		if (_map.find(temp) != _map.end())
			ans.push_back(_map.find(temp)->first);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
}
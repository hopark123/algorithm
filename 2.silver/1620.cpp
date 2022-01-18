#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

map<string, int> _map;
vector<string> vec;
int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int		N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++){
		string temp;
		cin >> temp;
		_map.insert(make_pair(temp, i));
		vec.push_back(temp);
	}
	while (M--) {
		string que;
		cin >> que;
		if (que[0] >= '0' && que[0] <= '9')
			cout << vec[stoi(que) - 1] << "\n";
		else {
			cout << _map.find(que)->second << "\n";
		}
	}
}
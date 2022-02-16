#include <iostream>
#include <map>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int		N, M;
	map<string, string> _map;

	cin >> N >> M;
	while (N--) {
		string id;
		string pass;
		cin >> id >> pass;
		_map[id] = pass;
	}
	while (M--) {
		string id;
		cin >> id;
		cout << _map[id] << "\n";
	}
}
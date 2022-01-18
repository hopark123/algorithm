#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int> > vec;
	int		N;
	cin >> N;
	while (N--) {
		int x, y;
		cin >> x >> y;
		vec.push_back(make_pair(y, x));
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i].second << " " << vec[i].first << "\n";
}
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;


class _Compare {
	public :
	bool operator() (pair<int, bool> a, pair<int, bool> b) {
		int left = a.first;
		int right = b.first;
		if (left == right) {
			if (!a.second)
				left *= -1;
			if (!b.second)
				right *= -1;
		}
		return (left >= right);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int		N;
	priority_queue<pair<int, bool> ,vector<pair<int, bool> >, _Compare > pq;
	cin >> N;
	while (N--) {
		int		temp;
		cin >> temp;
		if (temp == 0) {
			pair<int, bool>		res;
			if (!pq.empty()) {
				res = pq.top(); pq.pop();
				if (!res.second)
					cout << "-";
				cout << res.first << "\n";
			}
			else
				cout << "0\n";
		}
		else {
			if (temp > 0)
				pq.push(make_pair(abs(temp), true));
			else
				pq.push(make_pair(abs(temp), false));
		}
	}
}
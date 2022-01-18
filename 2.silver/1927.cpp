#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int, vector<int>, greater<int> > pq;

	int		N;
	int		num;
	cin >> N;
	while (N--) {
		cin >> num;
		if (num == 0) {
			if (!pq.empty()) {
				cout << pq.top() <<"\n"; pq.pop();
			}
			else
				cout << "0\n";
		}
		else {
			pq.push(num);
		}
	}
}

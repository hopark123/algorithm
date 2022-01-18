#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, temp;
	cin >> N;
	while (N--) {
		cin >> temp;
		if (temp == 0) {
			if (!pq.empty()) {
				cout << pq.top() << "\n"; pq.pop();
			}
			else
				cout  << "0\n";
		}
		else
			pq.push(temp);
	}
}


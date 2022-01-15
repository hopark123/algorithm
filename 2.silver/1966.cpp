#include <iostream>
#include <queue>

using namespace std;

int	N, M, T;


int main() {
	cin >> T;
	while (T--) {
		cin >> N >> M;
		priority_queue<int> pq;
		queue<pair<int, int> > q;
		for (int i = 0; i < N; ++i) {
			int	temp;
			cin >> temp;
			q.push(make_pair(i, temp));
			pq.push(temp);
		}
		int	cnt = 0;
		while (!q.empty()) {
			int	index = q.front().first;
			int	weight = q.front().second;
			q.pop();
			if (pq.top() == weight) {
				pq.pop();
				cnt++;
				if (index == M)
				{
					cout << cnt << "\n";
					break ;
				}
			}
			else {
				q.push(make_pair(index, weight));
			}
		}

	}
	

}
#include <iostream>
#include <queue>

using namespace std;
#define INF		1000000000

vector<pair<int, int> > _vec[1006];
int		N, M;


void		dijkstra(int st, int dest) {
	vector<int> dis(N + 1, INF);
	priority_queue<pair<int, int> > _pq;
	_pq.push(make_pair(0, st));
	while (!_pq.empty()) {
		int cost = -_pq.top().first;
		int	now = _pq.top().second; _pq.pop();
		if (dis[now] < cost) continue ;
		for (int i = 0; i < _vec[now].size(); i++) {
			int	next = _vec[now][i].first;
			int	new_cost = cost + _vec[now][i].second;
			if (dis[next] > new_cost) {
				dis[next] = new_cost;
				_pq.push(make_pair(-new_cost, next));
			}
		}
	}
	// for (int i = 1; i <= N; i++) {
	// 	cout << dis[i] << " ";
	// }
	cout << dis[dest] << "\n";
}

int main() {
	cin >> N >> M;
	while (M--) {
		int a, b, c; cin >> a >> b >> c;
		_vec[a].push_back(make_pair(b, c));
	}
	int st, dest; cin >> st >> dest;
	dijkstra(st, dest);
}
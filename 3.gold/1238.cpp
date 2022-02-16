#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000

using namespace std;

vector<pair<int, int> > vec[1005];
int		N, M, X; 
int		ans;

vector<int>			dijkstra(int st) {
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, st));
	vector<int> dist(N + 1, INF);
	dist[st] = 0;
	while (!q.empty()) {
		int cost = -q.top().first;
		int here = q.top().second; q.pop();
		if (dist[here] < cost) continue ;
		for (int i = 0; i < vec[here].size(); i++) {
			int	there = vec[here][i].first;
			int new_cost = dist[here] + vec[here][i].second;
			if (dist[there] > new_cost) {
				dist[there] = new_cost;
				q.push (make_pair(-new_cost, there));
			}
		}
	}
	return (dist);
}

int main() {
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int st, de, co; cin >> st >> de >> co;
		vec[st].push_back(make_pair(de, co));
	}
	vector<int> res[1005];
	for(int i = 1; i <= N; i++)
		res[i] = dijkstra(i);
	int	_max;
	for (int i = 1; i <= N; i++)
		_max = max(_max, res[i][X] + res[X][i]);
	cout << _max;
}

#include <iostream>
#include <vector>

using namespace std;
#define	INF		1000000000

vector<pair<int, int> > _vec[1005];
vector<pair<int, int> > _worm[1005];
int		N, M, W;

bool Bellman_Ford(int st) {
	vector<int> dist(N + 1, INF);
	vector<int> temp;
	dist[st] = 0;

	for (int n = 0; n < N; n++) {
		for (int st = 1; st <= N; st++) {
			// if (dist[st] == INF)	continue;
			for (int i = 0; i < _vec[st].size(); i++) {
				int		next = _vec[st][i].first;
				int		cost = dist[st] + _vec[st][i].second;
				if (cost < dist[next]) {
					dist[next] = cost;
				}
			}
		}
	}
	temp = dist;
	for (int st = 1; st <= N; st++) {
		if (dist[st] == INF)	continue;
		for (int i = 0; i < _vec[st].size(); i++) {
			int		next = _vec[st][i].first;
			int		cost = dist[st] + _vec[st][i].second;
			if (cost < dist[next]) {
				dist[next] = cost;
			}
		}
	}
	if (temp == dist)
		return (true);
	return (false);
}

int main() {
	int TC; cin >> TC;
	bool	res;
	while (TC--) {
		cin >> N >> M >> W;
		int a, b, c;
		for (int i = 0; i < M; i++) {
			cin >> a >> b >> c;
			_vec[a].push_back(make_pair(b, c));
			_vec[b].push_back(make_pair(a, c));
		}
		for (int i = 0; i < W; i++) {
			cin >> a >> b >> c;
			_vec[a].push_back(make_pair(b, -c));
		}
			res = Bellman_Ford(0);
			if (!res)
				cout << "YES\n";
			else
				cout << "NO\n";
		for (int i = 0; i <= N; i++) {
			_vec[i].clear();
			_worm[i].clear();
		}
	}
}
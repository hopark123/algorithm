#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

#define	INF 1000000000

using namespace std;

int		N, E , v1, v2;
vector<pair<int, int> > _vec[805];

vector<int>		dijkstra(int st) {
	priority_queue<pair<int, int> >	q;
	vector<int>					res(N + 1, INF);
	res[st] = 0;
	q.push(make_pair(0, st));
	while (!q.empty()) {
		int cost = -q.top().first;
		int here = q.top().second; q.pop();
		if (res[here] < cost) continue ;
		for (int i = 0; i < _vec[here].size(); i++) {
			int	new_cost = cost + _vec[here][i].second;
			int	next = _vec[here][i].first;
			if (res[next] > new_cost) {
				res[next] = new_cost;
				q.push(make_pair(-new_cost, next));
			}
		}
	}
	return (res);
}


int main() {
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c; cin >> a >> b >> c;
		_vec[a].push_back(make_pair(b, c));
		_vec[b].push_back(make_pair(a, c));
	}
	cin >> v1 >> v2;
	vector<int> ans[2];
	ans[0] = dijkstra(v1);
	ans[1] = dijkstra(v2);

	int		one = ans[0][1] + ans[0][v2] + ans[1][N];
	int		two = ans[1][1] + ans[1][v1] + ans[0][N];
	int		res = min(one, two);
	if (res < 0)
		cout << "-1\n";
	else
		cout << res << "\n";
}
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
#define	INF		1000000000

int		n;
vector<pair<int, int > > _vec[10005];


vector<int>	dijkstra(int st) {
	vector<int> dis(n + 1, INF);
	queue<pair<int, int> >		q;
	dis[st] = 0;
	q.push(make_pair(st, 0));
	while (!q.empty()) {
		int here = q.front().first;
		int cost = q.front().second; q.pop();
		// if (dis[here] < cost) continue;
		for (int i = 0; i < _vec[here].size(); i++) {
			int next = _vec[here][i].first;
			int new_cost = _vec[here][i].second + cost;
			if (dis[next] > new_cost) {
				dis[next] = new_cost;
				q.push(make_pair(next, new_cost));
			}
		}
	}
	return (dis);
}


int main() {
	vector<int> res;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b, c; 
		cin >> a >> b >> c;
		_vec[a].push_back(make_pair(b,c));
		_vec[b].push_back(make_pair(a,c));
	}
	res = dijkstra(1);
	int temp = 0;
	int	next = 1;
	for (int i = 1; i <= n; i++) {
		// cout << res[i] << " ";
		if (temp < res[i]) {
			temp = res[i];
			next = i;
		}
	}
	// cout << next <<"\n";
	res = dijkstra(next);
	for (int i = 1; i <= n; i++) {
		// cout << res[i] << " ";
		temp = max(temp, res[i]);
	}
	cout << temp << "\n";
}
#include <iostream>
#include <vector>
#include <queue>

#define VERTEX_MAX 20001
#define EDGE_MAX 300001
#define INF 1000000000

using namespace std;

int		V, E, K, u, v, k;

vector<int>	dijkstra(int dest, vector<pair<int, int> > *cost)
{
	vector<int>	dist(V + 1, INF);
	dist[dest] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, dest));
	while (!pq.empty())
	{
		int	pq_cost = -pq.top().first;
		int	pq_here = pq.top().second;
		pq.pop();
		if (dist[pq_here] < pq_cost) continue;
		for (size_t i = 0; i < cost[pq_here].size(); ++i)
		{
			int	there = cost[pq_here][i].first;
			int	newCost	= pq_cost + cost[pq_here][i].second;
			if (dist[there] > newCost)
			{
				dist[there] = newCost;
				pq.push(make_pair(-newCost, there));
			}
		}
	}
	return (dist);
}

int main()
{
	vector<int> res;
	cin >> V >> E >> K;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<pair<int, int> > cost[VERTEX_MAX + 1];

	for (int i = 0; i < E; i++)
	{
		pair<int, int> temp;
		cin >> u >>  v >> k;
		temp.first = v;
		temp.second = k;
		cost[u].push_back(temp);
	}
	res = dijkstra(K, cost);
	for (size_t i = 1; i < res.size(); i++)
	{	
		if (res[i] == INF)
			cout << "INF\n";
		else
			cout << res[i] << "\n";
	}
}
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_set>
#define INF 10000001

using namespace std;

vector<pair<int, int> > cost[50005];
queue<int> intens;
priority_queue<int> pq;
// set<int> sset;
// unordered_set<int> sset;
bool sset[50005];
// unordered_set<int> gset;
bool gset[50005];
int maxDIs = 0;

vector<int> dijkstra(int N, vector<int> gates) {
  priority_queue<pair<int, int> > q;
  vector<int> dist(N + 1, INF);
  vector<int> res(2, INF);
  for(auto it : gates) {
    dist[it] = 0;
    q.push(make_pair(0, it));
  }
  while (!q.empty()) {
    int old_cost = -q.top().first;
    int here = q.top().second; q.pop();
    if (dist[here] < old_cost) continue;
    if (sset[here]) {
      if (res[1] > old_cost) {
      res[0] = here;
      res[1] = old_cost;
      }
      else if (res[1] == old_cost) {
        res[0] = min(res[0], here);
      }
      continue;
    }
    for (int i = 0; i < cost[here].size(); ++i) {
      int there = cost[here][i].first;
      int new_cost = (dist[there] == INF) ? max(cost[here][i].second, dist[here]) : min(max(dist[here], cost[here][i].second), dist[there]);
      if (gset[there])
        continue;
      if (dist[there] > new_cost) {
        dist[there] = new_cost;
        q.push(make_pair(-new_cost, there));
      }
    }
  }
  return res;
}


vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer(2, INF);
    // cost.resize(n + 1);
    for (int i = 0; i < summits.size(); ++i) {
      // sset.insert(summits[i]);
      sset[summits[i]] = true;
    }
    for (int i = 0; i < gates.size(); ++i) {
      gset[gates[i]] = true;
    }
    for (int i = 0; i < paths.size(); ++i) {
      cost[paths[i][0]].push_back(make_pair(paths[i][1], paths[i][2]));
      cost[paths[i][1]].push_back(make_pair(paths[i][0], paths[i][2]));
    }
      vector<int> visited;
      answer = dijkstra(n, gates);

    return answer;
}

int main()
{
	ios::sync_with_stdio(false);
  vector<vector<int> > a;
  vector<int> b;
  vector<int> c;
  b.push_back(1);
  b.push_back(2);
  b.push_back(5);
  a.push_back(b);
  b.clear();

  b.push_back(1);
  b.push_back(4);
  b.push_back(1);
  a.push_back(b);
  b.clear();

  b.push_back(2);
  b.push_back(3);
  b.push_back(1);
  a.push_back(b);
  b.clear();


  b.push_back(2);
  b.push_back(6);
  b.push_back(7);
  a.push_back(b);
  b.clear();

    b.push_back(4);
  b.push_back(5);
  b.push_back(1);
  a.push_back(b);
  b.clear();

    b.push_back(5);
  b.push_back(6);
  b.push_back(1);
  a.push_back(b);
  b.clear();

  b.push_back(6);
  b.push_back(7);
  b.push_back(1);
  a.push_back(b);
  b.clear();
  b.push_back(3);
  b.push_back(7);

  c.push_back(1);
  c.push_back(5);

// b.push_back(1);
//   b.push_back(2);
//   b.push_back(3);
//   a.push_back(b);
//   b.clear();
//   b.push_back(2);
//   b.push_back(3);
//   b.push_back(5);
//   a.push_back(b);
//   b.clear();
//   b.push_back(2);
//   b.push_back(4);
//   b.push_back(2);
//   a.push_back(b);
//   b.clear();
//   b.push_back(2);
//   b.push_back(5);
//   b.push_back(4);
//   a.push_back(b);
//   b.clear();
//   b.push_back(3);
//   b.push_back(4);
//   b.push_back(4);
//   a.push_back(b);
//   b.clear();
//   b.push_back(4);
//   b.push_back(5);
//   b.push_back(3);
//   a.push_back(b);
//   b.clear();
//   b.push_back(4);
//   b.push_back(6);
//   b.push_back(1);
//   a.push_back(b);
//   b.clear();
//   b.push_back(5);
//   b.push_back(6);
//   b.push_back(1);
//   a.push_back(b);
//   b.clear();
//   b.push_back(1);
//   b.push_back(3);
//   c.push_back(5);
  vector<int> sol = solution(7, a, b, c);
  for (size_t i = 0; i < sol.size(); ++i)
    cout << sol[i] << endl;
}

/*
6	[[1, 2, 3], [2, 3, 5], [2, 4, 2], [2, 5, 4], [3, 4, 4], [4, 5, 3], [4, 6, 1], [5, 6, 1]]	[1, 3]	[5]	[5, 3]
7	[[1, 4, 4], [1, 6, 1], [1, 7, 3], [2, 5, 2], [3, 7, 4], [5, 6, 6]]	[1]	[2, 3, 4]	[3, 4]
7	[[1, 2, 5], [1, 4, 1], [2, 3, 1], [2, 6, 7], [4, 5, 1], [5, 6, 1], [6, 7, 1]]	[3, 7]	[1, 5]	[5, 1]
5	[[1, 3, 10], [1, 4, 20], [2, 3, 4], [2, 4, 6], [3, 5, 20], [4, 5, 6]]	[1, 2]	[5]	[5, 6]
*/


/*
 b.push_back(1);
  b.push_back(2);
  b.push_back(3);
  a.push_back(b);
  b.clear();
  b.push_back(2);
  b.push_back(3);
  b.push_back(5);
  a.push_back(b);
  b.clear();
  b.push_back(2);
  b.push_back(4);
  b.push_back(2);
  a.push_back(b);
  b.clear();
  b.push_back(2);
  b.push_back(5);
  b.push_back(4);
  a.push_back(b);
  b.clear();
  b.push_back(3);
  b.push_back(4);
  b.push_back(4);
  a.push_back(b);
  b.clear();
  b.push_back(4);
  b.push_back(5);
  b.push_back(3);
  a.push_back(b);
  b.clear();
  b.push_back(4);
  b.push_back(6);
  b.push_back(1);
  a.push_back(b);
  b.clear();
  b.push_back(5);
  b.push_back(6);
  b.push_back(1);
  a.push_back(b);
  b.clear();
  b.push_back(1);
  b.push_back(3);
  c.push_back(5);
*/



/*
b.push_back(1);
  b.push_back(4);
  b.push_back(4);
  a.push_back(b);
  b.clear();

  b.push_back(1);
  b.push_back(6);
  b.push_back(1);
  a.push_back(b);
  b.clear();

  b.push_back(1);
  b.push_back(7);
  b.push_back(3);
  a.push_back(b);
  b.clear();


    b.push_back(2);
  b.push_back(5);
  b.push_back(2);
  a.push_back(b);
  b.clear();

    b.push_back(3);
  b.push_back(7);
  b.push_back(4);
  a.push_back(b);
  b.clear();

    b.push_back(5);
  b.push_back(6);
  b.push_back(6);
  a.push_back(b);
  b.clear();
  b.push_back(1);
  c.push_back(2);
  c.push_back(3);
  c.push_back(4);

*/



/*b.push_back(1);
  b.push_back(3);
  b.push_back(10);
  a.push_back(b);
  b.clear();

  b.push_back(1);
  b.push_back(4);
  b.push_back(20);
  a.push_back(b);
  b.clear();

  b.push_back(2);
  b.push_back(3);
  b.push_back(4);
  a.push_back(b);
  b.clear();


    b.push_back(2);
  b.push_back(4);
  b.push_back(6);
  a.push_back(b);
  b.clear();

    b.push_back(3);
  b.push_back(5);
  b.push_back(20);
  a.push_back(b);
  b.clear();

    b.push_back(4);
  b.push_back(5);
  b.push_back(6);
  a.push_back(b);
  b.clear();
  b.push_back(1);
  b.push_back(2);

  c.push_back(5);
*/
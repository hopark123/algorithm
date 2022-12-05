#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;

vector<bool> visited;
vector<vector<pair<int, int> > >edg;

int res = 1e7;
int n;


vector<int> dij(int st) {
  priority_queue<pair<int, int> > pq;
  vector<int> vec(n + 1, 1e7);
  vec[st] = 0;
  pq.push(make_pair(0, st));

  while (!pq.empty()) {
    int cost = -pq.top().first;
    int here = pq.top().second; pq.pop();
    if (cost > vec[here]) continue;
    for (int i = 0; i < edg[here].size(); ++i) {
      int there = edg[here][i].first;
      int here_to_there = edg[here][i].second + vec[here];
      if (here_to_there < vec[there]) {
        vec[there] = here_to_there ;
        pq.push(make_pair(-here_to_there, there));
      }
    }
  }
  return vec;
}

int minCostPath(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight, int x, int y) {
  edg.resize(g_nodes + 1);
  visited.resize(g_nodes + 1, false);
  n = g_nodes;
  for (int i = 0; i < g_from.size(); ++i) {
    // cout << g_from[i]<<"@->" << g_to[i]<<" " << g_weight[i] << endl;
    edg[g_from[i]].push_back(make_pair(g_to[i], g_weight[i]));
    edg[g_to[i]].push_back(make_pair(g_from[i], g_weight[i]));
  }
  vector<int> from_st = dij(1);
  vector<int> from_x = dij(x);
  vector<int> from_y = dij(y);
  
  // for (int i = 0; i <= g_nodes; ++i)
  //   cout << from_st[i] << " ";
  // cout << endl;
  // for (int i = 0; i <= g_nodes; ++i)
  //   cout << from_x[i] << " ";
  // cout << endl;
  // for (int i = 0; i <= g_nodes; ++i)
  //   cout << from_y[i] << " ";
  // cout << endl;
  return (from_st[x] + from_x[y] + from_y[g_nodes]);
}

int main()
{
  ios::sync_with_stdio(false);
  vector<int> a = {1, 1, 2, 2, 3};
  vector<int> b = {2, 4, 4, 3, 4};
  vector<int> c = {6, 9, 10, 6, 11};
  int sol = minCostPath(4 , a, b, c, 2, 3);
  cout << sol << endl;
}


/*
4 5
1 2 6
1 4 9
2 4 10
2 3 6
3 4 11
2
3

*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;



vector<int> trap(1000);
vector<vector<pair<int, int> > > edge;
int res = 1e7;

void dfs(int now, int end, vector<int> traps, int cost) {
  if (now == end) {
  priority_queue<int> 

  }

}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
  int answer = 0;
  edge.resize(n, vector<pair<int, int>>(n));
  for (int i = 0 ; i < roads.size(); ++i) {
    int st = roads[i][0];
    int end = roads[i][1];
    int cost = roads[i][2];
    edge[st].push_back({end, cost});
  }
  return answer;
}


int main()
{
  ios::sync_with_stdio(false);
  vector<vector<int> > a = {{1, 2, 2}, {3, 2, 3}};
  vector<int> b = {2};
 
  int sol = solution(3, 1, 3, a, b);
  
  cout << sol << endl;
}


/*
n	start	end	roads	traps	result
3	1	3	{{1, 2, 2}, {3, 2, 3}}	{2}	5
4	1	4	{{1, 2, 1}, {3, 2, 1}, {2, 4, 1}}	{2, 3}	4
*/
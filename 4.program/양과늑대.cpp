#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

int N;
vector<int> visited;
int res = 0;


bool clear(vector<int> info) {
  for (int i = 0; i < N; ++i) {
    if (info[i] == 0) {
      if (visited[i] == 0 || visited[i] == 1) // 0아직 안감 1갈수있음 2갔다옴
        return false;
    }
  }
  return true;
}

void dfs(vector<int> info, vector<vector<int> > data, int index, int sheep, int wolf) {
  // cout <<"[" << sheep << "][" << wolf << "]" << endl;
  // for (int a = 0; a < N; ++a)
  //   cout << a << " ";
  // cout << endl;
  // for (int a = 0; a < N; ++a)
  //   cout << visited[a] << " ";
  // cout << endl;
  // cout << endl;
  // if (sheep <= wolf) {
  //   return ;
  // }
  if (sheep <= wolf || clear(info)) {
    // cout << "@@@@@@@@@@@@@clear" << endl;
    res = max(res, sheep);
    return ;
  }
  for (int i = 0; i < N; ++i) {
    if (visited[i] == 1) {
        visited[i] = 2;
        // cout << index << "->" << i << endl;
        for(int j = 0; j < data[i].size(); ++j) {
          visited[data[i][j]] = 1;
        }
        if (info[i] == 1)
          dfs(info, data, i, sheep, wolf + 1);
        else
          dfs(info, data, i, sheep + 1, wolf);

        for(int j = 0; j < data[i].size(); ++j) {
          visited[data[i][j]] = 0;
        }
        visited[i] = 1;
    }
  }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    N = info.size();
    vector<vector<int> > data(N);
    visited.resize(N, 0);
    for (auto &edge : edges) {
      data[edge[0]].push_back(edge[1]);
    }
    for(int j = 0; j < data[0].size(); ++j) {
          visited[data[0][j]] = 1;
    }
    visited[0] = 2;
    dfs(info, data, 0, 1, 0);
    answer = res;
    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  // vector<int> a = {0,0,1,1,1,0,1,0,1,0,1,1};
  // vector<vector<int> > b = {{0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9}};
vector<int> a = {0,1,0,1,1,0,1,0,0,1,0};
vector<vector<int> > b = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6},{3,7},{4,8},{6,9},{9,10}};

  int sol = solution(a, b);
  cout << sol << endl;
}


/*
info	edges	result
[0,0,1,1,1,0,1,0,1,0,1,1]	[[0,1],[1,2],[1,4],[0,8],[8,7],[9,10],[9,11],[4,3],[6,5],[4,6],[8,9]]	5
[0,1,0,1,1,0,1,0,0,1,0]	[[0,1],[0,2],[1,3],[1,4],[2,5],[2,6],[3,7],[4,8],[6,9],[9,10]]	5
*/
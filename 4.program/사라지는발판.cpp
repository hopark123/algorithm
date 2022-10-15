#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
int N, M;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool safe(int y, int x) {
  return (y>=0 && x>=0 && y<N && x<M);
}
bool cantMove(vector<vector<int> > &board, int y, int x) {
  for (int i = 0; i < 4; ++i) {
    if (safe(y + dy[i], x + dx[i]) && board[y + dy[i]][x + dx[i]])
      return false;
  }
  return true;
}

pair<bool, int> dfs(vector<vector<int> > &board, int y1, int x1, int y2, int x2) {
  if (cantMove(board, y1, x1) ) return {false, 0};
  
  pair<bool, int> res = {false, 0};
  if (!board[y1][x1]) return res;
  int res_min = 1e9;
  int res_max = 0;
  for (int i = 0; i < 4; ++i) {
    int nextY = y1 + dy[i];
    int nextX = x1 + dx[i];
    if (!safe(nextY, nextX) || !board[nextY][nextX]) continue;
    board[y1][x1] = 0;
    pair<bool, int> next = dfs(board, y2, x2, nextY, nextX);
    board[y1][x1] = 1;
    if (!next.first) {
      res.first = true;
      res_min = min(res_min, next.second);
    }
    else
      res_max = max(res_max, next.second);
  }
  res.second = res.first ? res_min + 1 : res_max + 1;
  return (res);
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = -1;
    N = board.size();
    M = board[0].size();
    answer = dfs(board, aloc[0], aloc[1], bloc[0], bloc[1]).second;
    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  // vector<vector<int> > a = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
  // vector<int> b = {1, 0};
  // vector<int> c = {1, 2};

  vector<vector<int> > a = {{1, 1, 1, 1, 1}};
  vector<int> b = {0, 0};
  vector<int> c = {0, 4};

  int sol = solution(a, b, c);
  cout << sol << endl;
}


/*
board	aloc	bloc	result
[[1, 1, 1], [1, 1, 1], [1, 1, 1]]	[1, 0]	[1, 2]	5
[[1, 1, 1], [1, 0, 1], [1, 1, 1]]	[1, 0]	[1, 2]	4
[[1, 1, 1, 1, 1]]	[0, 0]	[0, 4]	4
[[1]]	[0, 0]	[0, 0]	0

*/
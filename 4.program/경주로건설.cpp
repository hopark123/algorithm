#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;

int res;
int N;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

vector<vector<int> > visited1;
vector<vector<int> > visited2;

bool ft_wall(vector<vector<int> > board, int y, int x) {
  if (y < N  && y >= 0 && x < N  && x >= 0 && board[y][x] == 0) 
    return true;
  return false;
}


void dfs(vector<vector<int> > board, int y, int x, bool dir, int cost) {
  if (dir) {
    visited1[y][x] = cost;
  }
  else {
    visited2[y][x] = cost;
  }
  if (y == N - 1 && x == N - 1) {
    return ;
  }
  for (int i = 0; i < 2; ++i) {
    int ny = y + dy[i];
    int ncost = min(visited1[y][x] + 100, visited2[y][x] + 600);
    if (ft_wall(board, ny, x) && ncost < visited1[ny][x])
      dfs(board, ny, x, true, ncost);
  }
  for (int i = 2; i < 4; ++i) {
    int nx = x + dx[i];
    int ncost = min(visited1[y][x] + 600, visited2[y][x] + 100);
    if (ft_wall(board, y, nx) && ncost < visited2[y][nx])
      dfs(board, y, nx, false, ncost);
  }
}


int solution(vector<vector<int> > board) {
    int answer = 0;
    N = board.size();
    visited1.resize(N, vector<int>(N, 1e7));
    visited2.resize(N, vector<int>(N, 1e7));
    visited1[0][0] = 0;
    visited2[0][0] = 0;
    dfs(board, 0, 0, true, 0);
    answer = min(visited1[N - 1][N - 1], visited2[N - 1][N - 1]);
    return answer;
}


int main()
{
  ios::sync_with_stdio(false);
  vector<vector<int> > a = {{0,1,1,0},{0,0,0,1},{1,1,0,0},{1,1,1,0}};
  // vector<vector<int> > a = {{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0}};
  int sol = solution(a);
  cout << sol << endl;
}


/*

board	result
{{0,0,0},{0,0,0},{0,0,0}}	900
{{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0}}	3800
{{0,0,1,0},{0,0,0,0},{0,1,0,1},{1,0,0,0}}	2100
{{0,0,0,0,0,0},{0,1,1,1,1,0},{0,0,1,0,0,0},{1,0,0,1,0,1},{0,1,0,0,0,1},{0,0,0,0,0,0}}	3200
*/
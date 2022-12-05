#include <string>
#include <vector>
#include <iostream>

using namespace std;



int N;
int dx[2] = {1, -1};
int dy[2] = {1, -1};

vector<vector<int>> arr[2];

bool wall(int y, int x, vector<vector<int> > board) {
  return (y < N && y >= 0 && x < N && x >= 0 && !board[y][x]);
}

// dir [y : 0] [x : 1]
void dfs(int y, int x, vector<vector<int> > board, int cost, int dir) {
  arr[dir][y][x] = cost;
  for (int i = 0; i < 2; ++i) {
      int ty = y + dy[i];
      int cost_y = min(arr[0][y][x] + 100, arr[1][y][x] + 600);
      if (wall(ty, x, board) && arr[0][ty][x] > cost_y) {
        dfs(ty, x, board, cost_y, 0);
      }
      int tx = x + dx[i];
      int cost_x = min(arr[0][y][x] + 600, arr[1][y][x] + 100);
      if (wall(y, tx, board) && arr[1][y][tx] > cost_x) {
        dfs(y, tx, board, cost_x, 1);
      }
  }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    N = board.size();
    arr[0].resize(N, vector<int>(N, 1e7));
    arr[1].resize(N, vector<int>(N, 1e7));
    arr[0][0][0] = 0;
    arr[1][0][0] = 0;
    dfs(0, 0, board, 0, 0);
    dfs(0, 0, board, 0, 1);
    return answer = min(arr[0][N - 1][N - 1], arr[1][N -1][N -1]);
}

int main()
{
  ios::sync_with_stdio(false);
  // vector<vector<int> > a = {{0,1,1,0},{0,0,0,1},{1,1,0,0},{1,1,1,0}};
  // vector<vector<int> > a = {{0,0,0},{0,0,0},{0,0,0}};
  vector<vector<int> > a = {{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0}};
  int sol = solution(a);
  cout << sol << endl;
}


/*
https://school.programmers.co.kr/learn/courses/30/lessons/67259

board	result
{{0,0,0},{0,0,0},{0,0,0}}	900
{{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0}}	3800
{{0,0,1,0},{0,0,0,0},{0,1,0,1},{1,0,0,0}}	2100
{{0,0,0,0,0,0},{0,1,1,1,1,0},{0,0,1,0,0,0},{1,0,0,1,0,1},{0,1,0,0,0,1},{0,0,0,0,0,0}}	3200
*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int N;
int dx[2] = {1, -1};
int dy[2] = {1, -1};

vector<vector<int>> arr[2];

// bfs 보다 빠르다, dp저장 위치를 잘 설정 해야한다

class info {
  public :
  info(int _y, int _x, int _cost, int _dir) : y(_y), x(_x), cost(_cost), dir(_dir) {};

  int y, x, cost, dir;
};

class _compare{
  public :
  bool operator() (info a, info b) {
    return a.cost > b.cost;
  }
};


bool wall(int y, int x, vector<vector<int> > board) {
  return (y < N && y >= 0 && x < N && x >= 0 && !board[y][x]);
}

// dir [y : 0] [x : 1]

int solution(vector<vector<int>> board) {
    int answer = 0;
    N = board.size();
    arr[0].resize(N, vector<int>(N, 1e7));
    arr[1].resize(N, vector<int>(N, 1e7));
    arr[0][0][0] = 0;
    arr[1][0][0] = 0;
    priority_queue<info, vector<info>, _compare> pq;
    info stY(0, 0, 0, 0); pq.push(stY);
    while (!pq.empty()) {
      info top = pq.top(); pq.pop();
      if (top.cost > arr[top.dir][top.y][top.x]) continue;
      // arr[top.dir][top.y][top.x] = top.cost;
      for (int i = 0; i < 2; ++i) {
        int ty = top.y + dy[i];
        int cost_y = min(arr[0][top.y][top.x] + 100, arr[1][top.y][top.x] + 600);
        if (wall(ty, top.x, board) && arr[0][ty][top.x] > cost_y) {
          arr[0][ty][top.x] = cost_y;
          pq.push(info(ty, top.x, cost_y, 0));
        }
        int tx = top.x + dx[i];
        int cost_x = min(arr[0][top.y][top.x] + 600, arr[1][top.y][top.x] + 100);
        if (wall(top.y, tx, board) && arr[1][top.y][tx] > cost_x) {
          arr[1][top.y][tx] = cost_x;
          pq.push(info(top.y, tx, cost_x, 1));
        }
      }
    }
    return answer = min(arr[0][N - 1][N - 1], arr[1][N -1][N -1]);
}

int main()
{
  ios::sync_with_stdio(false);
  // vector<vector<int> > a = {{0,1,1,0},{0,0,0,1},{1,1,0,0},{1,1,1,0}};
  // vector<vector<int> > a = {{0,0,0},{0,0,0},{0,0,0}};
  vector<vector<int >> a;
  vector<int> b;
  for (int i = 0; i < 25; ++i)
    b.push_back(0);
  for (int i = 0; i < 25; ++i)
    a.push_back(b);
  // vector<vector<int> > a = {{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0}};
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
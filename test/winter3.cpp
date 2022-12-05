#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;


int N;
int answer =  1e7;

vector<vector<int> > dir= {{-1, 1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}};
vector<vector<int> > arr[8];

bool safe(int y, int x, vector<string> worldmap) {
  return (y < N && x < N && y >= 0 && x >= 0 && worldmap[y][x] != 'X' );
}

bool canGo(int y, int x, int d, vector<string> worldmap) {
  // cout << y << x << d <<  (worldmap[y + dir[d][0]][x] != 'X' && worldmap[y][x + dir[d][1]] != 'X') << endl;
  return (worldmap[y + dir[d][0]][x] != 'X' && worldmap[y][x + dir[d][1]] != 'X');
}

void dfs(vector<string> worldamp, int d, int i, int j, int step) {
  cout << d << " " << i << " " << j << " " << step << endl;
  if (i == N && j == N ) {
    return ;
  }

    for (int j = 0; j < N; ++j) {
      for (int i = 0; i < 8 ; ++i) {
        for (int k = 0; k < N; ++k) {
          if (worldamp[j][k] == 'X')
            cout << 'x' << " ";
          else if (arr[i][j][k] == 1e7) {
            cout << "." << " ";
          }
          else
            cout << arr[i][j][k] << " ";
        }
        cout << "|||";
      }
    cout << endl;
  }
  cout << "========" << endl;
  cout << "@" << endl;
  int nd = d;
  int ny = i + dir[nd][0];
  int nx = j + dir[nd][1];
  cout << "#" << endl;
  if (safe(ny, nx, worldamp) && canGo(i, j, nd, worldamp) && arr[nd][ny][nx] > step) {
    arr[nd][ny][nx] = step;
    dfs(worldamp, nd, ny, nx, step + 1);
  }
  nd = (d + 1) % 8;
  ny = i + dir[nd][0];
  nx = j + dir[nd][1];
  cout << "B" << endl;
  // dfs(worldamp, nd, i, j, step);
  cout << "D" << endl;
  if (safe(ny, nx, worldamp) && canGo(i, j, nd, worldamp) && arr[nd][ny][nx] > step) {
    cout << "F" << endl;
    arr[nd][ny][nx] = step;
    dfs(worldamp, nd, ny, nx, step + 1);
  }
  cout << "C" << endl;
  nd = (d - 1) % 8;
  ny = i + dir[nd][0];
  nx = j + dir[nd][1];
  if (safe(ny, nx, worldamp) && canGo(i, j, nd, worldamp) && arr[nd][ny][nx] > step) {
    arr[nd][ny][nx] = step;
    dfs(worldamp, nd, ny, nx, step + 1);
  }
}

int solution(vector<string> worldmap) {
    int answer = 1e7;
    N = worldmap.size();
    for (int i = 0; i < 8; ++i) {
      arr[i].resize(N, vector<int>(N, 1e7));
    }
    arr[5][0][0] = 0;
    dfs(worldmap, 5, 0, 0, 1);
    for (int i = 0; i < 8; ++i) {
      answer = min(arr[i][N - 1][N - 1], answer);
      cout << arr[i][N - 1][N - 1] << endl;
    }
    return answer;
}
int main()
{
  ios::sync_with_stdio(false);
  // vector<string > a ={"..XXX", "..XXX", "...XX", "X....", "XXX.."};
  vector<string > a ={".....", "X.XX.", "...X.", "X....", "XXX.."};

  int sol = solution(a);
  cout << sol << endl;
}


/*

["..XXX", "..XXX", "...XX", "X....", "XXX.."]
기댓값 〉
5

*/
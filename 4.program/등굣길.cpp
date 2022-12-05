#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;

vector<vector<int> > board;
vector<int> res;
int mmin = 1e7;
int M, N;
int dy[2] = {1, 0};
int dx[2] = {0, 1};

bool safe(int y, int x) {
    return (y >= 1 && y <= N && x >= 1 && x <= M);
}

long long mod(long long res) {
    return res % 1000000007;
}

void dfs(int y, int x, int step) {
    // for (int i = 1; i <= N; ++i) {
    //     for (int j = 1 ; j <= M; ++j) {
    //         if (board[i][j] == 1e7)
    //             cout << "x" << " ";
    //         else
    //             cout << board[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // cout << endl;
    if (y == N && x == M) {
        mmin = min(step, mmin);
        res.push_back(step);
        return;
    }
    // if (y > N || x < M || step > 100)
    //     return ;
    for (int i = 0; i < 2; ++i) {
        int ty = y + dy[i];
        int tx = x + dx[i];
        if(safe(ty, tx) && board[ty][tx] == 1e7){
            board[ty][tx] = 1;
            dfs(ty, tx, step + 1);
            board[ty][tx] = 1e7;
        }
    }
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    M = m; N = n;
    board.resize(N + 1, vector<int>(M + 1, 1e7));
    for (int i = 0; i < puddles.size(); ++i) {
      board[puddles[i][1]][puddles[i][0]] = -1;
    }
    board[1][1] = 0;
    dfs(1, 1, 1);
    sort(res.begin(), res.end());
    // for (int i = 0; i < res.size(); ++i)
    //   cout << res[i] << " ";
    // cout << endl;
    return mod(upper_bound(res.begin(), res.end(), mmin) - res.begin());
}
int main()
{
  ios::sync_with_stdio(false);
  vector<vector<string> > a;
  vector<string> b;
 
  b.clear();
  int sol = solution(5, 4, {{2, 2}, {3,3}});
  // int sol = solution(4, 3, 0);
  cout << sol << endl;
}


/*


*/
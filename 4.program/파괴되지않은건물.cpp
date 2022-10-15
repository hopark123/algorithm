#include <string>
#include <vector>
#include <iostream>
using namespace std;

int N, M;


int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    N = board.size();
    M = board[0].size();
    vector<vector<int> > dif(N + 2, vector<int>(M + 2, 0));
    for (auto &s : skill) {
      int type = s[0];
      int r1 = s[1];
      int c1 = s[2];
      int r2 = s[3];
      int c2 = s[4];
      int dg = type == 1 ? s[5] : -s[5];
      dif[r1 + 1][c1 + 1] += dg;
      dif[r2 + 2][c1 + 1] -= dg;
      dif[r1 + 1][c2 + 2] -= dg;
      dif[r2 + 2][c2 + 2] += dg;
    }

    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= M; ++j) 
        dif[i][j] += -dif[i-1][j-1] + dif[i][j - 1] + dif[i - 1][j];
    }
    
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) 
        if (board[i][j] > dif[i + 1][j + 1])
          ++answer;
    }
    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  vector<vector<int> > a ={{5,5,5,5,5}, {5,5,5,5,5}, {5,5,5,5,5}, {5,5,5,5,5}};
  vector<vector<int> > b = {{1,0,0,3,4,4}, {1,2,0,2,3,2}, {2,1,0,3,1,2}, {1,0,1,3,3,1}};
 

  int sol = solution(a, b);
  cout << sol << endl;
}


/*
dif	skill	result
[[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5]]	[[1,0,0,3,4,4],[1,2,0,2,3,2],[2,1,0,3,1,2],[1,0,1,3,3,1]]	10
[[1,2,3],[4,5,6],[7,8,9]]	[[1,1,1,2,2,4],[1,0,0,1,1,2],[2,2,0,2,0,100]]	6

*/
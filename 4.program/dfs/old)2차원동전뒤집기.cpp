#include <string>
#include <vector>
#include <cmath>
#include <iostream> 
using namespace std;


int N, M;
int answer = 1e7;

int check(vector<vector<int> > board, vector<vector<int> > target) {
    int res = 0;
    for (int i = 0; i < M; ++i) {
        int flag = 0;
        for (int j = 0; j < N; ++j) {
          flag += (board[j][i] != target[j][i]);
            if (flag != 0 && flag != j + 1) {
              return (-1);
            }
        }
      res += flag / N;
    }
    return res;
}

void change(vector<vector<int> > &board, int index) {
  for (int i = 0; i < M; ++i)
    board[index][i] += pow(-1, board[index][i]);
}

void dfs(vector<vector<int> > board, vector<vector<int> > target, int index, int res) {
    change(board, index);
    int flag = check(board, target);
    if (flag >= 0) {
      answer = min(answer, res + flag);
    }
    for (int i = index + 1; i < N; ++i) {
        dfs(board, target, i, res + 1);
    }
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    N = beginning.size();
    M = beginning[0].size();
    int flag = check(beginning, target);
    if (flag >= 0) {
      answer = min(answer, flag);
    }
    for (int i = 0; i < N; ++i) {
        dfs(beginning, target, i, 1);
    }
    if (answer == 1e7)
        answer = -1;
    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  // vector<vector<int> > a ={{0, 1, 0, 0, 0}, {1, 0, 1, 0, 1}, {0, 1, 1, 1, 0}, {1, 0, 1, 1, 0}, {0, 1, 0, 1, 0}};
  vector<vector<int> > a;
  vector<int> b = {0,0,0,0,1,0,0,0,0,1};
  a.push_back(b);
  a.push_back(b);
  a.push_back(b);
  a.push_back(b);
  a.push_back(b);
  a.push_back(b);
  a.push_back(b);
  a.push_back(b);
  a.push_back(b);
  // a.push_back(b);
  vector<int> k = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
  // a.push_back(b);
  a.push_back(k);
  // vector<vector<int> > c = {{0, 0, 0, 1, 1}, {0, 0, 0, 0, 1}, {0, 0, 1, 0, 1}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 1}};
  vector<vector<int>  >c;
  vector<int> t = {0,0,0,0,0,0,0,0,0,0};

  c.push_back(t);
  c.push_back(t);
  c.push_back(t);
  c.push_back(t);
  c.push_back(t);
  c.push_back(t);
  c.push_back(t);
  c.push_back(t);
  c.push_back(t);
  c.push_back(t);
  c.push_back(t);
  int sol = solution(a, a);
  cout << sol << endl;
}


/*
{0, 1, 0, 0, 0}, {1, 0, 1, 0, 1}, {0, 1, 1, 1, 0}, {1, 0, 1, 1, 0}, {0, 1, 0, 1, 0}}	{0, 0, 0, 1, 1}, {0, 0, 0, 0, 1}, {0, 0, 1, 0, 1}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 1}}

*/
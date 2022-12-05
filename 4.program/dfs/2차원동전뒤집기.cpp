#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

// n개 뽑기


int N, M;
int answer = 1e7;


void change(int index, vector<vector<int> > &beginning) {
  for (int i = 0; i < M; ++i) {
    beginning[index][i] = beginning[index][i] == 1 ? 0 : 1;
  }
}

int one_column(int index, vector<vector<int> > beginning, vector<vector<int> > target) {
  int flag = 0;
  for(int i = 0; i < N; ++i) {
    flag += (beginning[i][index] == target[i][index]);
  }
  if (flag == N)
    return 1;
  else if (flag == 0)
    return 2;
  else
    return 0;
}

int cnt_column(vector<vector<int> > beginning, vector<vector<int> > target) {
  int res = 0;
  for (int i = 0; i < M; ++i) {
    int temp = one_column(i, beginning, target);
    if (temp == 2)
      ++res;
    else if (temp == 0)
      return -1;
  }
  return res;
}


void dfs(int index, int cnt, vector<vector<int> > beginning, vector<vector<int>> target) {
  change(index, beginning);
  int res = cnt_column(beginning, target);
  if (res >= 0) {
    answer = min(answer, cnt + res);
    return ;
  }
  for (int i = index + 1; i < N; ++i) {
    dfs(i, cnt + 1, beginning, target);
  }
}


int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    N = beginning.size();
    M = beginning[0].size();
    for (int i = 0; i < N; ++i) {
      dfs(i, 1, beginning, target);
    }
    if (cnt_column(beginning, target) == 0)
      return 0;
    if (answer == 1e7)
      return -1;
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
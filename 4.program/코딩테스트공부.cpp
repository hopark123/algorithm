#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int> > dp;

int solution(int alp, int cop, vector<vector<int> > problems) {
    int answer = 0;
    int max_alp = alp;
    int max_cop = cop;

    for(auto &pb : problems) {
      max_alp = max(max_alp, pb[0]);
      max_cop = max(max_cop, pb[1]);
    }
  dp.resize(max_alp + 1, vector<int>(max_cop + 1, max_alp * max_cop));
  dp[alp][cop] = 0;

  for (int i = alp; i <= max_alp; ++i) {
    for (int j = cop; j <= max_cop; ++j) {
      if (i < max_alp)
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
      if (j < max_cop)
        dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
      for (auto &pb : problems) {
        if (pb[0] > i || pb[1] > j) continue;
        int next_alp = min(max_alp, i + pb[2]);
        int next_cop = min(max_cop, j + pb[3]);
        dp[next_alp][next_cop] = min(dp[i][j] + pb[4], dp[next_alp][next_cop]);
      }
    }
  }
  answer = dp[max_alp][max_cop];
  return answer;
}

int main() {
  vector<vector<int> > a;
  vector<int> b;
  b.push_back(10);
  b.push_back(15);
  b.push_back(2);
  b.push_back(1);
  b.push_back(2);
  a.push_back(b);
  b.clear();
  b.push_back(20);
  b.push_back(20);
  b.push_back(3);
  b.push_back(3);
  b.push_back(4);
  a.push_back(b);

  int sol = solution(10, 10, a);
  cout << sol << endl;
}


/*
alp	cop	problems	result
10	10	[[10,15,2,1,2],[20,20,3,3,4]]	15
0	0	[[0,0,2,1,2],[4,5,3,1,2],[4,11,4,0,2],[10,4,0,4,2]]	13
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int> > dp;
int N;
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    N = triangle.size();
    dp.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            dp[i][j] = triangle[i][j];
        }
    }
    for (int i = 1; i < N; ++i) {
        dp[i][0] += dp[i - 1][0];
        for (int j = 1; j <= i; ++j) {
            dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }
    for (int i = 0; i < N; ++i) {
        answer = max(answer, dp[N - 1][i]);
    }
    
    return answer;
}
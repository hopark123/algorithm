#include <iostream>
#include <cmath>
#include <limits.h>
#include <vector>

using namespace std;

int		N;


int main() {
	cin >> N;
	vector<int> dp(N + 1, 0);
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		int		_min = INT_MAX;
		for (int j = 1; j <= sqrt(i); j++) {
			int temp = i - j * j;
			_min = min(_min, dp[temp]);
		}
		dp[i] = _min + 1;
	}
	cout << dp[N];
}
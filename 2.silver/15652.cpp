#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;


int		N, M;
int		arr[10];
int		dp[10];

void	dfs(int index, int cnt) {
	if (cnt == M) {
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j < dp[i]; j++)
				cout << i + 1 << " ";
		}
			cout << "\n";
		return ;
	}
	for (int i = index; i < N; i++) {
		if (dp[i] > M)
			continue ;
		dp[i]++;
		dfs(i, cnt + 1);
		dp[i]--;
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		dp[i]++;
		dfs(i, 1);
		dp[i]--;
	}
	return (0);
}
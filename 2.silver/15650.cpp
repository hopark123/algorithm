#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int		N, M;
int		arr[10];
int		dp[10];

void	dfs(int index, int cnt) {
	if (cnt == M) {
		for (int i = 0; i <= N; i++) {
			if (dp[i])
				cout << i + 1 << " ";
		}
		cout << "\n";
		return ;
	}
	for (int i = index + 1; i < N; i++) {
		dp[i] = 1;
		dfs(i, cnt + 1);
		dp[i] = 0;
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		dfs(i, 1);
		dp[i] = 0;	
	}
	return (0);
}
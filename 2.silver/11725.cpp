#include <iostream>
#include <vector>

using namespace std;
vector<int>		_vec[100005];
int		N;
int			res[100005];
vector<int> dp(100005, 0);


void	dfs(int st) {
	for (int i = 0; i < _vec[st].size(); i++) {
		if (dp[_vec[st][i]] != 1) {
			dp[_vec[st][i]] = 1;
			res[_vec[st][i]] = st;
			dfs(_vec[st][i]);
			dp[_vec[st][i]] = 0;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b; cin >> a >> b;
		_vec[a].push_back(b);
		_vec[b].push_back(a);
	}
	dp[1] = 1;
	dfs(1);

	for (int i = 2; i <= N; i++) {
		cout << res[i] << "\n";
	}
}
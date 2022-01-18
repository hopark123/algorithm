#include <iostream>
#include <vector>

using namespace std;

int				N, M;
vector<int>		vec[101];
int				dp[101];

void		dfs(int now) {
	for (int i = 0; i < vec[now].size(); i++) {
		if (!dp[vec[now][i]]) {
			dp[vec[now][i]] = 1;
			dfs(vec[now][i]);
		}
	}
}


int main() {
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	while (M--) {
		int		a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	int cnt = 0;
	dp[1] = 1;
	dfs(1);
	for (int i = 1; i < N; i++)
		if (dp[i + 1])
			cnt++;
	cout << cnt;
}
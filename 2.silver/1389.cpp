#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define _MAX 100000000

vector<int>	arr[101];
int			res[101][101];
int			N, M, ans, _min = _MAX;



void	bfs(int st) {
	int dp[101] = {0,};
	queue<int> q;

	q.push(st);
	dp[st] = 1;
	while (!q.empty()) {
		int	temp = q.front(); q.pop();
		for (int i = 0; i < arr[temp].size(); i++) {
			int		next = arr[temp][i];
			if (dp[next] == 0) {
				dp[next] = 1;
				q.push(next);
				res[st][next] = res[st][temp] + 1;
				res[next][st] = res[st][temp] + 1;
			}
		}
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	while (M--) {
		int	a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
		bfs(i);
	for (int i = 1; i <= N; i++) {
		int temp = 0;
		for (int j = 1; j <= N; j++)
			temp += res[i][j];
		if (temp < _min)
		{
			_min = temp;
			ans = i;
		}
	}
	cout << ans;
}
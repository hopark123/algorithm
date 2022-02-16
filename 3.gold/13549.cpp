#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF	1000000000

int		N, K;

void	dfs() {
	priority_queue<pair<int, int> >		q;
	int step = 0;
	q.push(make_pair(0, N));
	vector<int> dp(200005, INF);
	dp[N] = 1;
	while (!q.empty()) {
		int next = q.top().second;
		step = -q.top().first;  q.pop();
		if (next == K) {
			cout << step;
			return ;
		}
		if (next >= 1 && dp[next - 1] > step) {
			q.push(make_pair(-(step + 1), next - 1));
			dp[next - 1] = step + 1;
		}
		if (2 * next <= 200005 && dp[2 * next] > step) {
			q.push(make_pair(-(step), 2 * next));
			dp[2 * next] = step;
		}
		if (dp[next + 1] > step) {
			q.push(make_pair(-(step + 1), next + 1));
			dp[next + 1] = step + 1;
		}
	}
}
int main() {
	cin >> N >> K;
	if (N == K) {
		cout << "0\n";
		return (0);
	}
	dfs();
}
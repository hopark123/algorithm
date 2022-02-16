#include <iostream>
#include <queue>

using namespace std;

int			arr[105][105];
int			N;


void		bfs(int st) {
	int		dp[105] = {0,};
	queue<int> q;
	for (int i = 0; i < N; i++)
		if (arr[st][i] == 1)
			q.push(i);
	while (!q.empty()) {
		int next = q.front(); q.pop();
		dp[next] = 1;
		arr[st][next] = 1;
		for (int i = 0; i < N; i++) {
			if (arr[next][i] == 1&& dp[i] == 0) {
				q.push(i);
			}
		}
	}
}
int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	for (int i = 0; i < N; i++)
		bfs(i);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
}
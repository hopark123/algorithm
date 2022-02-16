#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

int		arr[102];
int		N, M;
int		ans[102];


void	bfs() {
	queue<int> q;
	ans[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int temp = q.front(); q.pop();
		for (int i = 1; i <= 6; i++) {
			int next = temp + i;
			if (next > 100)	continue;
			next = arr[next];
			if (ans[next] == 0) {
				ans[next] = ans[temp] + 1;
				q.push(next);
			}
		}
	}
}
int main() {
	cin >> N >> M;
	int	a, b;
	for (int i = 1; i <= 100; i++)
		arr[i] = i;
	while (N--) {
		cin >> a >> b;
		arr[a] = b;
	}
	while (M--) {
		cin >> a >> b;
		arr[a] = b;
	}
	bfs();
	cout << ans[100] - 1;

}
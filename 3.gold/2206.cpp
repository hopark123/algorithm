#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
#define INF		100000000
int		N, M;
// string		arr[1005];
int			arr[1005][1005];

typedef	struct	s_info {
	int y, x, step;
	bool skill;
}	t_info;

int safe(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M)
		return (0);
	if (arr[y][x] == 1)
		return (2);
	return (1);
}


void		bfs(void) {
	queue<t_info> q;
	int		dy[4] = {-1, 1, 0, 0};
	int		dx[4] = {0, 0, -1, 1};
	int		dp[N][M][2]; for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {dp[i][j][0] = INF; dp[i][j][1] = INF;}
	int		step = 0;

	t_info		temp;
	temp.y = 0; temp.x = 0; temp.skill = true; temp.step = 1;
	q.push(temp);
	while (!q.empty()) {
		temp = q.front(); q.pop();
		if (temp.y == N - 1 && temp.x == M - 1) {
			cout << temp.step << "\n";
			return ;
		}
		for (int i = 0; i < 4; i++) {
			t_info	next;
			next.y = temp.y + dy[i];
			next.x = temp.x + dx[i];
			next.skill = temp.skill;
			next.step = temp.step + 1;
			if (safe(next.y, next.x) == 0)
				continue ;
			if (next.skill) {
				if (safe(next.y, next.x) == 2 && dp[next.y][next.x][1] > next.step) {
					next.skill = false;
					dp[next.y][next.x][1] = next.step;
				}
				else if (dp[next.y][next.x][0] <= next.step)
					continue ;
				dp[next.y][next.x][0] = next.step;
			}
			else {
				if (safe(next.y, next.x) == 2 || dp[next.y][next.x][1] <= next.step || dp[next.y][next.x][0] <= next.step)
					continue ;
				dp[next.y][next.x][1] = next.step;
			}
			q.push(next);
		}
	}
	cout << "-1\n";
}

int main() {

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	// cin >> N >> M;
	// for (int i = 0; i < N; i++)
		// cin >> arr[i];
	bfs();
}
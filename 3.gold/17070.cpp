#include <iostream>
using namespace std;

int		arr[16][16];
int		dp[16][16];
int		N;
int		res;


int		d[3][2] = {{0, 1}, {1, 0}, {1, 1}}; // 0 1 2

bool	safe(int y, int x, int dir) {
	if (!(y >= 0 && y < N && x >= 0 && x < N && arr[y][x] != 1))
		return (false);
	if (dir == 2 && (arr[y - 1][x] == 1 || arr[y][x - 1] == 1))
		return (false);
	return (true);
}

void	dfs(int y, int x, int dir) {
	if (y == N - 1 && x == N -1) {
		res++;
		return ;
	}
	for (int i = 0; i < 3; i++) {
		if (dir == 0 && i == 1)		continue ;
		if (dir == 1 && i == 0)		continue ;
		int ty = y + d[i][0];
		int tx = x + d[i][1];
		if (safe(ty, tx, i) && dp[ty][tx] == 0) {
			dp[ty][tx] = 1;
			dfs(ty, tx, i);
			dp[ty][tx] = 0;
		}
	}
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	dfs(0, 1, 0);
	cout << res << "\n";
}
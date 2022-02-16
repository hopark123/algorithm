#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int		N, M, _max;
int		arr[505][505];
int		visited[505][505];
int		dy[4] = {-1, 1, 0, 0};
int		dx[4] = {0, 0, -1, 1};

typedef struct s_info {
	int y;
	int x;
	int cnt;
	int	sum;
}		t_info;

bool safe(int y, int x) {
	return (y >= 0 && y < N && x >= 0 && x < M);
}

void	fuckshape(int y, int x) {
	if (safe(y, x + 2) && safe(y - 1, x + 1)) // ㅗ
		_max = max(_max, arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y - 1][x + 1]);
	if (safe(y + 2, x) && safe(y + 1, x + 1)) // ㅏ
		_max = max(_max, arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 1][x + 1]);
	if (safe(y + 2, x) && safe(y + 1, x - 1)) // ㅓ
		_max = max(_max, arr[y][x] + arr[y + 1][x] + arr[y + 1][x - 1] + arr[y + 2][x]);
	if (safe(y, x + 2) && safe(y + 1, x + 1))//ㅜ
		_max = max(_max, arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y + 1][x + 1]);
}


void	dfs(int y, int x, int cnt, int sum) {
	if (cnt == 4) {
		_max = max(_max, sum);
		return ;
	}
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];
		if (safe(ty, tx) && visited[ty][tx] != 1) {
			visited[ty][tx] = 1;
			dfs(ty, tx, cnt + 1, sum + arr[ty][tx]);
			visited[ty][tx] = 0;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 1;
			dfs(i, j, 1, arr[i][j]);
			visited[i][j] = 0;
			fuckshape(i, j);
		}
	}
	cout << _max <<"\n";

}
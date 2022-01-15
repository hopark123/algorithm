#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef	struct s_game {
	int	rx, ry, bx, by, cnt;
}	t_game;
char	arr[11][11];
int		N, M;


t_game	start;

int		dfs(void) {
	int				visit[10][10][10][10] = {0, };
	queue<t_game>	que;
	t_game			game;
	int				res = -1;
	int	dy[4] = {0, 0, -1, 1};
	int dx[4] = {-1, 1, 0, 0};
	que.push(start);
	visit[start.ry][start.rx][start.bx][start.by] = 1;
	while (!que.empty()) {

		game = que.front(), que.pop();
		if (game.cnt > 10) break ;
		if (arr[game.rx][game.ry] == 'O' && arr[game.bx][game.by] != 'O') {
			res = game.cnt;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int		next_rx = game.rx;
			int		next_ry = game.ry;
			int		next_bx = game.bx;
			int		next_by = game.by;

			while (1) {
				if (arr[next_rx][next_ry] != '#' && arr[next_rx][next_ry] != 'O') {
					next_rx += dx[i], next_ry += dy[i];
				}
				else {
					if (arr[next_rx][next_ry] == '#')
						next_rx -= dx[i], next_ry -= dy[i];
					break ;
				}
			}
			while (1) {
				if (arr[next_bx][next_by] != '#' && arr[next_bx][next_by] != 'O') {
					next_bx += dx[i], next_by += dy[i];
				}
				else {
					if (arr[next_bx][next_by] == '#')
						next_bx -= dx[i], next_by -= dy[i];
					break ;
				}
			}
			if (next_rx == next_bx && next_ry == next_by) {
				if (arr[next_rx][next_ry] != 'O') {
					int disR = abs(next_rx - game.rx) + abs(next_ry - game.ry);
					int disB = abs(next_bx - game.bx) + abs(next_by - game.by);
					if (disR > disB) {
						next_rx -= dx[i], next_ry -= dy[i];
					}
					else {
						next_bx -= dx[i], next_by -= dy[i];
					}

				}
			}
			if (visit[next_ry][next_rx][next_by][next_bx] == 0) {
				visit[next_ry][next_rx][next_by][next_bx] = 1;
				t_game nex;
				nex.ry = next_ry;
				nex.rx = next_rx;
				nex.by = next_by;
				nex.bx = next_bx;
				nex.cnt = game.cnt + 1;
				que.push(nex);
			}
			
		}
		
	}
	return (res);
}

int main()
{
	ios::sync_with_stdio(false);

	char	temp[11];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'R') {
				start.rx = i, start.ry = j;
			}
			if (arr[i][j] == 'B') {
				start.bx = i, start.by = j;
			}
		}
	}
	start.cnt = 0;
	cout << dfs() << endl;
}

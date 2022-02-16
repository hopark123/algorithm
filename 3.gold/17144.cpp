#include <iostream>

using namespace std;

int		arr[51][51];
int		push[51][51];
int		R, C, T;

bool safe(int y, int x) {
	return (y >= 0 && y < R && x >= 0 && x < C);
}

void	dust(int y, int x) {
	int		cnt = 0;
	int		mount = arr[y][x] / 5;
	int		dy[4] = {-1, 1, 0, 0};
	int		dx[4] = {0, 0, -1, 1};
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];
		if (safe(ty, tx) && arr[ty][tx] != -1) {
			push[ty][tx] += mount;
			cnt++;
		}
	}
	arr[y][x] -= cnt * mount;
}

class	Air {
	public :
		Air() : _y(0), _x(0), _time(0) {}
	void	set_pos(int y, int x) { _y = y; _x = x;}
	void	clean(void) {
		int ty = _y; int tx = _x;
		for (int i = _y - 3; i >= 0; i--) 
			arr[i + 1][0] = arr[i][0];
		for (int i = 1; i < C ; i++)
			arr[0][i - 1] = arr[0][i];
		for (int i = 1; i <= _y - 1; i++)
			arr[i - 1][C - 1] = arr[i][C - 1];
		for (int i = _y + 1 ; i < R - 1 ; i++)
			arr[i][0] = arr[i + 1][0];
		for (int i = 1; i < C; i++)
			arr[R - 1][i - 1] = arr[R - 1][i];
		for (int i = R - 1; i > _y ; i--)
			arr[i][C - 1] = arr[i - 1][C - 1];
		for (int i = C - 1; i > 1; i--) {
			arr[_y - 1][i] = arr[_y - 1][i - 1];
			arr[_y][i] = arr[_y][i - 1];
		}
		arr[_y - 1][1] = 0;
		arr[_y][1] = 0;

	}
	private :
		int		_y, _x, _time;
};

void		show() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("[%3d]", arr[i][j]);
			// cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int	main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> R >> C >> T;

	Air		air;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				air.set_pos(i, j);
			}
		}
	while (T--) {
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if (arr[i][j] > 0)
					dust(i, j);
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) {
				arr[i][j] += push[i][j];
				push[i][j] = 0;
			}
		air.clean();
	}
	int		res = 0;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (arr[i][j] > 0)
				res += arr[i][j];
	cout << res << "\n";
	return (0);
}
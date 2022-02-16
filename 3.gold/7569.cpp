#include <iostream>
#include <queue>

using namespace std;


int		arr[102][102][102];
int		M, N, H, tom, cnt;


typedef struct s_info {
	int y, x, h, day;
}	t_info;

queue<t_info> q;

bool	in_wall(t_info info) {
	if (info.h >= 0 && info.h < H && info.y >= 0 && info.y < N && info.x >= 0 && info.x < M)
		return (true);
	return (false);
}

void	show() {
	cout << "================\n";
	for (int h = 0; h < H; h++) {
		for(int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << arr[h][i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
}

int		bfs(void) {

	int		res = 0;
	int		cnt = 0;
	int dx[6] = {-1, 1, 0, 0, 0, 0};
	int dy[6] = {0, 0, -1, 1, 0, 0};
	int dh[6] = {0, 0, 0, 0, -1, 1};

	while (!q.empty()) {
		// show();
		if (q.front().day == res) {
			t_info temp;
			temp.h = q.front().h;
			temp.y = q.front().y;
			temp.x = q.front().x; q.pop();
			for (int i = 0; i < 6; i++) {
				t_info next;
				next.h = temp.h + dh[i];
				next.y = temp.y + dy[i];
				next.x = temp.x + dx[i];
				next.day = res + 1;
				if (in_wall(next) && arr[next.h][next.y][next.x] == 0) {
					arr[next.h][next.y][next.x] = 1;
					q.push(next);
					cnt++;
				}
			}
		}
		else
			res++;
	}
	if (cnt == tom)
		return (res);
	return (-1);
}

int main() {
	cin >> M >> N >> H;
	t_info temp;

	for (int h = 0; h < H; h++) {
		for(int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> arr[h][i][j];
				if (arr[h][i][j] == 0)
					tom++;
				if (arr[h][i][j] == 1) {
					temp.y = i;
					temp.x = j;
					temp.h = h;
					temp.day = 0;
					q.push(temp);
				}
			}
		}
	}
	cout << bfs();
}
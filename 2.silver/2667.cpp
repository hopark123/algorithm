#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char	arr[30][30];
int		N;
int		dx[4] = {0, 0, -1, 1};
int		dy[4] = {1, -1, 0, 0};
int		res;
vector<int>		ans;
bool	safe(int y, int x) {
	if (y >= 0 && y < N && x >= 0 && x < N)
		return (true);
	return (false);
}

void		dfs(int y, int x, int num) {
	arr[y][x] = num + '0';
	res++;
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];
		if (arr[ty][tx] == '1' && safe(ty, tx))
		{
			dfs(ty, tx, num);
		}
	}
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int	num = 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == '1') {
				res = 0;
				dfs(i, j, num);
				ans.push_back(res);
				num++;
			}
		}
	}
	cout << ans.size() << "\n";
	sort(ans.begin(), ans.end());
	// for (int i = 0; i < N; i++)
	// 	cout << arr[i] << "\n";

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
	return (0);
}
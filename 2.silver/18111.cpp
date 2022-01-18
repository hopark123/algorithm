#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;


int		N, M, B, res, _max;
int		arr[505][505];

long long	up(int dest) {
	long long res = 0;
	long long cnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] > dest)
			{
				res += 2 * (arr[i][j] - dest);
				cnt -= arr[i][j] - dest;
			}
			else if (arr[i][j] < dest)
			{
				res += dest - arr[i][j];
				cnt += dest - arr[i][j];
			}
		}
	}
	if (cnt > B)
		return (-1);
	return (res);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> B;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			_max = max(_max, arr[i][j]);
		}
	long long res = 2100000000;
	long long		dest;
	int height = 256;
	while (height >= 0) {
		long long now;
		now = up(height);
		if (now != -1)
		{
			if (res > now)
			{
				res = now;
				dest = height;
			}
		}
		height--;
	}
	cout << res << " " << dest;
}

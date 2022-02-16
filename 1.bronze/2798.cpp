#include <iostream>
#include <algorithm>

using namespace std;


int		N, M, res;
int		arr[2][105];

void	dfs(int index, int cnt, int sum) {
	if (cnt >= 3) 
	{
		if (sum > M)
			return ;
		res = max(res, sum);
		return ;
	}
	for (int i = index; i < N; i++) {
		if (arr[1][i] != 1)
		{
			arr[1][i] = 1;
			sum += arr[0][i];
			dfs(i + 1, cnt + 1, sum);
			arr[1][i] = 0;
			sum -= arr[0][i];
		}
	}
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[0][i];
	dfs(0, 0, 0);
	cout << res;

}
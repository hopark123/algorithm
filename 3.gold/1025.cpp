#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int	N, M;
char	arr[10][10];
int		dp[320000];
vector<int> vec;


bool	is_squre(int N)
{
	if ((int)sqrt(N) * (int)sqrt(N) == N)
		return (true);
	return (false);
}

void		find(int i, int j, int di, int dj, int num)
{
	if (is_squre(num))
		vec.push_back(num);
	if (di == 0 && dj == 0)
		return ;
	if (i + di >= N || j + dj >= M || i + di < 0 || j + dj < 0)
		return ;
	num = num * 10 + arr[i + di][j + dj] - '0';
	find (i + di, j + dj, di, dj , num);
	return ;
}

void	insert_d(int i, int j)
{
	for (int di = 0; i + di < N; di++)
	{
		for (int dj = 0; j + dj < M; dj++)
			find(i, j, di, dj, arr[i][j] - '0');
		for (int dj = 0; j + dj >= 0; dj--)
			find(i, j, di, dj, arr[i][j] - '0');
	}
	for (int di = 0; i + di >= 0; di--)
	{
		for (int dj = 0; j + dj < M; dj++)
			find(i, j, di, dj, arr[i][j] - '0');
		for (int dj = 0;  j + dj >= 0; dj--)
			find(i, j, di, dj, arr[i][j] - '0');
	}
	return ;
}

int main()
{
	int	res = -1;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			insert_d(i,j);
	}
	while (!vec.empty())
	{
		res = max(res, vec.back());
		vec.pop_back();
	}
	cout << res << endl;
}

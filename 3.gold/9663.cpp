#include <iostream>


using namespace std;

int			N, res;
char		arr[15][15];
char		dxy[4][2] = {
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0},
};

void	reset_arr(char	arr[][15])
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			arr[i][j] = ' ';
}

bool	is_safe(int y, int x, char arr[][15])
{
	for (int i = 1; i <= y; i++)
		if (arr[y - i][x] == '1')
		{
			return (false);
		}
	for (int i = 1; i <= y && i <= x; i++)
		if (arr[y - i][x - i] == '1')
		{
			return (false);
		}
	for (int i = 1; i <= y && i + x < N; i++)
		if (arr[y - i][x + i] == '1')
			return (false);
	return (true);
}

bool	safe_wall(int y, int x)
{
	if (y >= 0 && x >= 0 && y < N && x < N)
		return (true);
	return (false);
}

void	print(void)
{
	for (int i = 0 ; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout <<"[" << arr[i][j] << "]";
		cout << endl;
	}
		cout << endl;
}

void	dfs(int y, char arr[][15])
{
	if (y == N)
	{
		res++;
		cout << "res" << res << endl;
		print();
		return ;
	}
	for (int j = 0; j < N; j++)
	{
		if (safe_wall(y, j) && is_safe(y, j, arr))
		{
			arr[y][j] = '1';
			dfs(y + 1, arr);
			arr[y][j] = ' ';
		}
	}
	return ;
}

int main()
{
	cin >> N;
	for (int j = 0; j < N; j++)
	{
		reset_arr(arr);
		arr[0][j] = '1';
		dfs(0, arr);
	}
	cout << res << endl;
}
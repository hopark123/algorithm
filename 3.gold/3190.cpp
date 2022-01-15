#include <iostream>
#include <queue>

using namespace std;
int		N, K, L;
int		arr[101][101];
int		dy[4] = {0, -1, 0, 1};
int		dx[4] = {1, 0, -1, 0};
queue<pair<int, char> > _move;

bool	is_safe(int y, int x)
{
	if (y < N && x < N && y >= 0 && x >= 0 && arr[y][x] != 2)
		return (true);
	return (false);
}
void	print()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
		cout << endl;
}
int	turn(int d, char dir)
{
	if (dir == 'L')
		d = (d + 1) % 4;
	else if (dir == 'D')
		d = (d + 3) % 4;
	return (d);
}

// 몸을 움직인다 사과면 꼬리 안지움. 사과 아니면꼬리 지움
// 방향을 바꾼다
int		game(int y, int x)
{
	queue<pair<int, int> > snake;
	int time = 1;
	int	d = 0;
	arr[y][x] = 2;
	snake.push(make_pair(y, x));
	while (1)
	{
		y +=  dy[d];
		x +=  dx[d];
		if (!is_safe(y, x))
			break ;
		snake.push(make_pair(y, x));
		if (arr[y][x] != 1)
		{
			arr[snake.front().first][snake.front().second] = 0;
			snake.pop();
		}
		arr[y][x] = 2;
		if (time == _move.front().first)
		{
			d = turn(d, _move.front().second);
			_move.pop();
		}
		time++;
	}
	return (time);
}

int main()
{
	cin >> N >> K;
	while (K--)
	{
		int y, x;
		cin >> y >> x;
		arr[y - 1][x - 1] = 1;
	}
	cin >> L;
	while (L--)
	{
		int		t;
		char	dir;
		cin >> t >> dir;
		_move.push(make_pair(t, dir));
	}
	cout << game(0,0);
}
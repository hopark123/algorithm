#include <iostream>

using namespace std;
int		N, M, r, c, d;
int		arr[55][55];
int		dy[4] = {-1, 0, 1, 0};
int		dx[4] = {0, 1, 0, -1};

void	print(void) {
	for (int i = 0 ; i < N; i++)
	{
		for (int k = 0; k < M; k++)
			cout << arr[i][k] << " ";
		cout << endl;
	}
	cout << endl;
}
class	Robot {
private :
	int		_r;
	int		_c;
	int		_d;
	int		_res;
public :
	Robot(int r, int c, int d) : _r(r), _c(c), _d(d), _res(0){}

	void	rotate(void) {
		this->_d = (_d + 3) % 4;
	}

	int		clean(void) {
		if (arr[_r][_c] == 0) {
			arr[_r][_c] = 2;
			_res++;
			return (0);
		}
		else {
			for (int i = 1; i <= 4; i++) {
				rotate();
				int y = _r + dy[_d];
				int x = _c + dx[_d];
				if (arr[y][x] == 0) {
					_r = y;
					_c = x;
					arr[y][x] = 2;
					_res++;
					return (1);
				}
			}
			return (2);
		}
	}
	bool		back(void) {
		int y = _r - dy[_d];
		int x = _c - dx[_d];
		if (arr[y][x] != 1) {
			_r = y;
			_c = x;
			return (true);
		}
		return (false);
	}
	int			getRes(void) {
		return (this->_res);
	}
};

int main()
{
	ios::sync_with_stdio(false);

	cin >> N >> M;
	cin >> r >> c >> d;
	Robot robot(r, c, d);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	while (1) {
		if (robot.clean() == 2)
			if (!robot.back())
			{
				cout << robot.getRes();
				return (0);
			}
	}
}

// #include <iostream>
// #include <math.h>

// using namespace std;

// typedef struct s_robot 
// {
// 	int r;
// 	int c;
// 	int d; // 0=West | 1=East | 2=North, 3=South
// }	t_robot;

// int			N, M , r, c, d;
// int			arr[52][52];
// t_robot		robot;


// void		print(void)
// {
// 	for (int i = 0; i < N; i++)
// 	{
// 		for (int j = 0; j < M; j++)
// 			cout << arr[i][j] << " ";
// 		cout << endl;
// 	}
// }
// void		rotate(void)
// {
// 	robot.d = (robot.d + 3) % 4;
// }

// int		doclean(void)
// {
// 	int	y = robot.r;
// 	int	x = robot.c;
// 	if (arr[y][x] == 0)
// 	{
// 		arr[y][x] = 2;
// 		return (1);
// 	}
// 	if (robot.d == 1)
// 	{
// 		y = robot.r - 1;
// 		x = robot.c;
// 	}
// 	else if (robot.d == 2)
// 	{
// 		y = robot.r;
// 		x = robot.c + 1;
// 	}
// 	else if (robot.d == 3)
// 	{
// 		y = robot.r + 1;
// 		x = robot.c;
// 	}
// 	else if (robot.d == 0)
// 	{
// 		y = robot.r;
// 		x = robot.c - 1;
// 	}
// 	if (arr[y][x] == 0)
// 	{
// 		robot.r = y;
// 		robot.c = x;
// 		rotate();
// 		arr[y][x] = 2;
// 		return (2);
// 	}
// 	return (0);
// }

// int		back(void)
// {
// 	int		x = 0, y = 0;

// 	if (robot.d == 0)
// 	{
// 		y = robot.r + 1;
// 		x = robot.c;
// 	}
// 	else if (robot.d == 1)
// 	{
// 		y = robot.r;
// 		x = robot.c - 1;
// 	}
// 	else if (robot.d == 2)
// 	{
// 		y = robot.r - 1;
// 		x = robot.c;
// 	}
// 	else if (robot.d == 3)
// 	{
// 		y = robot.r;
// 		x = robot.c + 1;
// 	}
// 	if (arr[y][x] != 1)
// 	{
// 		robot.r = y;
// 		robot.c = x;
// 		return (1);
// 	}
// 	return (0);
// }



// int			doing(void)
// {
// 	int		res = 0;
// 	int		flag = 1;
// 	int		i;
	
// 	while (flag)
// 	{
// 		flag = 1;
// 		for (i = 0 ; i < 4; i++)
// 		{
// 			if (doclean())
// 			{
// 				res++;
// 				break ;
// 			}
// 			else
// 				rotate();
// 		}
// 		if (i == 4)
// 			flag = back();
// 	}
// 	return (res);
// }

// int main()
// {
// 	ios::sync_with_stdio(false);

// 	cin >> N >> M;
// 	cin >> robot.r >> robot.c >> robot.d;
// 	for (int i = 0; i < N; i++)
// 		for (int j = 0; j < M; j++)
// 			cin >> arr[i][j];
// 	cout << doing();
// }
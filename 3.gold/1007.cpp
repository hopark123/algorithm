#include <iostream>
#include <limits.h>
#include <math.h>

using namespace std;

int		T,N;
long long	arr[22][3];
double	res;

void	ft_find(int cnt, int index)
{
	if (cnt == N / 2)
	{
		double x = 0;
		double y = 0;
		for (int i = 0; i < N; i++)
		{
			x += arr[i][0] * arr[i][2];
			y += arr[i][1] * arr[i][2];
		}
		res = min(res , sqrt(x * x + y * y));
		return ;
	}
	if (index == N)	return ;
	ft_find(cnt, index + 1);
	arr[index][2] = 1;
	ft_find(cnt + 1, index + 1);
	arr[index][2] = -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		res = numeric_limits<double>::max();
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i][0] >> arr[i][1];
			arr[i][2] = -1;
		}
		ft_find(0, 0);
		printf("%.6lf\n", res);
	}
}
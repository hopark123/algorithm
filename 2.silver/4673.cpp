#include <iostream>

using namespace std;

int	dp[1000005];

int		cal(int N)
{
	int		res = N;
	
	while (N)
	{
		res += N % 10;
		N /= 10;
	}
	return (res);
}
void	ft_dp(int N, int past)
{
	if (dp[N] || N > 10000)
		return ;
	else
	{
		if (past != 0)
			dp[N] = past;
		int	next = cal(N);
		if (next == N)
			return ;
		return (ft_dp(next, N));
	}
}

int main()
{

	for (int i = 1; i < 10000; i++)
		ft_dp(i, 0);
	for (int i = 1; i < 10000; i++)
	{
		if (!dp[i])
			cout << i << endl;
	}
}
	#include <iostream>
	#include <math.h>

	using namespace std;

	int		N, K, W, V;
	long long	arr[103][2];
	long long	dp[101][100005];

	void	answer(void)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= K; j++)
			{
				if (j - arr[i][0] >= 0)
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i][0]] + arr[i][1]);
				else
					dp[i][j] = dp[i - 1][j];
			}

		}
	}
	int main()
	{
		ios::sync_with_stdio(false);
		cin >> N >> K;
		for (int i = 1; i <= N; i++)
			cin >> arr[i][0] >> arr[i][1];
		answer();
		cout << dp[N][K];
	}
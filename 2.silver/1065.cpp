#include <iostream>

using namespace std;

int		N;
int		d[1005];

bool	is_hansu(int N)
{
	int		temp = 0;
	int		next = 0;

	if (N < 100)
		return (true);
	temp = (N / 10) % 10 - N % 10;
	while (N >= 10)
	{
		next = (N / 10) % 10 - N % 10;
		if (temp != next)
			return (false);
		N /= 10;
		temp = next;
	}
	return (true);
}

int	dp(int N)
{
	if (d[N])
		return (d[N]);
	else
		return (d[N] = dp(N - 1) + is_hansu(N));
}

int main()
{
	d[1] = 1;
	cin >> N;
	cout << dp(N);
}
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

char	A[1005], B[1005];
int		dp[1005][1005];
size_t		i, j;
int		_max;

int main()
{
	scanf("%s %s", A + 1, B + 1);
	for (i = 1; i <= strlen(A + 1); i++)
	{
		for (j = 1; j <= strlen(B + 1); j++)
		{
			dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] + (A[i] == B[j]));
			_max = max(_max, dp[i][j]);
		}
	}
	printf("%d", _max);
	return 0;
}
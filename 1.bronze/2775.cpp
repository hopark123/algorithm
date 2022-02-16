#include <iostream>

using namespace std;

int		d[15][15];


int		dp(int k, int n) {
	if (d[k][n])
		return (d[k][n]);
	int	res = 0;
	for (int i = 1; i <= n; i++)
		res += dp(k - 1, i);
	d[k][n] = res;
	return (res);
}
int main()
{
	int		T, k, n;
	for (int i = 1; i <= 15; i++)
		d[0][i] = i;
	cin >> T;
	while (T--) {
		cin >> k >> n;
		dp(k, n);
		cout << d[k][n] << "\n";
	}
}
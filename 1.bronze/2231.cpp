#include <iostream>
#include <algorithm>

using namespace std;

int d[1000005];
int		N;


int		cal(int n) {
	int res = n;
	while (n) {
		res += n % 10;
		n /= 10;
	}
	return (res);
}
void	dp(int n) {
	if (d[cal(n)] == 0)
		d[cal(n)] = n;
}
int main() {
	cin >> N;
	for (int i = 0; i <= N; i++)
		dp(i);
	cout << d[N];
}
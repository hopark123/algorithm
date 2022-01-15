#include <iostream>

using namespace std;



int		d[1000005];
long long	N, M;


void	dp(int n) {
	if (d[n] == -1)
		return ;
	for (int i = 2; i * n <= M; i++)
		d[i * n] = -1;
}

int main() {


	cin >> N >> M;
	d[1] = -1;
	for (int i = 2; i <= M; i++)
		dp(i);
	for (int i = N; i <= M; i++)
		if (d[i] != -1)
			cout << i << "\n";
}
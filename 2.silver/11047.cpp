#include <iostream>
using namespace std;

int	arr[11];
int	ans;

// int		cnt(int K, int money) {
// 	int		res = 0;
// 	while (K >= money) {
// 		K -= money;
// 		res++;
// 	}
// 	return (res);
// }

int main() {

	long long	N, K;
	
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	ans = 0;
	for (int i = N - 1; i >= 0; i--){
		ans += K / arr[i];
		K = K % arr[i];
	}
	cout << ans ;
}
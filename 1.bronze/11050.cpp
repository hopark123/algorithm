#include <iostream>

using namespace std;

int main() {
	int N, K;
	long long res = 1;
	cin >> N >> K ;
	for (int i = N - K + 1; i <= N; i++)
		res *= i;
	for (int i = 1; i <= K; i++)
		res /= i;
	cout << res;
}

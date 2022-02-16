#include <iostream>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
	int		T; cin >> T;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(T--) {
		int		M, N; cin >> M >> N;
		int		x, y; cin >> x >> y;
		int		i = 0;
		int		max = lcm(M,N);
		for (i = x; i <= max; i += M) {
			// cout << i  << " " << i % N << endl;
			if (i % N == y || (y == N && i % N == 0)) {
				cout << i <<"\n";
				break ;
			}
		}
		if (i > max)
			cout << "-1\n";
	}
}
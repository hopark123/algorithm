#include <iostream>

using namespace std;

int main() {
	int		T;
	cin >> T;
	while (T--) {
		int		H, W, N, i , j;
		int	res = 0;
		cin >> H >> W >> N;
		for (j = 1; j <= W; j++) {
			for (i = 1; i <= H; i++) {
				if (++res == N)
					cout << 100 * i + j << endl;
			}
		}

	}
}
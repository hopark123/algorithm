#include <iostream>

using namespace std;

int		N, M;
int		arr[1030][1030];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int temp; cin >> temp;
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + temp;
		}
	}
	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		cout << arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1] << "\n";
		// cout << arr[x2][y2] << " " << arr[x1 - 1][y2] << " " <<  arr[x2][y1 - 1] << " " << arr[x1 - 1][y1 - 1] << "\n";

	}
}
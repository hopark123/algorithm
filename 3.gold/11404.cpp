#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define	INF		1000000000
int		n, m;
// vector<pair<int, int> > _vec[105];
int		arr[105][105];

void		floyd(void) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				arr[j][k] = min(arr[j][i] + arr[i][k], arr[j][k]);

}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = INF;
			if (i == j)
				arr[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++){
		int a, b, c; cin >> a >> b >> c;
		arr[a][b] = min(arr[a][b], c);
	}
	floyd();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == INF)
				cout << "0 ";
			else
				cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
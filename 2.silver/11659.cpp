#include <iostream>
#include <vector>

using namespace std;
int		arr[100005];
int		ans[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int		N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		arr[i] = temp;
		ans[i] = ans[i - 1] + temp;
	}
	while (M--) {
		int a, b;
		long long res = 0;
		cin >> a >> b;
		res = ans[b] - ans[a - 1];
		cout << res << "\n";
	}
}

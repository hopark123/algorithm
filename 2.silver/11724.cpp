#include <iostream>
#include <vector>

using namespace std;

int				dp[1005];
vector<int>		vec[1005];
int				N, M, res;

void		func(int st) {
	for (int i = 0; i < vec[st].size(); i++) {
		if (dp[vec[st][i] + 1] == 0) {
			dp[vec[st][i] + 1] = 1;
			func(vec[st][i]);
		}
	}
}

int main() {
	cin >> N >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		if (dp[i + 1] == 0) {
			dp[i + 1] = 1;
			func(i);
			res ++;
		}
	}
	cout << res;
}
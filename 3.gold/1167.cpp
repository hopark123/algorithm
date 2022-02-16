#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<pair<int, int > > vec[100005];
long long res;
int dp[100005];
int	maxNode;

long long	dis(int st, long long cost){
	if (res < cost) {
		res = cost;
		maxNode = st;
	}
	for (int i = 0; i < vec[st].size(); i++) {
		if (dp[vec[st][i].first] == 0) {
			dp[vec[st][i].first] = 1;
			dis(vec[st][i].first, cost + vec[st][i].second);
			dp[vec[st][i].first] = 0;
		}
	}
	return (res);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int		V; cin >> V;
	for (int i = 0; i < V; i++) {
		int st, de, co;
		cin >> st;
		while (1){
			cin >> de;
			if (de == -1)
				break ;
			cin >> co;
			vec[st].push_back(make_pair(de, co));
		}
	}

	for (int i = 1; i <= V; i++) {
		dp[i] = 0;
	}
	long long ans = 0;
	dp[1] = 1;
	ans = max(ans, dis(1, 0));
	dp[1] = 0;
	dp[maxNode] = 1;
	ans = dis(maxNode, 0);
	cout << ans << "\n";
}
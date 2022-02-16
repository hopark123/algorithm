#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;


int		N, M;
int		arr[10];
int		dp[10];
set<int> _set;
vector<int> _vec;
vector<int> res;

void	dfs(int index, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < (int)res.size(); i++)
				cout << res[i] << " ";
			cout << "\n";
		return ;
	}
	for (int i = 0; i < (int)_vec.size(); i++) {
		if (dp[i] != 0)
			continue ;
		dp[i] = 1;
		res.push_back(_vec[i]);
		dfs(i, cnt + 1);
		res.pop_back();
		dp[i] = 0;
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		int temp; cin >> temp;
		_set.insert(temp);
	}
	for(set<int>::iterator it = _set.begin(); it != _set.end(); it++)
		_vec.push_back(*it);
	sort(_vec.begin(), _vec.end());
	for (int i = 0; i < (int)_vec.size(); i++) {
		dp[i] = 1;
		res.push_back(_vec[i]);
		dfs(i, 1);
		res.pop_back();
		dp[i] = 0;
	}
	return (0);
}
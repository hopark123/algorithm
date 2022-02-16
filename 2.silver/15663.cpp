#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> _vec;
int			dp[10];
set<vector<int> >	_set;
int		N, M;


void		dfs(int cnt, vector<int> res) {
	if (cnt == M) {
		_set.insert(res);
		return ;
	}
	for (int i = 0; i < N; i++) {
		if (dp[i] == 1)
			continue ;
		res.push_back(_vec[i]);
		dp[i] = 1;
		dfs(cnt + 1, res);
		res.pop_back();
		dp[i] = 0;
	}
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		_vec.push_back(temp);
	}
	sort(_vec.begin(), _vec.end());	
	
	vector<int> res;
	dfs(0, res);
	for (set<vector<int> >::iterator it = _set.begin(); it != _set.end(); it++) {
		vector<int> temp = *it;
		for (int i = 0; i < M; i++)
			cout << temp[i] << " ";
		cout << "\n";
	}
}
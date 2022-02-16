#include <iostream>
#include <queue>
using namespace std;

int		left(int A) {
	int res = (A % 1000) * 10 + A / 1000;
	res %= 10000;
	return (res);
}

int		right(int A) {
	int res = (A / 10) + (A % 10) * 1000;
	res %= 10000;
	return (res);
}

int		doubles(int A) {
	int res = (A * 2) % 10000;
	return (res);
}

int		minuss(int A) {
	int res =(A - 1);
	if (res < 0)
		res += 10000;
	return (res);
}

void	bfs(int A, int B) {
	int dp[10002];
	for (int i = 0; i < 10000; i++)
		dp[i] = 0;
	queue<pair<int, string> > q;
	q.push(make_pair(A, ""));
	while (!q.empty()) {
		int		num = q.front().first;
		string	str = q.front().second; q.pop();
		if (num == B) {
			cout << str << "\n";
			break ;
		}
		int		_left = left(num);
		int		_right = right(num);
		int		_double = doubles(num);
		int		_minus = minuss(num);
		if (dp[_left] == 0) {
			dp[_left] = 1;
			q.push(make_pair(_left, str+"L"));
		}
		if (dp[_right] == 0) {
			dp[_right] = 1;
			q.push(make_pair(_right, str+"R"));
		}
		if (dp[_double] == 0) {
			dp[_double] = 1;

			q.push(make_pair(_double, str+"D"));
		}
		if (dp[_minus] == 0) {
			dp[_minus] = 1;
			q.push(make_pair(_minus, str+"S"));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int		T; cin >> T;
	cin.tie(NULL);
	cout.tie(NULL);
	while (T--) {
		int		A, B; cin >> A >> B;
		bfs(A, B);
	}
}
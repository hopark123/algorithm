#include <iostream>
#include <queue>

using namespace std;

int		N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	queue<int> q;
	for (int i = 1; i <= N; i++)
		q.push(i);
	int	num;
	while (!q.empty()) {
		num = q.front();
		q.pop();
		if (q.empty())
			break ;
		num = q.front(); q.pop();
		q.push(num);
	}
	cout << num;
}
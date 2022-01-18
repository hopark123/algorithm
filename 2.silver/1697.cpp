#include <iostream>
#include <queue>

using namespace std;
#define		_MAX 100001

int			N, M;
int		bfs() {
	int	visited[100005] = {0,};
	queue<pair<int, int> > q;
	visited[N] = 1;
	q.push(make_pair(N, 0));
	while (!q.empty()) {
		int index = q.front().first;
		int time = q.front().second;	q.pop();
		if (index == M)	return (time);
		if (index + 1 < _MAX && !visited[index + 1]) {
			visited[index + 1] = 1;
			q.push(make_pair(index + 1, time + 1));
		}
		if (index - 1 >= 0 && !visited[index - 1]) {
			visited[index - 1] = 1;
			q.push(make_pair(index - 1, time + 1));
		}
		if (index * 2 < _MAX && !visited[index * 2]) {
			visited[index * 2] = 1;
			q.push(make_pair(index * 2, time + 1));
		}
	}
}
int main() {
	cin >> N >> M;
	cout << bfs();
}

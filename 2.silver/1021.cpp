#include <iostream>
#include <deque>

using namespace std;

int		N, M, cnt;
int		arr[52];
deque<int> que;


int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		que.push_back(i);
	for (int i = 0; i < M; i++)
		cin >> arr[i];
	for (int m= 0; m < M; m++)
	{
		int left = 0, right = 0;
		for (int i = 0; i < (int)que.size(); i++)
		{
			if (arr[m] == que[i])
			{
				left = i;
				right = que.size() - left;
				break ;
			}
		}
		if (left <= right)
		{
			while (que.front() != arr[m])
			{
				que.push_back(que.front());
				que.pop_front();
				cnt++;
			}
			que.pop_front();
		}
		else
		{
			cnt++;
			while (que.back() != arr[m])
			{
				que.push_front(que.back());
				que.pop_back();
				cnt++;
			}
			que.pop_back();
		}
	}
	cout << cnt << endl;
}
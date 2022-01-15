#include <iostream>
#include <algorithm>

using namespace std;
#define MAX  500005
int		N, M, _min = MAX;
int		button[10];
int		dp[MAX][3];

int		is_can(int channel)
{
	int		cnt = 0;
	int		temp = channel % 10;

	if (channel == 100 && button[1] != -1 && button[0] != -1)
		return (-1);
	while (button[temp] != -1 && channel)
	{
		channel /= 10;
		temp = channel % 10;
		cnt++;
	}
	if (!channel)
		return (cnt);
	return (MAX);
}

int		res(int channel, int before)
{
	int		_min = MAX;

	cout << "start[" << channel << "]" <<endl;
	if (is_can(channel) > before)
	{
		cout << "here" << is_can(channel) << " " << before << endl;
		return (MAX + 1);
	}
	dp[channel][0] = is_can(channel);
	dp[channel][1] = res(channel - 1, is_can(channel) + 1) + 1;
	dp[channel][2] = res(channel + 1, is_can(channel)) - 1;
	_min = min(dp[channel][0], dp[channel][2]);
	if (channel > 0)
		_min = min(_min, dp[channel][1]);
	return (_min);

}

int main() {

	cin >> N >> M;
	while (M--)
	{
		int temp;
		cin >> temp;
		button[temp] = -1;
	}
	// for (int i = 0; i < 10; i++)
	// 	dp[i] = button[i];
	int ans = res(N, MAX + 1);
	if (ans == -1)
		cout << "ans : 0" << endl;
	else
		cout << "ans: "<< ans << endl;
	// for (int i = 0; i < 101; i++)
		// cout << dp[i] << " ";
	return (0);
	// cout << res(100);
}
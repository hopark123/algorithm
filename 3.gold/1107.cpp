#include <iostream>
#include <algorithm>

using namespace std;
#define MAX  1000001
int		N, M, _min = MAX;
int		button[10];

bool		is_can(int channel)
{
	if (channel == 0)
	{
		if (button[0] == -1)
			return (false);
		return (true);
	}
	while (channel)
	{
		if (button[channel % 10] == -1)
			return (false);
		channel /= 10;
	}
	return (true);
}

int		res(int channel)
{
	int		_min = MAX;
	int		From100 = abs(100 - channel);

	for (int i = 0; i < MAX; i++) {
		if (is_can(i)) {
			int temp = to_string(i).length();
			temp += abs(i - channel);
			_min = min(_min, temp);
		}
	}
	return (min(_min, From100));

}

int main() {

	cin >> N >> M;
	while (M--)
	{
		int temp;
		cin >> temp;
		button[temp] = -1;
	}

	cout << res(N);
	return (0);
}
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long 		N,K;
	long long 		arr[10005];
	long long 		cnt = 0;
	long long		_start = 1, _end = 1, _mid;
	ios::sync_with_stdio(false);
	cin >> N >> K;
	for (long long  i = 0; i < N; i++)
	{
		cin >> arr[i];
		_end = max(_end, arr[i]);
	}
	while (1)
	{
		_mid = (_start + _end)/ 2;
		cnt = 0;
		for (long long i = 0; i < N; i++)
			cnt += arr[i] / _mid;
		if (cnt >= K)
			_start = _mid + 1;
		else if (cnt < K)
		{
			_end = _mid - 1;
			_mid = _end;
		}
		if (_start > _end)
			break ;
	}
	cout << _mid;
}
#include <iostream>
#include <math.h>
using namespace std;


long long		_min, _max;
bool			arr[1000003];

int	 main()
{
	ios::sync_with_stdio(false);
	long long		res = 0;

	cin >> _min >> _max;

	for (long long i = 2; i <= sqrt(_max); i++)
	{
		long long	start = _min / (i * i);
		if (start * i * i != _min)
			start++;
		for (long long j = start; j * i * i <= _max; j++)
			arr[(j * i * i) - _min] = true;
	}
	for (long long i = 0; i <= _max - _min; i++)
	{
		if (arr[i] == false)
			res++;
		// cout << "[" << arr[i] << "]";
	}
	cout << res;
}
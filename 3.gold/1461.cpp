#include <iostream>
#include <algorithm>

using namespace std;

int		N, M, res;
int		arr[52];

int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N + 1);
	
	int zero = 0;
	for (int i = 0; i < N + 1; i++)
	{
		if (arr[i] == 0)
		{
			zero = i;
			break ;
		}
	}

	for (int i = 0; i < zero; i += M)
		res -= arr[i] * 2;
	for (int i = N ; i > zero; i-= M)
		res += arr[i] * 2;
	res -= abs(max(abs(arr[0]), abs(arr[N])));
	cout << res << endl;

}
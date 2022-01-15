#include <iostream>

using namespace std;

int main()
{
	char	arr[8][8];
	int		res = 0;
	ios::sync_with_stdio(false);

	for(int i = 0; i < 8; i++)
		cin >> arr[i];

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0 && arr[i][j] == 'F')
				res++;
		}
	}
	cout << res;
}
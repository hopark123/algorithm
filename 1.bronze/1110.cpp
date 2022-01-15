#include <iostream>

using namespace std;

int main()
{
	int		N;
	int		i = 0;
	int		next = 0;
	int		temp = -1;
	ios::sync_with_stdio(false);
	cin >> N;
	next = N;
	while (N != temp)
	{
		i++;
		temp = (next / 10 + next % 10) % 10 + next % 10 * 10;
		next = temp;
	}
	cout << i << endl;
}
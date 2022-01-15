#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int		T, x, y, dis, i;

	ios::sync_with_stdio(false);
	cin >> T;
	while (T--)
	{
		i = 0;
		cin >> x >> y;
		dis = y - x;
		while (i < sqrt(dis))
			i++;
		x = (dis - i * i) / i;
		cout << x + 2 * i - 1 << endl;
	}

}

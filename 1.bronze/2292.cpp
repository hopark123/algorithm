#include <iostream>
#include <cmath>

using namespace std;


int main() {
	int		n;
	int		res = 1;
	int		now = 2;

	cin >> n;
	if (n == 1)
	{
		cout << 1;
		return (0);
	}
	while (now <= n)
		now += 6 * res++;
	cout << res;
}
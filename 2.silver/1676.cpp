#include <iostream>

using namespace std;

int		N;

int main() {
	int res = 0;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int temp = i;
		while (temp && temp % 5 == 0) {
			res++;
			temp /= 5;
		}
	}
	cout << res;
}
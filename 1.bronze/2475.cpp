#include <iostream>

using namespace std;

int main()
{
	int	N;
	int	temp = 0;
	for (int i = 0 ; i < 5; i++)
	{
		cin >> N;
		temp += (N * N) % 10;
	}
	cout << temp % 10 << endl;
}
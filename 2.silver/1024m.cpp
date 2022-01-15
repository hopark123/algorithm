#include <iostream>
#include <math.h>


using namespace std;

void		print(int N, int L, int temp)
{
	if ((2 * N) % L  == 0&& (2 * N) / L % 2 == 1)
	{
	for (int i = 1; i < 2 * temp; i ++)
		cout << N / L - temp + i << " ";
	cout << N / L + temp << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	long long 	N,L,temp;
	
	cin >> N >> L;
	while (N + 1 >= L && L <= 100 && L >= 2 && N > 0 && N <= 1000000000)
	{
		temp = L / 2;
		if (fmod(L, 2)== 0 && fmod((2 * N), L)  == 0 && fmod((2 * N) / L, 2) == 1)
		{
			for (int i = 1; i < 2 * temp; i ++)
				cout << (N / L) - temp + i << " ";
			cout << (N / L) + temp << endl;
			return (0);
		}
		else if (fmod(L, 2) == 1 && !(fmod(N, L)))
		{

			for (int i = 0; i < 2 * temp; i++)
				cout << (N / L) - temp + i << " ";
			cout << (N / L) + temp << endl;
			return (0);
		}
		if (N / L - temp < 0)
			break ;
		L++;
	}
	cout << "-1" << endl;
}
#include <iostream>

using namespace std;

long long	arr[10];
long long	N;

void		add_one(long long N, int digit)
{
	while (N)
	{
		arr[N % 10] += digit;
		N = N / 10;
	}
}

void		cal(long long start, long long end, int digit)
{
	while (start % 10 != 0 && start <= end)
	{
		add_one(start, digit);
		start++;
	}
	if (start > end)
		return ;
	while (end % 10 != 9 && end >= start)
	{
		add_one(end, digit);
		end--;
	}
	long long cnt = (end / 10 - start / 10) + 1;
	for (int i = 0; i < 10; i++)
		arr[i] += cnt * digit;
	cal(start / 10, end / 10, digit * 10);
}

int main()
{
	cin >> N;
	cal(1, N, 1);
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl;
}
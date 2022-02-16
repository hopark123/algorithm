#include <iostream>
using namespace std;

int		arr[3000][3000];
int		N;
int		m,p,z;

int			check(int y, int x, int size)
{
	int		res;
	
	res = arr[y][x];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			if (arr[y + i][x + j] != res)
				return (3);
	}
	return (res);
}

void		func(int y, int x, int size)
{
	int			res;
	
	res = check(y, x, size);
	if (res == -1)
		m++;
	else if (res == 0)
		z++;
	else if (res == 1)
		p++;
	else {
		func(y, x, size / 3);
		func(y + size / 3, x, size / 3);
		func(y + size / 3 * 2, x, size / 3);
		func(y, x + size / 3, size / 3);
		func(y, x + size / 3 * 2, size / 3);
		func(y + size / 3, x + size / 3 , size / 3);
		func(y + size / 3, x + size / 3 * 2, size / 3);
		func(y + size / 3 * 2, x + size / 3 , size / 3);
		func(y + size / 3 * 2, x + size / 3 * 2, size / 3);
	}
}



int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	func(0, 0, N);
	cout << m << "\n" << z << "\n" << p;
}
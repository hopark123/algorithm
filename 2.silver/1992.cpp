#include <iostream>
using namespace std;

string		arr[65];
int		N;
string		str;


int			check(int y, int x, int size) {
	int		res;
	
	res = arr[y][x] - '0';
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if (arr[y + i][x + j] != res + '0')
				return (-1);
		}
	return (res);
}

void		func(int y, int x, int size) {
	int che;

	che = check(y, x, size);
	if (che == 1)
		str += "1";
	else if (che == 0)
		str += "0";
	else {
		str += "(";
		func(y, x, size / 2);
		func(y, x + size / 2, size / 2);
		func(y + size / 2, x, size / 2);
		func(y + size / 2, x + size / 2, size / 2);
		str += ")";
	}
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	func(0, 0, N);
	cout << str;
}
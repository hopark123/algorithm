#include <iostream>
#include <math.h>

using namespace std;

int		r1, c1, r2, c2;

int	draw(int i, int j)
{
	int	num;
	int	line;

	line = max(abs(i), abs(j));
	num = (pow((2 * line + 1), 2));
	if (line == i) return (num -= line - j);
	num -= line * 2;
	if (line == -j) return (num -= line - i);
	num -= line * 2;
	if (line == -i) return (num -= line + j);
	num -= line * 2;
	if (line == j) return (num -= line + i);
	return (num);
}

int	length(int _max)
{
	return (_max ? length(_max / 10) + 1 : 0);
}

int main()
{
	int	_max;
	int	_length = 0;

	cin >> r1 >> c1 >> r2 >> c2;
	_max = max(max(abs(r1), abs(c1)), max(abs(r2), abs(c2)));
	for (int i = r1; i <= r2; i++)
		for (int j = c1; j <= c2; j++)
			_length = max(_length, length(draw(i,j)));
	for (int i = r1; i <= r2; i++)
	{
		for (int j = c1; j <= c2; j++)
			printf("%*d ", _length, draw(i,j));
		putchar('\n');
	}
}
#include <iostream>

using namespace std;

int		arr[129][129];
int		N;
int		w, c;

int		color(int y, int x, int size)
{
	int flag = arr[y][x];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (arr[y + i][x + j] != flag)
				return (0);
	if (flag == 0)
		return (1);
	return(2);
}

void		check(int y, int x, int size) {
	int	col = color(y, x, size);
	if (col == 1) {
		// cout << w<<"w" <<y << " " << x <<" "<< size << endl;
		w++;
	}
	else if (col == 2) {
		// cout << c<<"c" <<y << " " << x <<" "<< size << endl;
		c++;
	}
	else {
		check(y , x, size / 2);
		check(y + size / 2 , x, size / 2);
		check(y , x + size / 2, size / 2);
		check(y + size / 2, x + size / 2, size / 2);
	}

}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	check(0, 0, N);
	cout << w << "\n" << c;
}
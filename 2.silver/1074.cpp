#include <iostream>

using namespace std;

int		N, r, c, res;

void		func(int y, int x, int size) {

	if (y == r && x == c) {
		cout << res << "\n";
		return ;
	}
	if (r < y + size && y <= r && c < x + size && x <= c)
	{
		func(y, x, size/2); //1사분면
		func(y, x + size / 2, size/2); // 2사분면 
		func(y + size / 2, x, size/2); // 3사분면
		func(y + size / 2, x + size / 2, size/2); // 4사분면
	}
	else
	{
		res += size * size;
	}

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> r >> c;
	func(0, 0, 1 << N);
}
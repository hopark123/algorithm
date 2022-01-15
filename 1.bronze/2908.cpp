#include <iostream>

using namespace std;

int change(int A)
{
	int res = 0;
	res += (A % 10) * 100;
	A /= 10;
	res += (A % 10) * 10;
	A /= 10;
	res += (A % 10);
	return (res);
}

int main()
{
	int	A, B;
	cin >> A >> B;
	A = change(A);
	B = change(B);
	if (A > B)
		cout << A << endl;
	else
		cout << B << endl;
}
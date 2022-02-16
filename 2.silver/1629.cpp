#include <iostream>
#include <cmath>

using namespace std;


long long	multi(long long a, long long b, long long c) {
	a %= c;
	if (b == 0) return (1);
	else if (b == 1) return (a);
	else if (b % 2 == 0) {
		long long temp = multi(a, b / 2, c) % c;
		return ((temp * temp) % c);
	}
	else {
		return ((multi(a, b - 1, c) % c * multi(a, 1, c) % c) % c);
	}
}

int main() {
	long long A, B, C;
	cin >> A >> B >> C;
	cout << multi(A, B, C);
}
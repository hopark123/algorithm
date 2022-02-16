#include <iostream>

using namespace std;

bool	check(long long A, long long B, long long C) {
	if (A * A == B * B + C * C)
		return (true);
	else if (B * B == A * A + C * C)
		return (true);
	else if (C * C == A * A + B * B)
		return (true);
	else
		return (false);
}

int main() {
	long long A, B, C;
	while (cin >> A >> B >> C) {
		if (!A && !B && !C)
			break;
		if (check(A, B, C))
			cout << "right\n";
		else
			cout << "wrong\n";
	}

}
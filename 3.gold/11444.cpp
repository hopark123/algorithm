#include <iostream>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
#define MOD		1000000007



long long		n;

long long	_mod(long long a) {
	return (a % MOD);
}
class	Matrix {
public :
	Matrix() : x1(1), y1(1), x2(1), y2(0) {}
	Matrix operator=(const Matrix &other) {
		this->x1 = other.x1;
		this->x2 = other.x2;
		this->y1 = other.y1;
		this->y2 = other.y2;
		return (*this);
	}
	Matrix operator*(const Matrix &other) {
		Matrix temp;
		temp.x1 = _mod(_mod(this->x1 * other.x1) + _mod(this->y1 * other.x2));
		temp.y1 = _mod(_mod(this->x1 * other.y1) + _mod(this->y1 * other.y2));
		temp.x2 = _mod(_mod(this->x2 * other.x1) + _mod(this->y2 * other.x2));
		temp.y2 = _mod(_mod(this->x2 * other.y1) + _mod(this->y2 * other.y2));
		(*this) = temp;
		return (*this);
	}
	long long x1, y1, x2, y2;
};

map<long long, Matrix> _map;

Matrix		fibonacci(long long n) {
	Matrix one;
	if (n == 0 || n == 1) {
		_map[n] = one;
		return (one);
	}
	if (_map.find(n) != _map.end())
		return (_map[n]);
	if (n % 2 == 0) {
		return (_map[n] = (fibonacci(n / 2) * fibonacci(n / 2))); 
	}
	else {
		return (_map[n] = (fibonacci(n - 1) * fibonacci(1)));
	}
}


int main() {
	cin >> n;
	cout << fibonacci(n).x2 << "\n";
}
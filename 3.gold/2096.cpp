#include <iostream>
#include <cmath>

using namespace std;


int		N;

long long _max[3];
long long	_bmax[3];
long long _min[3];
long long _bmin[3];
int main () {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c; cin >> a >> b >> c;
		_max[0] = max(_bmax[0], _bmax[1]) + a;
		_max[1] = max(max(_bmax[0], _bmax[1]), _bmax[2]) + b;
		_max[2] = max(_bmax[1], _bmax[2]) + c;
		_min[0] = min(_bmin[0], _bmin[1]) + a;
		_min[1] = min(min(_bmin[0], _bmin[1]), _bmin[2]) + b;
		_min[2] = min(_bmin[1], _bmin[2]) + c;
		for (int i = 0; i < 3; i++) {
			_bmax[i] = _max[i];
			_bmin[i] = _min[i];
		}
	}
	cout << max(max(_max[0], _max[1]), _max[2]) <<" " << min(min(_min[0], _min[1]), _min[2]) <<"\n";
}
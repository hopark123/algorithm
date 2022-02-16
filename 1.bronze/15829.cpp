#include <iostream>
#include <cmath>

using namespace std;


long long	cal(char	c, int index) {
	long long res = 0;
	long long mulit = 1;
	
	res += c - 'a' + 1;
	for (int i = 0; i < index; i++)
		mulit = mulit * 31 % 1234567891;
		
	res *= mulit;
	return (res);
}
	

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int		N;
	long long res = 0;
	string str;
	cin >> N >> str;
	for (int i = 0; i < str.size(); i++) {
		res += cal(str[i], i);
		res = res % 1234567891;
	}
	cout << res;
}
#include <iostream>

using namespace std;

int main() {
	string		str;
	long long	res = 0;
	bool		minus = false;

	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		int	temp = 0;
		while (str[i] >= '0'  && str[i] <= '9')
		{
			temp *= 10;
			temp += str[i] - '0';
			i++;
		}
		if (!minus)
			res += temp;
		else
			res -= temp;
		if (str[i] == '-')
			minus = true;
	}
	cout << res;

}
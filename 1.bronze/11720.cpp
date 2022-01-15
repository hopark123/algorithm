#include <iostream>
#include <string>

using namespace std;

int main()
{
	int		N;
	string	s;
	int	res = 0;
	cin >> N;
	cin >> s;
	for (int i = 0 ; i < s.size(); i++)
		res += s[i] - '0';
	cout << res << endl;
}
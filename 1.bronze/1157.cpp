#include <iostream>
#include <string>

using namespace std;

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		c += 'A' - 'a';
	return (c);
}
int		arr[26];

int main()
{
	char	c = 0;
	int		_max = 0;
	int		temp = 0;
	string	s;

	cin >> s;
	for(int i = 0; i < (int)s.size(); i++)
	{
		s[i] = to_upper(s[i]);
		arr[s[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++)
		_max = max(_max, arr[i]);
	for (int i = 0; i < 26; i++)
	{
		if (_max == arr[i])
		{
			c = i + 'A';
			temp++;
		}
	}
	if (temp == 1)
		cout << c << endl;
	else
		cout << "?" << endl;
}
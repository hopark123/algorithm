#include <iostream>
#include <string>

using namespace std;

int main()
{
	string	s;
	int		cnt = 0;
	int		temp = 0;
	getline(cin, s);
	for (int i = 0; s[i]; i++)
	{
		while (isspace(s[i]))
			i++;
		temp = 0;
		while (s[i] != ' ' && s[i])
		{
			i++;
			temp++;
		}
		if (temp > 0)
			cnt++;
	}
	cout << cnt << endl;
}
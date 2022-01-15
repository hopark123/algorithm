#include <iostream>

using namespace std;

int	T;

int main()
{
	string	str;
	int		flag = 1;
	int		res = 0;
	cin >> T;
	while (T--)
	{
		res = 0;
		flag = 1;
		cin >> str;
		for (int i = 0; i < (int)str.length(); i++)
		{
			if (str[i] == 'O')
			{
				res += flag;
				flag++;
			}
			else
				flag = 1;
		}
		cout << res<< endl;
	}
}
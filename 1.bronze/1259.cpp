#include <iostream>

using namespace std;



int main()
{
	string		str;
	while (cin >> str)
	{
		if (!str.compare("0"))
			return (0);
		int flag = 1;
		for (int i = 0; i <= str.size() / 2; i++)
		{
			if (str[i] != str[str.size() - 1 - i])
			{
				cout << "no" << endl;
				flag = 0;
				break ;
			}
		}
		if (flag)
			cout << "yes" << endl;
	}

}
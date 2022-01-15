#include <iostream>

using namespace std;

int main()
{
	int		T;
	int		N;
	string	s;
	cin >> T;
	while (T--)
	{
		cin >> N;
		cin >> s;
		for (int i = 0 ; i < s.size(); i++)
		{
			for(int j = 0 ; j < N; j++)
				cout << s[i];
		}
		cout << endl;
	}
}
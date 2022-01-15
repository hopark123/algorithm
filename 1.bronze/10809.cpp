#include <iostream>

using namespace std;

int main() {
	string s;
	int	arr[26];

	cin >> s;
	for (int j = 0; j < 26; j++)
	{
		arr[j] = -1;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'a' + j)
			{
				arr[j] = i;
				break ;
			}
		}
	}
	for (int i = 0; i < 26; i++)
		cout << arr[i] << " ";
}
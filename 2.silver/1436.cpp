#include <iostream>
#include <string>

using namespace std;

int main()
{
	int		N;
	int		cnt = 0;
	int		start = 665;
	string		str;
	cin >> N;

	while (1)
	{
		str = to_string(++start);
		if (str.find("666") != -1)
			cnt++;
		if (cnt == N)
		{
			cout << start << endl;
			return (0);
		}
	}
}
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	string		res;
	int			n, x, m = 0;
	stack<int>	temp;
	
	cin >> n;
	while (n--) {
		cin >> x;
		if (x > m) {
			while (x > m) {
				res += "+";
				temp.push(++m);
			}
			temp.pop();
			res += "-";
		}
		else {
			bool check = false;
			if (!temp.empty()) {
				if (x == temp.top())
					check = true;
				temp.pop();
				res += "-";
			}
			if (!check) {
				cout << "NO" << endl;
				return (0);
			}
		}
	}
	for (int i = 0; i < res.length(); i++)
		cout << res[i] << "\n";
	return (0);
}

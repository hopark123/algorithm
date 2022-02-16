#include <iostream>
#include <map>

using namespace std;

typedef	struct s_pair{
	char L, R;
}	t_pair;

map<char, t_pair >_map;

using namespace std;

void	prefix(char x) {
	if (x != '.')
		cout << x;
	if (_map[x].L != '.')
		prefix(_map[x].L);
	if (_map[x].R != '.')
		prefix(_map[x].R);
}
void	postfix(char x) {
	if (_map[x].L != '.')
		postfix(_map[x].L);
	if (_map[x].R != '.')
		postfix(_map[x].R);
	if (x != '.')
		cout << x;
}
void	infix(char x) {
	if (_map[x].L != '.')
		infix(_map[x].L);
	if (x != '.')
		cout << x;
	if (_map[x].R != '.')
		infix(_map[x].R);
}

int		N;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	char x, y, z;
	cin >> x >> y >> z;
	t_pair temp;
	temp.L = y;
	temp.R = z;
	_map[x] = temp;
	N--;
	while (N--) {
		char a, b, c;
		cin >> a >> b >> c;
		t_pair temp;
		temp.L = b;
		temp.R = c;
		_map[a] = temp;
	}
	prefix(x);
	cout << "\n";
	infix(x);
	cout << "\n";
	postfix(x);
	cout << "\n";
}
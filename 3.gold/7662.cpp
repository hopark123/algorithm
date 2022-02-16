#include <iostream>
#include <set>

using namespace std;

void		show(multiset<int> _set) {
	cout << "****";
	for (multiset<int>::iterator it = _set.begin(); it != _set.end(); it++)
		cout << *it << " ";
	cout << "\n";

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int		T; cin >> T;
	while (T--) {
		int		N; cin >> N;
		multiset<int> _set;
		while (N--) {
			string	str;
			int		num;
			cin >> str;
			if (!str.compare("D")) {
				cin >> num;
				if (num == -1) {
					if (!_set.empty())
						_set.erase(_set.begin());
				}
				else if (num == 1) {
					if (!_set.empty()) {
						_set.erase(--_set.end());
					}

				}
			}
			else if (!str.compare("I")) {
				cin >> num;
				_set.insert(num);
			}
		}
		if (_set.empty())
			cout << "EMPTY\n";
		else
			cout << *(--_set.end()) << " " << *_set.begin() << "\n";
	}
}
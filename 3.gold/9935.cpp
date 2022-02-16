#include <iostream>

using namespace std;

int main() {
	string		a, b; cin >> a >> b;
	int flag = 1, len = 0;
	for (int i = 0; i < a.size(); i++) {
		flag = 1;
		int j = 0;
		for (j = 0; j < b.size(); j++) {
			// cout << i << a[i] << j << b[j] << " ";
			if (a[i] != b[j]) {
				break ;
			}
		}
		// cout << endl;
		if (j == b.size() - 1) {
			for (int k = 0; k < j; k++) {
				cout << a[i + k];
				a[i + k] = 0;
			}
			i = 0;
			len++;
		}
	}
	if (len == 0)
		cout << "FRULA";
}
#include <iostream>

using namespace std;

int		arr[10005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long N;
	cin >> N;

	while (N--) {
		int temp;
		cin >> temp;
		arr[temp]++;
	}
	for (int i = 1; i <= 10000; i++)
	{
		while (arr[i]--)
			cout << i << "\n";
	}
}

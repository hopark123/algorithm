#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vec;
int main() {
	int		N;
	cin >> N;

	while (N--) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	long long res= 0;
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++)
		res += (vec.size() - i) * vec[i];
	cout << res;



}
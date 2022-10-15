#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<long long> vec;
	int		N,M;
	long long temp;
	cin >> N;
	while (N--)
	{
		cin >> temp; vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());
	cin >> M;
	while (M--)
	{
		cin >> temp;
		cout << _bound(vec.begin(), vec.end(), temp) - lower_bound(vec.begin(), vec.end(), temp) << " ";
	}
}
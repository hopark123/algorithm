#include <iostream>
#include <vector>

using namespace std;

bool	big(pair<int, int> a, pair<int, int> b)
{
	if (a.first < b.first && a.second < b.second)
		return (true);
	return (false);
}

int	res[55];

int main()
{
	vector<pair<int, int> > vec;
	int		T;
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		int	a, b;
		cin >> a >> b;
		vec.push_back(make_pair(a, b));
	}
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec.size(); j++)
		if (big(vec[i], vec[j]))
			res[i]++;
	}
	for (int i = 0; i < vec.size(); i++)
		cout << res[i] + 1 << " ";
}
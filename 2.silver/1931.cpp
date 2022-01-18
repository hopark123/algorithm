#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int		N;
vector<pair<int, int> > vec;

bool Compare(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first)
		return a.second < b.second;
	else return a.first < b.first;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	while (N--) {
		int a, b;
		cin >> a >> b;
		vec.push_back(make_pair(a, b));
	}
	vec.push_back(make_pair(0, 0));
	sort(vec.begin(), vec.end(), Compare);
	int res = 0;
	int	end = vec[0].second;
	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i].second < end)
			end = vec[i].second;
		else if (vec[i].first >= end) {
			end = vec[i].second;
			res++;
		}
	}
	cout << res ;
}
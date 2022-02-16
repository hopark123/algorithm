#include <iostream>
#include <vector>

using namespace std;

int main() {

	int		T; cin >> T;
	while (T--) {
		int			num;
		cin >> num;
		int			index = 0;
		vector<pair<string, int> > vec;
		while (num--){
			string		name, kind;
			int			i;
			cin >> name >> kind;
			for (i = 0; i < vec.size(); i++)
				if (!kind.compare(vec[i].first))
				{
					vec[i].second++;
					break ;
				}
			if (i == vec.size()) {
				vec.push_back(make_pair(kind, 2));
			}
		}
		int		res = 1;
		for (int j = 0; j < vec.size(); j++)
			res *= vec[j].second;
		cout << res - 1 << "\n";
	}
}
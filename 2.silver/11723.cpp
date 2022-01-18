#include <iostream>
#include <map>
#include <string.h>

using namespace std;

map<int, int> _map;
int main() {
	int N; cin >> N;
	scanf("%d", &N);
	char str[100] = {0,};
	// string str;
	int		num;
	while (N--) {
		scanf("%s", str);
		if (!strcmp(str, ("add"))) {
			scanf("%d", &num);
			_map.insert(make_pair(num, 0));
		}
		else if (!strcmp(str, ("remove"))) {
			scanf("%d", &num);
			_map.erase(num);
		}
		else if (!strcmp(str, ("check"))) {
			scanf("%d", &num);
			if (_map.find(num) != _map.end())
				printf("1\n");
			else
				printf("0\n");
		}
		else if (!strcmp(str, ("toggle"))) {
			scanf("%d", &num);
			if (_map.find(num) != _map.end())
				_map.erase(num);
			else
				_map.insert(make_pair(num,0));
		}
		else if (!strcmp(str, ("all"))) {
			for (int i = 1; i <= 20; i++)
				_map.insert(make_pair(i, 0));
		}
		else if (!strcmp(str, ("empty"))) {
			_map.clear();
		}
	}

}
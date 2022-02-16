#include <iostream>
#include <deque>

using namespace std;

void	show(deque<int> deq) {
	cout << deq.size() << "show\n";
	for (int i = 0; i < deq.size(); i++) {
		cout << deq[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int		T; cin >> T;
	while (T--) {
		string			str; cin >> str;
		int				N; cin >> N;
		string			num; cin >> num;
		deque<int>		deq;
		int				flag = 1;
		int				start = 0;
		int i = 0;
		while (num[i]) {
			int temp = 0;
			i++;
			while (num[i] >= '0' && num[i] <= '9') {
				temp *= 10;
				temp += num[i] - '0';
				i++;
			}
			if (temp != 0){
				deq.push_back(temp);
			}
		}
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'D') {
				if (deq.empty())
				{
					flag = 3;
					cout << "error\n";
					break ;
				}
				if (flag == 1)
					deq.pop_front();
				else if (flag == -1)
					deq.pop_back();
			}
			else if (str[i] == 'R') {
				flag *= -1;
			}
		}
		if (deq.empty()) {
			if (flag != 3)
				cout << "[]\n";
			continue ;
		}
		cout << "[";
		if (flag == 1) {
			for (int i = 0; i < deq.size() - 1; i++)
				cout << deq[i] << ",";
			cout << deq[deq.size() - 1] << "]\n";
		}
		else if (flag == -1){
			for (int i = deq.size() - 1; i > 0; i--)
				cout << deq[i] << ",";
			cout << deq[0] << "]\n";
		}
	}
}
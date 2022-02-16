#include <iostream>
#include <cmath>
#include <map>

using namespace std;

long long		A, B;
map<long long, long long> _map;

void		d(long long x, long long cnt) {
	if (x > B)
		return ;
	long long		addone = 10 * x + 1;
	_map[x] = max(cnt, _map[x]);
	d(2 * x, cnt + 1);
	d(addone, cnt + 1);
}

int main() {
	cin >> A >> B;
	d(A, 1);
	if (_map[B] == 0)
		cout << "-1\n";
	else
		cout << _map[B];
}

// not dp
// #include <iostream>
// #include <string>

// using namespace std;

// int A,B;
// int cnt=1;
// string s;

// int main() {
// 	cin>> A >> B;
// 	s=to_string(B);

// 	while(true) {
// 		if(s[s.length()-1]=='1') { //1로 끝날 때
// 			cnt++;
// 			s=s.substr(0,s.length()-1);
// 			B=stoi(s);
// 		}else if(!(B%2)){
// 			cnt++;
// 			B/=2;
// 			s=to_string(B);
// 		}else if(B%2) {
// 			cnt=-1;
// 			break;
// 		}
		
// 		if(A==B) break;
// 		else if (A>B) {
// 			cnt=-1;
// 			break;
// 		}
// 	}
// 	cout << cnt;

// }


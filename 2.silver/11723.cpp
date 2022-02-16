#include <iostream>
using namespace std;

// 출력
void	show(int *a) {
for (int i = 32; i > 0; i--) {
		cout << ((*a & (1 << (i - 1))) ? 1 : 0 );
	}
}
// 초기화(null)
void	init(int *a) {
	*a = 0;
}
// 모두 포함
void	full(int *a) {
	*a = -1;
}
// i 번째 인덱스 삽입
void	set(int *a, int i) {
	*a |= (1 << i);
}
// i 번째 인덱스 삭제
void	drop(int *a, int i) {
	*a &= ~(1 << i);
}
// i 번째 인덱스 확인
bool	check(int *a, int i) {
	return (*a & (1 << i));
}
// i 번째 toggle (1 은 0으로 0은 1으로) (xor 연산 ^)
void	toggle(int *a, int i) {
	*a ^= (1 << i);
}
// 마지막 원소 구하기
int		getLast(int *a) {
	return (*a & -*a);
}
// 마지막 원소 삭제하기
void	dropLast(int *a) {
	*a &= (*a - 1);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int	M; cin >> M;
	int	bit;
	init(&bit);
	while (M--) {
		string str; cin >> str;
		int		temp;
		if (!str.compare("add")) {
			cin >> temp;
			set(&bit, temp);
		}
		else if (!str.compare("remove")) {
			cin >> temp;
			drop(&bit, temp);
		}
		else if (!str.compare("check")) {
			cin >> temp;
			cout << check(&bit, temp) << "\n";
		}
		else if (!str.compare("toggle")) {
			cin >> temp;
			toggle(&bit, temp);
		}
		else if (!str.compare("all")) {
			full(&bit);
		}
		else if (!str.compare("empty")) {
			init(&bit);
		}
	}
}
#include <iostream>
#include <queue>

using namespace std;

int				arr[21][21];
int				N;

typedef struct s_fish {
	int y;
	int x;
	int dis;
}				t_fish;

// std::ostream &operator<<(std::ostream &ost, const t_fish &fish){
// 	ost << "[" << fish.y <<"][" << fish.x <<"][" <<fish.dis << "]";
// return (ost);
// }

// void	pr(void) {
// 	for (int i = 0; i < N; i++) {
// 		for (int j = 0; j < N; j++) {
// 			cout << arr[i][j] << " ";
// 		}
// 		cout << "\n";
// 	}
	// cout << "\n";
// }

class	_compare {
	public :
	bool operator() (t_fish A, t_fish B) {
		if (A.dis == B.dis) {
			if (A.y == B.y)
				return (A.x > B.x);
			return (A.y > B.y);
		}
		return (A.dis > B.dis);
	}
};

class	Shark{
public : 
	Shark(void) : _y(0), _x(0), _size(2), _cnt(0), _time(0) {}
	void	set_locate(int y, int x) {
		_y = y;	_x = x;
	}
private :
	int		_y;
	int		_x;
	int		_size;
	int		_cnt;
	int		_time;
	priority_queue<t_fish, vector<t_fish>, _compare> eatable;


public : 
	bool	safe_wall(int y, int x) {
		return (y >= 0 && y < N && x >= 0 && x < N);
	}
	void	find_eatable(void) {
		int				dy[4] = {0, 0, 1, -1};
		int				dx[4] = {-1, 1, 0, 0};
		int				visited[21][21];
		for (int i = 0 ; i < N; i++)
			for (int j = 0; j < N; j++)
				visited[i][j] = 0;
	
		t_fish			now;
		queue<t_fish>	q;
		now.dis = 0; now.y = _y; now.x = _x;
		q.push(now);
		visited[_y][_x] = 1;
		while (!q.empty()) {
			now.y = q.front().y;
			now.x = q.front().x;
			now.dis = q.front().dis;  q.pop();
			if (arr[now.y][now.x] != 0 && arr[now.y][now.x] < _size) {
				visited[now.y][now.x] = 1;
				eatable.push(now);
				continue;
			}
			for (int i = 0; i < 4; i++) {
				t_fish		next;
				next.y = now.y + dy[i];
				next.x = now.x + dx[i];
				next.dis = now.dis + 1;
				if (safe_wall(next.y, next.x) && arr[next.y][next.x] <= this->_size && visited[next.y][next.x] != 1) {
					visited[next.y][next.x] = 1;
					q.push(next);
				}
			}
		}
	}

	bool		eat(void) {
		if (eatable.empty())
			return (false);
		_cnt++;
		if (_cnt == _size) {
			_size++;
			_cnt = 0;
		}
		_time += eatable.top().dis;
		_y = eatable.top().y;
		_x = eatable.top().x;
		arr[_y][_x] = 0;
		while (!eatable.empty())
			eatable.pop();
		return (true);
	}

	void	res(void) {
		cout << this->_time << "\n";
	// }

	// void	show(void) {
	// 	cout << eatable.top().y << eatable.top().x << eatable.top().dis << endl;
	// }
	// void	info(void) {
	// 	cout << "[" << _y << "][" << _x << "][" << _size << "][" << _cnt << "][" << _time << "]\n";
	// } 
};

int main() {
	Shark	shark;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				arr[i][j] = 0;
				shark.set_locate(i, j);
			}
		}
	}
	while (1) {
		shark.find_eatable();
		if (!shark.eat()) {
			break ;
		}
	}
	shark.res();
}
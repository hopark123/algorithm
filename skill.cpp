
1e7

// 0000 ~ 1111 ////
vector<string> ft_pair_order(int n) {
  vector<string> res;
  for (int i = 0; i < pow(2, n); ++i) {
    string temp;
    int nbr = i;
    for (int j = 0; j < n; ++j) {
      int rest = nbr % 2;
      nbr /= 2;
      temp += to_string(rest);
    }
    res.push_back(temp);
  }
  return res;
}

// int -> string //
to_string 
//string -> int
stoi

// 순열
int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";;
  do {
    bool flag = true;
    for (int i = 0; i < data.size(); ++i) {
      char a = data[i][0];
      char b = data[i][2];
      char cal = data[i][3];
      int gap = data[i][4] -'0';
      flag = ft_cal(friends, a, b, cal, gap);
      if (!flag)
        break ;
    }
    if (flag)
      ++answer;
  }
  while(next_permutation(friends.begin(), friends.end()));
  return answer;
}


// resizE
visited.resize(4, vector<int>(4, 1e7));

class _Compare {
	public :
	bool operator() (pair<int, bool> a, pair<int, bool> b) {
		int left = a.first;
		int right = b.first;
		if (left == right) {
			if (!a.second)
				left *= -1;
			if (!b.second)
				right *= -1;
		}
		return (left >= right);
	}
};

// priority_queue
vector<int> dij(int st, int x, int y) {
  priority_queue<pair<int, int> > pq;
  vector<int> vec(202, INF);
  vec[st] = 0;
  pq.push(make_pair(0, st));

  while (!pq.empty()) {
    int cost = -pq.top().first;
    int here = pq.top().second; pq.pop();
    if (cost > vec[here]) continue;
    // if (here == x || here == y) continue;
    for (int i = 0; i < arr[here].size(); ++i) {
      int there = arr[here][i].first;
      int here_to_there = arr[here][i].second + vec[here];
      if (here_to_there < vec[there]) {
        vec[there] = here_to_there ;
        pq.push(make_pair(-here_to_there, there));
      }
    }
  }
  return vec;
}

int cnt = res.end() - lower_bound(res.begin(), res.end(), stoi(query[7]));
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#define INF 100000005
using namespace std;

vector<pair<int, int> > arr[202];

vector<int> dij(int st, int x, int y) {
  priority_queue<pair<int, int> > pq;
  vector<int> vec(202, INF);
  vec[st] = 0;
  pq.push(make_pair(0, st));

  while (!pq.empty()) {
    int cost = -pq.top().first;
    int here = pq.top().second; pq.pop();
    if (cost > vec[here]) continue;
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


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 100005 * 500;
    for (auto fare : fares) {
      arr[fare[0]].push_back(make_pair(fare[1], fare[2]));
      arr[fare[1]].push_back(make_pair(fare[0], fare[2]));
    }
    vector<int> st_s = dij(s, a, b);
    vector<int> st_a = dij(a, s, b);
    vector<int> st_b = dij(b, a, s);
    // for (int i = 0; i <= n; ++i)
    //   cout << st_s[i] << " ";
    // cout << endl;
    //   for (int i = 0; i <= n; ++i)
    //   cout << st_a[i] << " ";
    // cout << endl;
    //   for (int i = 0; i <= n; ++i)
    //   cout << st_b[i] << " ";
    // cout << endl;
  
    for (int i = 0; i <=n; ++i) {
      answer = min(answer, st_s[i] + st_b[i] + st_a[i]);
    }

    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  vector<vector<int> > a;
  vector<int> b;
  b.push_back(4); b.push_back(1); b.push_back(10); 
  a.push_back(b); b.clear();
  b.push_back(3); b.push_back(5); b.push_back(24); 
  a.push_back(b); b.clear();
  b.push_back(5); b.push_back(6); b.push_back(2); 
  a.push_back(b); b.clear();
  b.push_back(3); b.push_back(1); b.push_back(41); 
  a.push_back(b); b.clear();
  b.push_back(5); b.push_back(1); b.push_back(24); 
  a.push_back(b); b.clear();
  b.push_back(4); b.push_back(6); b.push_back(50); 
  a.push_back(b); b.clear();
  b.push_back(2); b.push_back(4); b.push_back(66); 
  a.push_back(b); b.clear();
  b.push_back(2); b.push_back(3); b.push_back(22); 
  a.push_back(b); b.clear();
  b.push_back(1); b.push_back(6); b.push_back(25); 
  a.push_back(b); b.clear();

  int sol = solution(6, 4, 6, 2, a);
  cout << sol << endl;
}


/*
n	s	a	b	fares	result
6	4	6	2	[[4, 1, 10], [3, 5, 24], [5, 6, 2], [3, 1, 41], [5, 1, 24], [4, 6, 50], [2, 4, 66], [2, 3, 22], [1, 6, 25]]	82
7	3	4	1	[[5, 7, 9], [4, 6, 4], [3, 6, 1], [3, 2, 3], [2, 1, 6]]	14
6	4	5	6	[[2,6,6], [6,3,7], [4,6,7], [6,5,11], [2,5,12], [5,3,20], [2,4,8], [4,3,9]]	18

*/
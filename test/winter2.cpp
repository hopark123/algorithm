#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;

vector<int> score;

bool compare1 (pair<int, int>a, pair<int, int> b) {
  if (a.second > b.second)
    return true;
  else if (a.second == b.second) {
    return a.first < b.first;
  }
  return false;
}

bool compare2(pair<int, int> a, pair<int, int> b) {
  return a.first < b.first;
}

vector<pair<int, int> > sort(vector<pair<int, int> > before, int &answer) {
  vector<pair<int, int> > after;
  string a;
  string b;
  for (int i = 0; i < before.size(); ++i) {
    after.push_back({i + 1, score[i + 1]});
  }
  for (int i = 0; i < before.size() / 2; ++i) {
    a.push_back(before[i].first + '0');
  }
  sort(after.begin(), after.end(), compare1);
  for (int i = 0; i < before.size() / 2; ++i) {
    b.push_back(after[i].first + '0');
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  cout << a << "=" << b << endl;
  if (a != b)
    ++answer;
  return after;
}


int solution(int n, vector<int> student, vector<int> point) {
    int answer = 0;
    score.resize(n + 1, 0);
    vector<pair<int, int> > before;

    for (int i = 0; i < n; ++i) {
      before.push_back({i +  1, 0});
    }
    for (int i = 0; i < point.size(); ++i) {
      score[student[i]] += point[i];
      for (int i = 1; i <= n; ++i) {
        cout <<"[" << score[i] << "]";
      }
      cout << endl;
      cout << "bf" << endl;
      for (int i = 0; i < n; ++i) {
        cout <<"[" << before[i].first << "-" << before[i].second << "]";
      }
      cout << endl;
      before = sort(before, answer);
      for (int i = 0; i < n; ++i) {
        cout <<"[" << before[i].first << "-" << before[i].second << "]";
      }
      cout << endl;
      cout << endl;
      cout << endl;
    }
    for (int i = 0; i < n; ++i) {
      cout <<"[" << score[i] << "]";
    }
    cout << endl;
    return answer;
}


int main()
{
  ios::sync_with_stdio(false);
  vector<int> a ={6, 1, 4, 2, 5, 1, 3, 3, 1, 6, 5};
  vector<int> b = {3, 2, 5, 3, 4, 2, 4, 2, 3, 2, 2};
  int sol = solution(6, a, b);
  cout << sol << endl;
}


/*
6, {6, 1, 4, 2, 5, 1, 3, 3, 1, 6, 5}, {3, 2, 5, 3, 4, 2, 4, 2, 3, 2, 2}
기댓값 〉
7


10, {3, 2, 10, 2, 8, 3, 9, 6, 1, 2}, {3, 2, 2, 5, 4, 1, 2, 1, 3, 3}

*/
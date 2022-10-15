#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;


bool find(string source, string target) {
  bool flag = true;
  int st = -1;
  string::iterator it = source.begin() - 1;
  for (int i = 0; i < target.size(); ++i) {
    it = find(it + 1, source.end(), target[i]);
    // cout<<"find" << target[i] << endl;
    // for (auto itt = it; itt < source.end(); ++itt) 
      // cout << *itt;
    // cout << endl;

    if (it == source.end()){
      flag = false;
      break ;
    }
  }
  return flag;
}

int getMaximumRemovals(vector<int> order, string source, string target) {
  int cnt = 0;
//   for (int i = 0; i < order.size(); ++i)
    // cout << order[i] << endl;
//   cout << source << endl;
//   cout << target << endl;
  for (auto t : order) {
    if 
    if (source[t - 1] == '-')
      continue;
    source[t - 1] = '-';
    // cout << t <<  source << endl;;
    bool flag = true;
    int st = 0;
    flag = find(source, target);
    if (flag) {
      ++cnt;
    }
    else
      break;
    // cout << endl;
  }
  return cnt;
}

int main()
{
  ios::sync_with_stdio(false);
  // vector<int> a = {3, 12, 10, 8, 5, 2, 14, 11, 15, 4, 9, 7, 6, 1, 13};
  // int sol = getMaximumRemovals(a, "ceabddaaccbceca", "cac");
  // vector<int> a = {5, 1, 4, 2, 3, 5};
  // int sol = getMaximumRemovals(a, "hkbdi", "kd");
  vector<int> a = {7, 7, 1, 2, 5, 4, 3, 6};
  int sol = getMaximumRemovals(a, "abbabaa", "bb");

  cout << sol << endl;
}


/*
7
7
1
2
5
4
3
6
abbabaa
bb

*/

// 3
// 12
// 10
// 8
// 5
// 2
// 14
// 11
// 15
// 4
// 9
// 7
// 6
// 1
// 13
// ceabddaaccbceca
// cac
// 3ceabddaaccbceca
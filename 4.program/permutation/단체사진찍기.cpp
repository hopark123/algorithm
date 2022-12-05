#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

bool ft_cal(string friends, char a, char b, char cal, int gap) {
  int index_a = friends.find(a);
  int index_b = friends.find(b);
  int arr_gap = abs(index_a - index_b) - 1;
  if (cal == '=') {
    return (arr_gap == gap);
  }
  else if (cal == '<') {
    return (arr_gap < gap);
  }
  else if (cal == '>') {
    return (arr_gap > gap);
  }
  return false;
}

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

int main()
{
  ios::sync_with_stdio(false);
  vector<string> a;
  a.push_back("N~F=0");
  a.push_back("R~T>2");

  int sol = solution(2, a);
    cout << sol << endl;
}


/*
2	["N~F=0", "R~T>2"]	3648
2	["M~C<2", "C~M>1"]	0
*/
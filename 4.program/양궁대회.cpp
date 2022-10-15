#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
int max_gap = 0;
vector<int> max_vec(11);

bool whoFirst(vector<int> res) {

  for (int i = 0; i < 11; ++i) {
    if (res[10 - i] > max_vec[10 - i]) {
      return true;
    }
    else if(res[10 - i] < max_vec[10 - i])
      return false;
  }

  return false;
}

int ft_check(vector<int> res, vector<int> info) {
  int rya = 0;
  int app = 0;

  for (int i = 0; i < 11; ++i) {
    if(res[i] > info[i]) {
      rya += 10 - i;
    }
    else {
      if (info[i] != 0)
        app += 10 - i;
    }
  }
  bool flag = true;
  if (max_gap == rya - app && rya - app != 0) {
    flag = whoFirst(res);
  }
  if (max_gap <= rya - app && rya - app != 0 && flag) {
    for (int i = 0; i < 11; ++i) {
      max_vec[i] = res[i];
    }
    max_gap = rya - app;
  }
  if (max_gap == 0)
    max_vec[0] = -1;
  return (1);
}

void sol(int index, int arrow, vector<int> res, vector<int> info){
  if (arrow == 0) {
    res[10] += arrow;
    index = 11;
  }
  if (index == 11) {
    res[10] += arrow;
    ft_check(res, info);
    res[10] -= arrow;
    return ;
  }
  sol(index + 1, arrow, res, info);
  if (arrow > info[index]) {
    res[index] = info[index] + 1;
    sol(index + 1, arrow - info[index] - 1, res, info);
    res[index] = 0;
  }
}


vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> res(11);
    sol(0, n, res, info);
    
    if (max_vec[0] == -1)
      answer.push_back(-1);
    else
      for (int i = 0; i < max_vec.size(); ++i) {
        answer.push_back(max_vec[i]);
      }
    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  vector<int> a;
  // a.push_back(2);
  // a.push_back(1);
  // a.push_back(1);
  // a.push_back(1);
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(0);

  // a.push_back(1);
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(0);
    
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(3);
  // a.push_back(4);
  // a.push_back(3);

  a.push_back(0);
  a.push_back(0);
  a.push_back(1);
  a.push_back(2);
  a.push_back(0);
  a.push_back(1);
  a.push_back(1);
  a.push_back(1);
  a.push_back(1);
  a.push_back(1);
  a.push_back(1);

  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(1);
  // a.push_back(1);
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(1);
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(0);
  // a.push_back(0);
  vector<int> sol = solution(9, a);
  for (auto it : sol)
    cout <<  it << endl;
}


/*
n = 3
info = [0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0]
5	[2,1,1,1,0,0,0,0,0,0,0]	[0,2,2,0,1,0,0,0,0,0,0]
1	[1,0,0,0,0,0,0,0,0,0,0]	[-1]
9	[0,0,1,2,0,1,1,1,1,1,1]	[1,1,2,0,1,2,2,0,0,0,0]
10	[0,0,0,0,0,0,0,0,3,4,3]	[1,1,1,1,1,1,1,1,0,0,2]
*/
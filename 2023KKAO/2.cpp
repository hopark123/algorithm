#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int ft_hand(int cap, int n, vector<int> &vec) {
  int fall = 0;
  while (n - 1 >= 0 && vec[n - 1] == 0) {
    --n;
    if (n <= 0)
      break ;
  }
  fall = n;
  while (cap) {
    while (n - 1 >= 0 && vec[n - 1] <= cap) {
      cap -= vec[n - 1];
      vec[n - 1] = 0;
      --n;
    }
    if (n >= 1) {
      if (vec[n - 1] > cap) {
        vec[n - 1] -= cap;
        cap = 0;
      }
    }
    else 
      break ;
  }
  return (fall);
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    while (n > 0) {
      int a = ft_hand(cap, n, deliveries);
      int b = ft_hand(cap, n, pickups);
      n = min(a,b);
      // cout << "=============== " << n << endl;
      // for (int i = 0; i < deliveries.size(); ++i) {
        // cout << deliveries[i] << " ";
      // }
      // cout << endl;
      // for (int i = 0; i < pickups.size(); ++i) {
        // cout << pickups[i] << " ";
      // }
      // cout << endl;
      // cout << "a" << a << "b"<< b << endl;
      // cout << "=============== " << n << endl;
      answer += max(a, b);
    }
    return 2 * answer;
}


int main()
{
  vector<int> a;
  vector<int> b;
 
  a.push_back(1);a.push_back(0);a.push_back(3);a.push_back(1);a.push_back(2);
  b.push_back(0);b.push_back(3);b.push_back(0);b.push_back(4);b.push_back(0);
  long long sol = solution(4, 5,a, b);
  cout << sol << endl;
}


/*
4, 5 ,
1 0 3 1 2 
0 3 0 4 0

2 , 7
[1, 0, 2, 0, 1, 0, 2]
[0, 2, 0, 1, 0, 2, 0]

*/
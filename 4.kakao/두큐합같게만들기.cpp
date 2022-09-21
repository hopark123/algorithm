#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

int get_time(string a, string b)
{
  int start = atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 5).c_str()) * 1;
  int end = atoi(b.substr(0, 2).c_str()) * 60 + atoi(b.substr(3, 5).c_str()) * 1;
  return (end - start);
}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<int> lq;
    queue<int> rq;
    long long lsum = 0;
    long long rsum = 0;
    for(auto &it : queue1) {
      lq.push(it);
      lsum += it;
    }
    for(auto &it : queue2) {
      rq.push(it);
      rsum += it;
    }
    while ((lsum != rsum)) {
      // cout << lsum << " == " << rsum << endl;
      if (lsum > rsum) {
        int temp = lq.front(); lq.pop();
        rq.push(temp);
        lsum -= temp;
        rsum += temp;
        answer++;
      }
      else if (lsum < rsum) {
        int temp = rq.front(); rq.pop();
        lq.push(temp);
        lsum += temp;
        rsum -= temp;
        answer++;
      }
      if (answer > 3 * queue1.size())
        return (-1);
    }
    return answer;
}
int main()
{
  ios::sync_with_stdio(false);
  vector<int> a;
  vector<int> b;

  // a.push_back(3);
  // a.push_back(2);
  // a.push_back(7);
  // a.push_back(2);
  // b.push_back(4);
  // b.push_back(6);
  // b.push_back(5);
  // b.push_back(1);


  // a.push_back(1);
  // a.push_back(2);
  // a.push_back(1);
  // a.push_back(2);
  // b.push_back(1);
  // b.push_back(10);
  // b.push_back(1);
  // b.push_back(2);
a.push_back(1);
a.push_back(1);
a.push_back(1);
a.push_back(1);
a.push_back(1);
a.push_back(1);
a.push_back(1);
a.push_back(1);
a.push_back(1);
a.push_back(1);
a.push_back(10);
b.push_back(1);
b.push_back(1);
b.push_back(1);
b.push_back(1);
b.push_back(1);
b.push_back(1);
b.push_back(1);
b.push_back(1);
b.push_back(1);
b.push_back(1);
b.push_back(1);

  int sol = solution(a, b);
  cout << sol << endl;
}


/*
queue1	queue2	result
[3, 2, 7, 2]	[4, 6, 5, 1]	2
[1, 2, 1, 2]	[1, 10, 1, 2]	7
[1, 1]	[1, 5]	-1
*/
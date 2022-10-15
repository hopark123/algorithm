#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;


string solution(vector<int> numbers, string hand) {
  pair<int, int> left(3, 0);
  pair<int, int> right(3, 2);
    string answer = "";
    for(auto nbr : numbers) {
      cout << nbr << endl;
      if (nbr % 3 == 1) {
        answer += "L";
        left.first = nbr / 3;
        left.second = 0;
      }
      else if (nbr % 3 == 0 && nbr != 0) {
        answer += "R";
        right.first = nbr / 3 - 1;
        right.second = 2;
      }
      else {
        pair<int, int> pt;
        pt.first = nbr / 3;
        pt.second = 1;
        if (nbr == 0)
          pt.first += 3;
        int left_dis = abs(left.first - pt.first) + abs(left.second - pt.second);
        int right_dis = abs(right.first - pt.first) + abs(right.second - pt.second);
        cout << left_dis << right_dis << endl;
        if (left_dis < right_dis || (left_dis == right_dis && hand == "left")) {
          left.first = pt.first;
          left.second = pt.second;
          answer += "L";
        }
        else {
          right.first = pt.first;
          right.second = pt.second;
          answer += "R";
        }
      }
      cout << answer[answer.size() - 1] << endl;
    }
    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  vector<int> a  = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
  string sol = solution(a, "left");
  cout << sol << endl;
}


/*
numbers	hand	result
[1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5]	"right"	"LRLLLRLLRRL"
[7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2]	"left"	"LRLLRRLLLRR"
[1, 2, 3, 4, 5, 6, 7, 8, 9, 0]	"right"	"LLRLLRLLRL"

*/
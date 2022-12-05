#include <string>
#include <vector>
#include <iostream>
using namespace std;


bool _compare(vector<int> a, vector<int> b) {
    if (a[0] < b[0])
        return true;
    else if (a[0] > b[0])
        return false;
    else
        return a[1] > b[1];
}

int solution(vector<vector<int>> flowers) {
    int answer = 0;
    sort(flowers.begin(), flowers.end(), _compare);
    int st = flowers[0][0];
    int end = flowers[0][1];
    
    for (int i = 1; i < flowers.size(); ++i) {
      if (flowers[i][0] > end) {
        answer += end - st;
        st = flowers[i][0];
      }
      end = max(end, flowers[i][1]);
    }
    answer += end - st;
    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  // vector<vector<int> > a = {{2, 5}, {3, 7}, {10, 11}};
  // vector<vector<int> > a = {{3, 4}, {4, 5}, {6, 7}, {8, 10}};
  vector<vector<int> > a = {{10, 12}, {1, 2}, {1, 13}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};

  int sol = solution(a);
  cout << sol << endl;
}


/*
{{10, 12}, {1, 2}, {1, 13}, {3, 4}, {4, 5}, {5, 6}, {6, 7}}
{{2, 5}, {3, 7}, {10, 11}}
{{3, 4}, {4, 5}, {6, 7}, {8, 10}}
*/
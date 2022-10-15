#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool ft_wall(vector<string> place, int y, int x) {
    if (x < 0 || x > 4 || y < 0 ||  y > 4) {
      return false;
    }
    return true; 
}
bool check(vector<string> place, int y, int x) {

  int flag = 0;
  if (place[y][x] == 'P') {
    for (int i = 0 ; i < 4; ++i) {
      if (ft_wall(place, y + dy[i], x + dx[i])) {
        if (place[y + dy[i]][x + dx[i]] == 'P') {
          return false;
        }
      }
    }
  }
  else if (place[y][x] == 'O') {
    for (int i = 0 ; i < 4; ++i) {
      if (ft_wall(place, y + dy[i], x + dx[i])) {
        if (place[y + dy[i]][x + dx[i]] == 'P') {
          ++flag;
        }
        if (flag >= 2) {
          return false;
        }
      }
    }
  }
  return true;
}

vector<int> solution(vector<vector<string> > places) {
    vector<int> answer;
    
    for (auto place : places) {
      int flag = true;
      for (int i = 0; flag && i < 5; i++) {
        for (int j = 0; flag && j < 5; j++) {
          flag = check(place, i, j);
        }
      }
      answer.push_back(flag);
    }
    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  vector<vector<string> > a;
  vector<string> b;
  b.push_back("POOOP");
  b.push_back("OXXOX");
  b.push_back("OPXPX");
  b.push_back("OOXOX");
  b.push_back("POXXP");
  a.push_back(b);
  b.clear();
  b.push_back("POOPX");
  b.push_back("OXPXP");
  b.push_back("PXXXO");
  b.push_back("OXXXO");
  b.push_back("OOOPP");
  a.push_back(b);

  b.clear();
  b.push_back("PXOPX");
  b.push_back("OXOXP");
  b.push_back("OXPOX");
  b.push_back("OXXOP");
  b.push_back("PXPOX");
  a.push_back(b);

  b.clear();
  b.push_back("OOOXX");
  b.push_back("XOOOX");
  b.push_back("OOOXX");
  b.push_back("OXOOX");
  b.push_back("OOOOO");
  a.push_back(b);

  b.clear();
  b.push_back("PXPXP");
  b.push_back("XPXPX");
  b.push_back("PXPXP");
  b.push_back("XPXPX");
  b.push_back("PXPXP");
  a.push_back(b);
  b.clear();

  vector<int> sol = solution(a);
  for (auto it : sol)
    cout << it << endl;
}


/*
[["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]	[1, 0, 1, 1, 1]
*/
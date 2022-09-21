#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
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
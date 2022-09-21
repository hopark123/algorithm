#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;


int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    return answer;
}


int main()
{
  ios::sync_with_stdio(false);
  vector<vector<string> > a;
  vector<string> b;
  b.push_back("100");
  b.push_back("ryan");
  b.push_back("music");
  b.push_back("2");
  a.push_back(b);
  b.clear();
  b.push_back("200");
  b.push_back("apeach");
  b.push_back("math");
  b.push_back("2");
  a.push_back(b);
  b.clear();
  b.push_back("300");
  b.push_back("tube");
  b.push_back("computer");
  b.push_back("3");
  a.push_back(b);
  b.clear();
  b.push_back("400");
  b.push_back("con");
  b.push_back("computer");
  b.push_back("4");
  a.push_back(b);
  b.clear();
  b.push_back("500");
  b.push_back("muzi");
  b.push_back("music");
  b.push_back("3");
  a.push_back(b);
  b.clear();
  b.push_back("600");
  b.push_back("apeach");
  b.push_back("music");
  b.push_back("2");
  a.push_back(b);
  b.clear();

  int sol = solution(a);
  cout << sol << endl;
}


/*
2
*/
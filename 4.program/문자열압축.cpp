#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;



bool check(string s, string word, int st) {
  for (int i = 0; i < word.length(); ++i) {
    if (s[st + i] != word[i]) {
      return false;
    }
  }
  return true;
}

int sol(string s, int len) {
  int i = 0;
  int res = 0;
  string temp;
  int cnt = 0;
  while (i + len < s.length()) {
    string word = s.substr(i, len);
    res += len;
    i += len;
    cnt = 0;
    while (check(s, word, i)) {
      cnt++;
      i += len;
    }
    if (cnt > 0) {
      temp += to_string(cnt + 1);
    }
    temp += word;
  }
  for (; i < s.length(); ++i)
    temp += s[i];
  res = temp.size();  
  return (res);
}

int solution(string s) {
    int answer = s.size();
    int length = 1;
    string temp = s;
    for (int i = 1; i <= s.size() / 2; ++i) {
      answer = min(answer, sol(s, i));
    }
    return answer;
}


int main()
{
  ios::sync_with_stdio(false);
  vector<vector<string> > a;
  vector<string> b;
}


/*
2
*/
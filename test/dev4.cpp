#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


vector<set<string> > split(vector<string> id_list) {
  vector<set<string> > id(id_list.size());
  for (int i = 0; i < id_list.size(); ++i) {
    int j = 0;
    while (j < id_list[i].size()) {
      int st = j;
      int end;
      while (j < id_list[i].size() && id_list[i][j] != ' ')
        ++j;
      end = j;
      ++j;
      string w = id_list[i].substr(st, end - st);
      id[i].insert(w);
    }
  }
  return id;
}

int solution(vector<string> id_list, int k) {
    int answer = 0;
    map<string, int> mp;
    vector<set<string> > id = split(id_list);
    for (int i = 0; i < id.size(); ++i) {
      for (auto w : id[i]) {
        if (mp[w]) {
          if (mp[w] < k)
            ++answer;
          ++mp[w];
        }
        else {
          ++answer;
          mp[w] = 1;
        }
      }
    }
    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  // vector<string> a = {"A B C D", "A D", "A B D", "B D"};
  // vector<string> a = {"JAY", "JAY ELLE JAY MAY", "MAY ELLE MAY", "ELLE MAY", "ELLE ELLE ELLE", "MAY"};
  vector<string> a;
  for (int i = 0; i < 1000; ++i)
    a. push_back("JAY ELLE JAY MAY");
  int sol = solution(a, 1);
  cout << sol << endl;
}


/*
{"A B C D", "A D", "A B D", "B D"}
{"JAY", "JAY ELLE JAY MAY", "MAY ELLE MAY", "ELLE MAY", "ELLE ELLE ELLE", "MAY"}
*/
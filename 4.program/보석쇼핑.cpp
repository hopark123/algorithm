#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.second - a.first == b.second - b.first)
    return a.first < b.first;
  return (a.second - a.first < b.second - b.first);

}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int> mp;
    set<string> st;
    int lo = 0, hi = 0;

    vector<pair<int, int> > vec;
    for(auto &it : gems) {
      st.insert(it);
    }
    while(1) {
      cout << mp.size() <<"="<< st.size() << endl;
      if (mp.size() == st.size()) {
        cout << "lo" << lo << endl;
        vec.push_back(make_pair(lo + 1, hi));
        if (mp[gems[lo]] == lo) {
          mp.erase(gems[lo]);
        }
        ++lo;
        if (hi > gems.size()) {
          break ;
        }
      }
      else {
        if (hi >= gems.size()) {
          break ;
        }
        cout << "hi[" << gems[hi] << "]:" << hi<< endl;
        mp[gems[hi]] = hi;
        ++hi;
      }
    }
    for (auto &it : vec) {
      cout << it.first << " " << it.second << endl;
    }
    sort(vec.begin(), vec.end(), comp);
    answer.push_back(vec[0].first);
    answer.push_back(vec[0].second);
    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  // vector<string> b = {"DIA", "RUBY",  "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
  // vector<string> b = {"AA", "AB", "AC", "AA", "AC"};
  // vector<string> b = {"XYZ", "XYZ", "XYZ"};
  vector<string> b = {"ZZZ", "YYY", "NNNN", "YYY", "BBB"};

  vector<int> sol = solution(b);
  for (auto &it : sol)
    cout << it << endl;
}


/*
gems	result
{"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"}	{3, 7}
{"AA", "AB", "AC", "AA", "AC"}	{1, 3}
{"XYZ", "XYZ", "XYZ"}	{1, 1}
{"ZZZ", "YYY", "NNNN", "YYY", "BBB"}	{1, 5}

*/
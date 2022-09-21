#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;


unordered_map<string, vector<int> > data_map;

vector<vector<string> > ft_split(vector<string> info) {
  vector<vector<string> > res;

  for (int i = 0; i < info.size(); ++i ) {
    int st = 0;
    int end = 0;
    vector<string> one_string;
    while (info[i][end]) {
      // cout <<"("<< info[i][end] <<")"<<endl;
      if (info[i][end] == ' ') {
        // cout << "this"<<info[i].substr(st, end - st) << endl;
        one_string.push_back(info[i].substr(st, end - st));
        st = end + 1;
      }
      ++end;
    }
    one_string.push_back(info[i].substr(st, end - st));
    res.push_back(one_string);
    one_string.clear();
  }
  return (res);
}

void make_data(vector<string> info_one) {
  for (int i = 0; i < 16; ++i) {
    string str;
    for (int j = 0; j < 4; ++j) {
        str += (i & (1 << j)) ? info_one[j] : "-";
    }
    data_map[str].push_back(atoi(info_one[4].c_str()));
  }
}

int ft_check(vector<string> query) {
  string k = query[0] + query[2] + query[4] + query[6];
  vector<int> res = data_map[k];
  
  int cnt = res.end() - lower_bound(res.begin(), res.end(), stoi(query[7]));
  return (cnt);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<vector<string > > s_query;
    vector<vector<string > > s_info;
    s_info = ft_split(info);
    s_query = ft_split(query);
    for (int i = 0 ; i < s_info.size(); ++i) 
      make_data(s_info[i]);
    for(auto &iter: data_map) 
      sort(iter.second.begin(), iter.second.end()); 
    for (int i = 0; i < s_query.size(); ++i) {
      answer.push_back(ft_check(s_query[i]));
    }
    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  vector<string> a;
  vector<string> b;
  
  a.push_back("java backend junior pizza 150");
  a.push_back("python frontend senior chicken 210");
  a.push_back("python frontend senior chicken 150");
  a.push_back("cpp backend senior pizza 260");
  a.push_back("java backend junior chicken 80");
  a.push_back("python backend senior chicken 50");
  b.push_back("java and backend and junior and pizza 100");
  b.push_back("python and frontend and senior and chicken 200");
  b.push_back("cpp and - and senior and pizza 250");
  b.push_back("- and backend and senior and - 150");
  b.push_back("- and - and - and chicken 100");
  b.push_back("- and - and - and - 150");
  vector<int> sol = solution(a, b);
  for (auto it : sol)
    cout << it << endl;
}


/*
*/
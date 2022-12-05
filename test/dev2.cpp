#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;

priority_queue<pair<int, string> > arr[5];

pair<string, vector<int> > split(string record) {
  string name;
  vector<int> cord;
  int i = 0;
  while (record[i] != ':') {
    name += record[i];
    ++i;
  }
  while (i < record.size()) {
    string temp;
    ++i;
    while (record[i] != ',' && i < record.size()) {
      temp += record[i];
      ++i;
    }
    cord.push_back(stoi(temp));
  }
  for (int i = 0; i < 5; ++i)
    if (cord[i] != 0) {
      arr[i].push({-cord[i], name});
    }
  // cout << name << "->";
  //   cout << cord[i] << ' ';
  // cout << endl;
  return {name, cord};
}



vector<string> solution(vector<string> record) {
    vector<string> answer;
    for (int i = 0; i < record.size(); ++i)
      split(record[i]);
    for (int i = 0; i < 5; ++i) {
      
    }
    cout << arr[0].top().second << endl;
    cout << arr[1].top().second << endl;
    cout << arr[2].top().second << endl;
    cout << arr[3].top().second << endl;
    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  vector<string> a = {"jack:9,10,13,9,15", "jerry:7,7,14,10,17", "jean:0,0,11,20,0", "alex:21,2,7,11,4", "kevin:8,4,5,0,0", "brown:3,5,16,3,18", "ted:0,8,0,0,8", "lala:0,12,0,7,9", "hue:17,16,8,6,10", "elsa:11,13,10,4,13"};
 
  vector<string> sol = solution(a);
  for (int i = 0; i < sol.size(); ++i)
    cout << sol[i] << endl;
}


/*
{"jack:9,10,13,9,15", "jerry:7,7,14,10,17", "jean:0,0,11,20,0", "alex:21,2,7,11,4", "kevin:8,4,5,0,0", "brown:3,5,16,3,18", "ted:0,8,0,0,8", "lala:0,12,0,7,9", "hue:17,16,8,6,10", "elsa:11,13,10,4,13"}

*/
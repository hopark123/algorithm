#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>

using namespace std;
bool arr[11];
string temp, item;
set<string> st;
map<string, int> mp;


string ft_word(string orders) {
  string res;
  for (int i = 0; i < orders.length(); ++i) {
    if (arr[i])
      res += orders[i];
  }
  sort(res.begin(), res.end());
  return res;
}

void ft_course(int index, int cnt, vector<int> course, string orders)
{
    if (find(course.begin(), course.end(), cnt) != course.end()) {
        string temp;
        temp = ft_word(orders);
        ++mp[temp];
    }
    if (cnt > 10)
        return;
    for (int i = index; i < orders.length(); ++i) {
      arr[i] = true;
      ft_course(i + 1, cnt + 1, course, orders);
      arr[i] = false;
    }
}




vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    fill(arr, arr + 10, false);
    for (auto &it : orders) {
        ft_course(0, 0, course, it);
    }
    for (auto &it : course) {
      int len = it;
      int max_cnt = 0;
      for (auto &itt : mp) {
        if (itt.first.length() == len) {
          max_cnt = max(max_cnt, itt.second);
        }
      }
      if (max_cnt < 2)
        continue;
      for (auto &itt : mp) {
        if (itt.first.length() == len && itt.second == max_cnt)
          answer.push_back(itt.first);
      }
    }
    stable_sort(answer.begin(), answer.end());
    return (answer);
}

int main()
{
    ios::sync_with_stdio(false);
    vector<string> a;
    vector<int> b;
    // a.push_back("ABCFG");
    // a.push_back("AC");
    // a.push_back("CDE");
    // a.push_back("ACDE");
    // a.push_back("BCFG");
    // a.push_back("ACDEH");
    // b.push_back(2);
    // b.push_back(3);
    // b.push_back(4);


    // a.push_back("ABCDE");
    // a.push_back("AB");
    // a.push_back("CD");
    // a.push_back("ADE");
    // a.push_back("XYZ");
    // a.push_back("XYZ");
    // a.push_back("ACD");
    // b.push_back(2);
    // b.push_back(3);
    // b.push_back(5);


    a.push_back("XYZ");
    a.push_back("XWY");
    a.push_back("XWA");
    b.push_back(2);
    b.push_back(3);
    b.push_back(4);

    // a.push_back("ABCDE");
    // a.push_back("ABCDE");
    // a.push_back("ABCDE");
    // a.push_back("ABCDE");
    // a.push_back("ABCDE");
    // a.push_back("ABCDE");
    // a.push_back("ABCDE");
    // b.push_back(2);
    // b.push_back(3);
    // b.push_back(5);
    vector<string> sol = solution(a, b);
    for (auto it = sol.begin(); it != sol.end(); ++it)
        cout << *it << endl;
}


// ["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"]	[2,3,5]	["ACD", "AD", "ADE", "CD", "XYZ"]
	// ["XYZ", "XWY", "WXA"], [2, 3, 4]
    // ["ABCDE", "ABCDE", "ABCDE", "ABCDE", "ABCDE", "ABCDE", "ABCDE"]
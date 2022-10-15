#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;

set<string> st;
vector<bool> visited;
vector<bool> ban;

string ft_answer(vector<string> user_id) {
  string res = "";
  for (int i = 0; i < visited.size(); ++i) {
    if(visited[i])
      res += user_id[i] + ' ';
  }
  return res;
}

bool ft_check(string user, string ban) {
  if (user.size() != ban.size())
    return false;
  for(int i = 0; i < ban.size(); ++i) {
    if (ban[i] != '*' && ban[i] != user[i])
      return false;
  }
  return true;
}

void dfs(vector<string> user_id, vector<string> banned_id, int index, int cnt) {

  // cout << "new" << endl;
  if (cnt == banned_id.size()) {
    st.insert(ft_answer(user_id));
    // cout << "[" << ft_answer(user_id) << "]" << endl;
    // cout << endl;
    return ;
  }
  if (index >= banned_id.size())
    return ;
  for (int i = index; i < banned_id.size(); ++i) {
    for (int j = 0; j < user_id.size(); ++j) {
      if (!visited[j] && ft_check(user_id[j], banned_id[i])) {
        // cout << i << "-" << cnt << endl;
        // cout << user_id[j] << "=" << banned_id[i] << endl;
        visited[j] = true;
        dfs(user_id, banned_id, i + 1, cnt + 1);
        visited[j] = false;
      }
    }
  }
}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    visited.resize(user_id.size(), false);
    // ban.resize(banned_id.size(), false);
    dfs(user_id, banned_id, 0, 0);
    cout << endl;

    for (auto it : st)
      cout << it << endl;
    answer = st.size();
    return answer;
}


int main()
{
  ios::sync_with_stdio(false);
  vector<string> a = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
  vector<string> b = {"*rodo", "*rodo", "******"};
  for (auto &it : a)
    cout << it << " ";
  cout << endl;
  for (auto &it : b)
    cout << it << " ";
  cout << endl;
 
  int sol = solution(a, b);
  cout << sol << endl;

}


/*
user_id	banned_id	result
{"frodo", "fradi", "crodo", "abc123", "frodoc"}	{"fr*d*", "abc1**"}	2
{"frodo", "fradi", "crodo", "abc123", "frodoc"}	{"*rodo", "*rodo", "******"}	2
{"frodo", "fradi", "crodo", "abc123", "frodoc"}	{"fr*d*", "*rodo", "******", "******"}	3

*/
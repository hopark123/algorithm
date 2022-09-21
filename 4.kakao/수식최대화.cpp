#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

int order[6][3] = {
    {1, 2, 3},
    {1, 3, 2},
    {2, 1, 3},
    {2, 3, 1},
    {3, 1, 2},
    {3, 2, 1}};

long long ft_eval(long long a, string cal, long long b)
{
  long long res;
  if (cal == "*")
    res = a * b;
  else if (cal == "-")
    res = a - b;
  else if (cal == "+")
    res = a + b;
  return res;
}

long long solution(string expression)
{
  long long answer = 0;
  vector<string> vec;
  int i = 0;
  while (expression[i])
  {
    string temp;
    if (expression[i] >= '0' && expression[i] <= '9')
    {
      string temp;
      while (expression[i] && expression[i] >= '0' && expression[i] <= '9')
      {
        temp += expression[i];
        ++i;
      }
      vec.push_back(temp);
    }
    if (expression[i])
    {
      string temp;
      temp += expression[i];
      vec.push_back(temp);
      ++i;
    }
  }
  long long max_nbr = 0;
  long long nbr1 = 0;
  for (int i = 0; i < 6; ++i)
  {
    map<string, int> mp;
    stack<long long> nbr;
    stack<string> cal;
    mp["*"] = order[i][0];
    mp["+"] = order[i][1];
    mp["-"] = order[i][2];
    for (int j = 0; j < vec.size(); ++j)
    {
      if (vec[j] == '*' || vec[j] == "+" || vec[j] == "-")
      {
        int now = mp[vec[j]];
        while (!cal.empty() && (mp[cal.top()] >= now))
        {
          long old_nbr1 = nbr.top();
          nbr.pop();
          long old_nbr2 = nbr.top();
          nbr.pop();
          string old_cal = cal.top();
          cal.pop();
          long long new_nbr = ft_eval(old_nbr2, old_cal, old_nbr1);
          nbr.push(new_nbr);
        }
        cal.push(vec[j]);
      }
      else
      {
        nbr.push(atoll(vec[j].c_str()));
        nbr.top();
      }
    }
    if (!nbr.empty())
    {
      nbr1 = nbr.top();
      nbr.pop();
    }
    while (!cal.empty())
    {
      long long nbr2 = nbr.top();
      nbr.pop();
      string old_cal = cal.top();
      cal.pop();
      nbr1 = ft_eval(nbr2, old_cal, nbr1);
    }
    max_nbr = max(max_nbr, llabs(nbr1));
  }
  answer = max_nbr;
  return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  string a = "100-200*300-500+20";
  // string a = "1-2*3-4";
  // string a = "50*6-3*2";

  long long sol = solution(a);
  cout << sol << endl;
}

#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>

using namespace std;
int arr[360010];

int time_to_sec(string time)
{
  int res = 0;
  res += stoi(time.substr(0, 2)) * 3600;
  res += stoi(time.substr(3, 2)) * 60;
  res += stoi(time.substr(6, 2));
  return res;
}

string time_to_str(int time)
{
  string res;
  int digit = 3600;
  while (digit) {
    int temp = time / digit;
    time %= digit;
    if (temp >= 0 && temp < 10)
      res+= "0";
    res += to_string(temp);
    digit /= 60;
    if (digit != 0)
     res += ":";
  }
  return (res);
}


bool com(pair<int, int> a, pair<int, int> b) {
  return a.first > b.first;
}


string solution(string play_time, string adv_time, vector<string> logs)
{
  string answer = "";
  int p_time = time_to_sec(play_time);
  int a_time = time_to_sec(adv_time);
  int spot;
  long long sum = 0;
  for (auto it : logs)
  {
    int t1 = time_to_sec(it.substr(0, 8));
    int t2 = time_to_sec(it.substr(9, 8));
    arr[t1] += 1;
    arr[t2] -= 1;
  }

  for (int i = 0; i < p_time; ++i)
    arr[i + 1] += arr[i];

  for (int i = 0; i < a_time; ++i)
    sum += arr[i];

  long long max_time = sum;

  for (int i = 0; i + a_time < p_time; ++i) {
    sum -= arr[i];
    sum += arr[i + a_time];
    if (sum > max_time) {
      max_time = sum;
      spot = i + 1;
    }
  }
  answer = time_to_str(spot);
  return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  vector<string> b;
  // b.push_back("00:00:01-00:00:03");
  // b.push_back("00:00:02-00:00:04");
  // b.push_back("00:00:04-00:00:05");
  // b.push_back("00:00:07-00:00:10");
  // string p = "00:00:10";
  // string q = "00:00:4";
  // b.push_back("00:00:01-00:00:03");
  b.push_back("01:20:15-01:45:14");
  b.push_back("00:40:31-01:00:00");
  b.push_back("00:25:50-00:48:29");
  b.push_back("01:30:59-01:53:29");
  b.push_back("01:37:44-02:02:30");
  string p = "02:03:55";
  string q = "00:14:15";
  string sol = solution(p, q, b);
  cout << sol << endl;
}

/*
play_time	adv_time	logs	result
"02:03:55"	"00:14:15"	["01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"]	"01:30:59"
"99:59:59"	"25:00:00"	["69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00"]	"01:00:00"
"50:00:00"	"50:00:00"	["15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45"]	"00:00:00"

*/
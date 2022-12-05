#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Time {
public :
  Time();
  Time(string s) {
    _y = stoi(s.substr(0, 4));
    _m = stoi(s.substr(5, 7));
    _d = stoi(s.substr(8, 10));
    _h = stoi(s.substr(11, 13));
    _t = stoi(s.substr(14, 16));
    _s = stoi(s.substr(17, 19));
    suc.push_back(_y * 10000 + _m * 100 + _d);
    cout << _y << "/" << _m << "/" << _d << " " << _h << ":" << _t << ":" << _s << endl;
  }

  Time add(string a) {
    _d += stoi(a.substr(0, 2));
    _h += stoi(a.substr(3, 5));
    _t += stoi(a.substr(6, 8));
    _s += stoi(a.substr(9, 11));
    if (_s >= 60) {  _s -= 60;  ++_t;}
    if (_t >= 60) {  _t -= 60;  ++_h;}
    if (_h >= 24) {  _h -= 24; ++_d;}
    if (_d > 30) {  _d -= 30; ++_m;}
    if (_m > 12) {  _m -= 12; ++_y;}
    cout <<a << "+" << _y << "/" << _m << "/" << _d << " " << _h << ":" << _t << ":" << _s << endl;
    suc.push_back(_y * 10000 + _m * 100 + _d);
    return (*this);
  }
  int _y, _m, _d, _h, _t, _s;
  vector<int> suc;
};

int cnt_day(int a, int b) {
  int st = a % 100;
  a /= 100;
  st += a % 100 * 30;
  a /= 100;
  st += a * 360; 

  int end = b % 100;
  b /= 100;
  end += b % 100 * 30;
  b /= 100;
  end += b * 360; 
  
  return end - st;
}

vector<int> solution(string s, vector<string> times) {
    vector<int> answer(2);
    Time date(s);
    for (int i = 0; i < times.size(); ++i) {
      date.add(times[i]);
    }
    answer[0] = 1;
    answer[1] = cnt_day(date.suc[0], date.suc[date.suc.size() - 1]) + 1;
    int st = date.suc[0];
    for (int i = 1; i < date.suc.size(); ++i) {
      
      if (cnt_day(st, date.suc[i]) > 1) {
        answer[0] = 0;
        break ;
      }
      st = date.suc[i];
    }
    return answer;
}


int main()
{
  ios::sync_with_stdio(false);
  // string a = "2021:04:12:16:08:35";
  // string a= "2021:04:12:16:08:35";
  string a= "2021:12:30:23:59:59";
  // vector<string> b =  {"01:06:30:00", "00:01:12:00"};
  // vector<string> b = {"01:06:30:00", "01:01:12:00", "00:00:09:25"};
  vector<string> b = {"00:00:00:00"};
  vector<int> sol = solution(a, b);
  cout << sol[0] << endl;
  cout << sol[1] << endl;
}


/*
"2021:12:30:23:59:59", ["00:00:00:01"]
"2021:04:12:16:08:35"   {"01:06:30:00", "01:04:12:00"}
"2021:04:12:16:08:35"   {"01:06:30:00", "00:01:12:00"}

*/
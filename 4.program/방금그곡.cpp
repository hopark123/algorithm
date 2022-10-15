#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <map>
#include <regex>
using namespace std;

int get_time(string a, string b)
{
  int start = atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 5).c_str()) * 1;
  int end = atoi(b.substr(0, 2).c_str()) * 60 + atoi(b.substr(3, 5).c_str()) * 1;
  return (end - start);
}
void ft_sharp(string &m) {
  size_t w;
  while ((w = m.find("C#")) != string::npos) {
    m.replace(w, 2, "c");
  }
  while ((w = m.find("D#")) != string::npos) {
    m.replace(w, 2, "d");
  }
  // while ((w = m.find("E#")) != string::npos) {
  //   m.replace(w, 2, "e");
  // }
  while ((w = m.find("F#")) != string::npos) {
    m.replace(w, 2, "f");
  }
  while ((w = m.find("G#")) != string::npos) {
    m.replace(w, 2, "g");
  }
  while ((w = m.find("A#")) != string::npos) {
    m.replace(w, 2, "a");
  }
  // while ((w = m.find("B#")) != string::npos) {
  //   m.replace(w, 2, "b");
  // }
}

string solution(string m, vector<string> musicinfos)
{
  string answer = "(None)";
  int max_time = 0;
  for (int i = 0; i < musicinfos.size(); ++i)
  {
    string split_music[4];
    int split_index = 0;
    int j = 0;
    int s = 0;
    for (int j = 0; j < musicinfos[i].size(); j++)
    {
      if (musicinfos[i][j] == ',')
      {
        split_music[split_index] = musicinfos[i].substr(s, j - s);
        ++split_index;
        s = j + 1;
      }
    }
    split_music[split_index] = musicinfos[i].substr(s, j - s);
    ft_sharp(m);
    ft_sharp(split_music[3]);
    int time = get_time(split_music[0], split_music[1]);
    string new_string;
    if (time > split_music[3].length())
      for (int j = 0; j < (time / split_music[3].length()) + 1; ++j)
      {
        new_string += split_music[3];
      }
    else
      new_string = split_music[3].substr(0, time);
    
    if (new_string.find(m) != string::npos && new_string[new_string.find(m) + m.size()] != '#')
    {
      if (time > max_time)
        answer = split_music[2];
      max_time = max(max_time, time);
    }
  }
  return answer;
}
int main()
{
  ios::sync_with_stdio(false);
  // string a = "CC#BCC#BCC#BCC#B";
  // string a = "ABC";
  vector<string> b;
  // b.push_back("03:00,03:30,FOO,CC#B");
  // b.push_back("04:00,04:08,BAR,CC#BCC#BCC#B");

  // string a = "ABC";
  // b.push_back("12:04,13:00,HELLO,ABC#ABC#ABC");

  string a = "ABC";
  b.push_back("13:00,15:05,aaaa,ABCDEF");
  b.push_back("13:00,15:05,bbbb,ABCDEF");
  b.push_back("13:00,13:05,WORLD,ABCDEF");
  // string a = "C#C";
  // b.push_back("12:00,12:06,HELLO,C#C#CC#");
  // string a = "C#C";
  // b.push_back("00:00,00:00,HELLO,C#C#CC#");
  string sol = solution(a, b);
  cout << sol << endl;
}
/*
"ABCDEFG"	["12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"]	"HELLO"
"CC#BCC#BCC#BCC#B"	["03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"]	"FOO"
"ABC"	["12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"]
*/
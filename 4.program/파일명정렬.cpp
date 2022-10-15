#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <regex>
#include <string.h>
#include <algorithm>

using namespace std;


vector<string> ft_split(int index, string s) {
  vector<string> answer;
  int i = 0;
  char c = '0' + index;
  answer.push_back(string(&c));
  while (s[i]) {
    if (s[i] >= '0' && s[i] <= '9')
      break ;
    ++i;
  }
  answer.push_back(s.substr(0, i));
  int k = 0;
  while (s[i + k]) {
    if ((s[i + k] < '0' || s[i + k] > '9') || k > 4)
      break ;
    ++k;
  }
  answer.push_back(s.substr(i, k));
  int j = 0;
  while (s[i + k + j])
    ++j;
  if (j != 0) {
    answer.push_back(s.substr(i + k, j));
  }
  // cout << "0["<<answer[0] << "]"<< endl;
  // cout << "1["<<answer[1]<<"]" << endl;
  // if (answer.size() >= 3) {
  //   cout << "2["<<answer[2] <<"]"<< endl;
  // }
  return answer;
}


bool compare(vector<string> a, vector<string> b) {
  int com = strcasecmp((a)[1].c_str(), (b)[1].c_str());
  if (com < 0)
    return true;
  else if (com > 0) {
      return false;
  }
  else {
    if (stoi(a[2]) < stoi(b[2]))
      return true;
    else
      return false;
  }
  
}

vector<string> solution(vector<string> files)
{
  vector<string> answer;
  vector<vector<string> > answer_split;
  
  int index = 0;
  for (auto it = files.begin(); it != files.end(); ++it)
  {
    answer_split.push_back(ft_split(index++, *it));
  }
  stable_sort(answer_split.begin(), answer_split.end(), compare);
  for (auto it = answer_split.begin(); it != answer_split.end(); ++it) {
    string temp;
    temp = (*it)[1] + (*it)[2];
    if ((*it).size() >= 4) {
      temp += (*it)[3];
    }
    answer.push_back(temp);
  }
  return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  vector<string> a;
  a.push_back("ABC12");
  a.push_back("aBc12");
  a.push_back("AbC12");

  a.push_back("img12.png");
  a.push_back("img10.png");
  a.push_back("img02.png");
  a.push_back("img2.JPG");
  a.push_back("img02.png");
  a.push_back("img2.JPG");
  a.push_back("img1.png");
  a.push_back("IMG01.GIF");
  a.push_back("img1.png");
  a.push_back("IMG01.GIF");

  a.push_back("F-5 Freedom Fighter");
  a.push_back("B-50 Superfortress");
  a.push_back("A-10 Thunderbolt II");
  a.push_back("F-14 Tomcat");
  a.push_back("O00321");
  a.push_back("O49qcGPHuRLR5FEfoO00321");
  a.push_back("O1234567");
  a.push_back("F15");
  a.push_back("A000002");
  a.push_back("A00000");
  a.push_back("A0001234567");
  a.push_back("foo.a-s.d122.zip");
  vector<string> sol = solution(a);
  for (vector<string>::iterator it = sol.begin(); it != sol.end(); ++it)
    cout << *it << endl;
}

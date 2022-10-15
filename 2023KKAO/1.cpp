#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> ft_split(string str) {
  vector<string> res;
  res.push_back(str.substr(0,4));
  res.push_back(str.substr(5,2));
  res.push_back(str.substr(8,2));
  if (str.size() > 11)
  res.push_back(str.substr(11,1));
  return (res);
}



bool ft_check(string today, vector<string> vec, vector<string> terms) {
  string month;
  for (int i = 0; i < terms.size(); ++i) {
    char c = terms[i][0];
    // cout << c << "@"  << *(vec[3].c_str()) << endl;
    if (c == *(vec[3].c_str())) {
      month = terms[i].substr(2);
    }
  }
  vector<string> today_string = ft_split(today);
  vector<int> int_today;
  vector<int> int_vec;
  for (int i = 0; i < 3; i++) {
    int_today.push_back(stoi(today_string[i]));
  }
  for (int i = 0; i < 3; i++) {
    int_vec.push_back(stoi(vec[i]));
  } 

  int int_month = stoi(month);
  int_vec[0] += int_month / 12;
  int_vec[1] += int_month % 12;
  if (int_vec[1] > 12) {
    int_vec[1] -= 12;
    ++int_vec[0];
  }
  for (int i = 0; i < 3; ++i)
  if (int_today[0] > int_vec[0]) {
    return (true);
  }
  else if (int_today[0] < int_vec[0]) {
    return false;
  }
  else {
    if (int_today[1] > int_vec[1]) {
      return (true);
    }
    else if (int_today[1] < int_vec[1]) {
      return (false);
    }
    else{
        if (int_today[2] >= int_vec[2])
        return (true);
        return false;
    }
  }
  return (true);
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    for (int i = 0; i < privacies.size(); ++i) {
      vector<string> temp = ft_split(privacies[i]);
      if (ft_check(today, temp, terms))
        answer.push_back(i + 1);
    }
    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  vector<string> a;
  vector<string> b;
  string today = "2022.05.19";
  a.push_back("A 6");
  a.push_back("B 12");
  a.push_back("C 3");
  b.push_back("2021.05.02 A");
  b.push_back("2021.07.01 B");
  b.push_back("2022.02.19 C");
  b.push_back("2022.02.20 C");

  // string today = "2020.01.01";
  // a.push_back("Z 3");
  // a.push_back("D 5");

  // b.push_back("2019.01.01 D");
  // b.push_back("2019.11.15 Z");
  // b.push_back("2019.08.02 D");
  // b.push_back("2019.07.01 D");
  // b.push_back("2018.12.28 Z");
  vector<int> sol = solution(today, a, b);
  for(auto it : sol)
    cout << it << endl;
}


/*
"2022.05.19"
["A 6", "B 12", "C 3"]
["2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"]
*/
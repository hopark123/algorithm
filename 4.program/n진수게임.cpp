#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;


string arr[17] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

string makeNum(int nota, int num) {
  string res;
  string rev;
  if (num == 0)
    res += "0";
  while (num > 0) {
    rev += arr[num % nota];
    num = num / nota;
  }
  for (int i = rev.length() - 1; i >= 0; --i)
    res += rev[i];
  return (res);
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string temp = "";
    int i = 0;
    while (temp.length() < (t + 1) * m) {
      temp += makeNum(n, i);
      ++i;
    }
    for (int i = 0; i < t; ++i) {
      answer += temp[m * i + p - 1];
    }
    cout << temp << endl;
    cout << answer;

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    string sol = solution(16,	16,	2,	2);
    cout << sol << endl;
}

#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;

int res = 1;
int arr[6] = {1, 3, 7, 15, 31, 63};

string bin(long long nbr)
{
  string str;
  while (nbr != 0)
  {
    if (nbr % 2 == 1)
      str += '1';
    else
      str += '0';
    nbr /= 2;
  }
  return (str);
}

int guild(int len) {
  for (int i = 0; i < 7; ++i) {
    if (arr[i]>= len)
      return (arr[i] - len);
  }
  return (0);
}

int check(string str, int index, int len)
{
  cout <<"index[" << index<<"]" << len << endl;
  if (index > len) {
    return (true);
  }
  if (index < 0) { 
    cout << "end" << endl;
    return (true);
  }
  if (index >= 4) {
    check(str, index - index / 2, len);
    check(str, index + index / 2, len);
  }
  if (str[(index - 1)] == '0') {
    cout << "@@0" << endl;
    res = false;
    return false;
  }
  else {
    cout << "*1*" << endl;
    return true;
  }
  if (index % 2 != 0) {
    ++index;
  }
}



vector<int> solution(vector<long long> numbers)
{
  vector<int> answer;
  for (auto number : numbers)
  {
    string temp = bin(number);
    cout << temp << endl;
    // cout << guild(temp.size());
    int size = guild(temp.size());
    for (int i = 0; i < size; ++i) { 
      temp += '0';
    }
    res = 1;
    int flag = check(temp, (temp.size() + 1) / 2, temp.size() - size);
    answer.push_back(flag);
  }
  return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  vector<long long> a;
  // a.push_back(7);
  // a.push_back(5);
  // a.push_back(63);
  // a.push_back(111);
  a.push_back(95);
  // a.push_back(43);
  vector<int> sol = solution(a);
  for (auto it : sol)
    cout << it << endl;
}

/*

numbers(long[])
[7, 5]
[63, 111, 95]

Return
Return
[1, 0]
[1, 1, 0]
*/
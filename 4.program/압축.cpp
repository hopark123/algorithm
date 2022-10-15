#include <string>
#include <vector>
#include <iostream>
using namespace std;



int ft_find(vector<string> *dict, string msg) {
  size_t len = 1;
  int res = -1;
  string find;
  for (size_t  i = 0; i < dict->size(); ++i) {
    find = msg.substr(0, len);
    // cout << "[" << find  <<"][" << (*dict)[i] << "]"<< endl;
    if ((*dict)[i] == find) {
      res = i;
      // cout << "find "<<find << endl;
      if (len == msg.size()) {
        // cout << "@@@@@@@@@@@" << endl;
        break ;
      }
      ++len;
    }
  }
  find = msg.substr(0, len);
  // cout << "find @" << find <<  res << endl;
  dict->push_back(find);
  return (res);
}

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> dict;
    for (int i = 0; i < 26; ++i) {
      char alpha = 'A' + i;
      string a = "";
      a.push_back(alpha);
      dict.push_back(a);
    }
    for (size_t i = 0; i < msg.size(); ++i) {
      string temp = msg.substr(i);
      // cout << "================\ni[" << &msg[i] << "]";
      int res = ft_find(&dict, temp);
      // cout << "res" << res << (dict)[res - 1] << endl;
      
      // for (size_t j = 0; j < dict.size(); ++j)
        // cout << (dict)[j] << "*";
      // cout << endl;
      // cout << "dict " <<dict[res] << res << " " <<dict[res].length() << endl;
      i += dict[res].length() - 1;
      answer.push_back(res + 1);
    }
    return answer;
}

int main()
{
	ios::sync_with_stdio(false);
  vector<int> sol = solution("ABABABABABABABAB");
  for (size_t i = 0; i < sol.size(); ++i)
    cout << sol[i] << endl;
}

/*
[1, 2, 27, 29, 28, 31, 30]
1
2
27
29
28
29
31
A B AB ABA BA BABABAB
A 1 AB(27)
B 2 BA(28)
AB 27 ABA(29)
ABA 29 ABABA(30)
BA 28 BAB(31)
BAB 31 
*/

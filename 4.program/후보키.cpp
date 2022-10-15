#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;


bool combine[8] = {0,0,0,0,0,0,0,0};
vector<string> combine_vec;
vector<string> unique_vec;
vector<string> mini_vec;

void ft_dfs(int index, int cnt, int size, int column_size) {
  if (cnt == size) {
    string combi;
    for (int i = 0; i < column_size; ++i) {
      if (combine[i]) {
        combi += to_string(i);
      }
    }
    combine_vec.push_back(combi);
    return ;
  }
  for (int i = index; i < column_size; ++i) {
    combine[i] = true;
    ft_dfs(i + 1, cnt + 1, size, column_size);
    combine[i] = false;
  }
}

void ft_unique(vector<vector<string> > relation) {
  for (auto combi : combine_vec) {
    set<string> st;
    bool flag = true;
    for (int i = 0; i < relation.size(); ++i) {
      string temp;
      for (auto s : combi) {
        int col = s - '0';
        temp+= relation[i][col] + '*';
      }
      flag = (st.insert(temp)).second;
      if (!flag)
        continue ;
    }
    if (flag)
      unique_vec.push_back(combi);
  }
}

void ft_mini(string unique) {
  for (int i = 0; i < mini_vec.size(); ++i) {
    int flag = mini_vec[i].length();
    // cout << "[" << unique << "][" << mini_vec[i] << "]" << flag << endl;
    for (int j = 0; j < mini_vec[i].length(); ++j) {
      // cout << "find" << mini_vec[i][j] << endl;
      if (unique.find(mini_vec[i][j]) != string::npos) {
        // cout << "OOOO" << endl;
        --flag;
      }
      // else
        // cout << "XXXXX" << endl;

    }
    // cout << unique <<"]["<< flag << endl;
    if (flag == 0)
      return ;
  }
  mini_vec.push_back(unique);
}

int solution(vector<vector<string> > relation) {
    int answer = 0;
    for (int i = 1; i <= relation[0].size(); ++i) {
      ft_dfs(0, 0, i, relation[0].size());
      ft_unique(relation);
      for (int k = 0; k < unique_vec.size(); ++k) {
        // cout << "unique"<<unique_vec[k] << endl;
        ft_mini(unique_vec[k]);
      }
      // cout << "mini"<<endl;
      // for(auto it :mini_vec)
        // cout << it << endl;
      combine_vec.clear();
      unique_vec.clear();
      // cout << "====================" << i<<endl;
    }
  for(auto it :mini_vec) {
    // cout << "res[" << it << "]"<< endl;
    answer = mini_vec.size();
  }
  return answer;
}


int main()
{
  ios::sync_with_stdio(false);
  vector<vector<string> > a;
  vector<string> b;
  // b.push_back("100");
  // b.push_back("ryan");
  // b.push_back("music");
  // b.push_back("2");
  // a.push_back(b);
  // b.clear();
  // b.push_back("200");
  // b.push_back("apeach");
  // b.push_back("math");
  // b.push_back("2");
  // a.push_back(b);
  // b.clear();
  // b.push_back("300");
  // b.push_back("tube");
  // b.push_back("computer");
  // b.push_back("3");
  // a.push_back(b);
  // b.clear();
  // b.push_back("400");
  // b.push_back("con");
  // b.push_back("computer");
  // b.push_back("4");
  // a.push_back(b);
  // b.clear();
  // b.push_back("500");
  // b.push_back("muzi");
  // b.push_back("music");
  // b.push_back("3");
  // a.push_back(b);
  // b.clear();
  // b.push_back("600");
  // b.push_back("apeach");
  // b.push_back("music");
  // b.push_back("2");
  // a.push_back(b);
  // b.clear();


    b.push_back("a");
    b.push_back("1");
    b.push_back("1");
    b.push_back("1");
    a.push_back(b);
    b.clear();
    b.push_back("a");
    b.push_back("0");
    b.push_back("1");
    b.push_back("1");
    a.push_back(b);


  // b.push_back("a");
  // b.push_back("aa");
  // a.push_back(b);
  // b.clear();
  // b.push_back("aa");
  // b.push_back("a");
  // a.push_back(b);
  // b.clear();
  //   b.push_back("a");
  // b.push_back("a");
  //   a.push_back(b);
  // b.clear();

  // b.push_back("a");
  // b.push_back("1");
  // b.push_back("aaa");
  // b.push_back("c");
  // b.push_back("ng");
  // a.push_back(b);
  // b.clear();
  // b.push_back("a");
  // b.push_back("1");
  // b.push_back("bbb");
  // b.push_back("e");
  // b.push_back("g");
  // a.push_back(b);
  // b.clear();
  // b.push_back("c");
  // b.push_back("1");
  // b.push_back("aaa");
  // b.push_back("d");
  // b.push_back("ng");
  // a.push_back(b);
  // b.clear();
  // b.push_back("d");
  // b.push_back("2");
  // b.push_back("bbb");
  // b.push_back("d");
  // b.push_back("ng");
  // a.push_back(b);
  // b.clear();

  // b.push_back("a");
  // b.push_back("1");
  // b.push_back("aaa");
  // b.push_back("c");
  // b.push_back("ng");
  // a.push_back(b);
  // b.clear();
  //   b.push_back("a");
  // b.push_back("1");
  // b.push_back("bbb");
  // b.push_back("e");
  // b.push_back("g");
  // a.push_back(b);
  // b.clear();
  //   b.push_back("c");
  // b.push_back("1");
  // b.push_back("aaa");
  // b.push_back("d");
  // b.push_back("ng");
  // a.push_back(b);
  // b.clear();
  //   b.push_back("d");
  // b.push_back("2");
  // b.push_back("bbb");
  // b.push_back("d");
  // b.push_back("ng");
  // a.push_back(b);
  // b.clear();
  
  
  
  // b.push_back("1");
  // b.push_back("1");
  // a.push_back(b);
  // b.clear();
  // b.push_back("1");
  // b.push_back("2");
  // a.push_back(b);


  // b.push_back("a");
  // b.push_back("b");
  // b.push_back("c");
  // a.push_back(b);
  // b.clear();
  // b.push_back("1");
  // b.push_back("b");
  // b.push_back("c");
  // a.push_back(b);
  // b.clear();
  //   b.push_back("a");
  // b.push_back("b");
  // b.push_back("4");
  // a.push_back(b);
  // b.clear();
  //   b.push_back("a");
  // b.push_back("5");
  // b.push_back("c");
  // a.push_back(b);
  // b.clear();


  //   b.push_back("a");
  // b.push_back("1");
  // b.push_back("4");
  // a.push_back(b);
  // b.clear();
  //     b.push_back("2");
  // b.push_back("1");
  // b.push_back("5");
  // a.push_back(b);

  // b.clear();
  //     b.push_back("a");
  // b.push_back("2");
  // b.push_back("4");
  // a.push_back(b);
  // b.clear();
  //   b.push_back("a");
  // b.push_back("1");
  // b.push_back("4");
  // a.push_back(b);
  // b.clear();
  //     b.push_back("2");
  // b.push_back("1");
  // b.push_back("5");
  // a.push_back(b);
  // b.clear();
  //     b.push_back("a");
  // b.push_back("2");
  // b.push_back("4");
  // a.push_back(b);
  b.clear();
  int sol = solution(a);
  cout << sol << endl;
}


/*
a,b,c
1,b,c
a,b,4
a,5,c
결과값1

[["a", "1", "4"],
["2", "1", "5"],
["a", "2", "4"]]

> 정답: 2

[["100", "r"],
["200", "c"],
["300", "d"]]

> 정답: 2


a,1,4
2,1,5
a,2,4
결과값2
case1: [['a',1,'aaa','c','ng'],['b',1,'bbb','c','g'],['c',1,'aaa','d','ng'],['d',2,'bbb','d','ng']] 답 : 3 (0,23,134)
case2: [["a","1","aaa","c","ng"],["a","1","bbb","e","g"],["c","1","aaa","d","ng"],["d","2","bbb","d","ng"]] 답: 5 (02, 03, 04, 13, 23)
[["a","aa"],["aa","a],["a,a"]]
*/
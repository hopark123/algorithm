#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <unistd.h>
using namespace std;

int solution(vector<vector<int> > board, vector<int> moves)
{
  int answer = 0;
  int n = board.size();
  int m = board[1].size();
  stack<int> s;
  stack<int> bo[31];
  s.push(0);
  for (size_t i = 0; i < n; ++i)
  {
    for (size_t j = 0; j < m; ++j)
    {
      if (board[n - i - 1][j] != 0) {
        bo[j].push(board[n - 1 - i][j]);
      }
    }
  }

  for (vector<int>::iterator it = moves.begin(); it != moves.end(); ++it)
  {

    if (bo[(*it) - 1].empty())
      continue;
    int crain = bo[(*it) - 1].top();
    bo[(*it) - 1].pop();
    // cout << "c"<<crain << endl;
// PTKABEPTKACDKA
    if (crain)
    {
      s.push(crain);
      while (1)
      {
        if (s.size() <= 1)
          break ;
        int temp = s.top();
        s.pop();
        // cout << temp << "==?" << s.top() << endl;
        if (temp != s.top())
        {

          s.push(temp);
          break;
        }

        s.pop();
        ++answer;
      }
    }
    // cout<<endl;
  }
  return (answer * 2);
}

int main()
{
  ios::sync_with_stdio(false);
  vector<vector<int> > a;
  vector<int> b;
  b.push_back(0);
  b.push_back(0);
  b.push_back(0);
  b.push_back(0);
  b.push_back(0);
  a.push_back(b);
  b.clear();

  b.push_back(0);
  b.push_back(0);
  b.push_back(1);
  b.push_back(0);
  b.push_back(1);
  a.push_back(b);
  b.clear();

  b.push_back(0);
  b.push_back(1);
  b.push_back(1);
  b.push_back(0);
  b.push_back(1);
  a.push_back(b);
  b.clear();

  b.push_back(1);
  b.push_back(1);
  b.push_back(1);
  b.push_back(1);
  b.push_back(1);
  a.push_back(b);
  b.clear();

  b.push_back(1);
  b.push_back(1);
  b.push_back(1);
  b.push_back(1);
  b.push_back(1);
  a.push_back(b);
  b.clear();

  b.push_back(1);
  b.push_back(5);
  b.push_back(3);
  b.push_back(5);
  b.push_back(1);
  b.push_back(2);
  b.push_back(1);
  b.push_back(4);
  int sol = solution(a, b);
  cout << sol << endl;
}

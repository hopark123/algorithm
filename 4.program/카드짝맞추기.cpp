#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;

int cnt;
int x, y;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

vector<vector<pair<int, int>>> card_pos;

vector<string> ft_pair_order(int n)
{
  vector<string> res;
  for (int i = 0; i < pow(2, n); ++i)
  {
    string temp;
    int nbr = i;
    for (int j = 0; j < n; ++j)
    {
      int rest = nbr % 2;
      nbr /= 2;
      temp += to_string(rest);
    }
    res.push_back(temp);
  }
  return res;
}

bool ft_can(int y, int x)
{

  return (y >= 0 && y < 4 && x >= 0 && x < 4);
}

typedef struct t_info
{
  int y;
  int x;
  int cnt;
} info;

int bfs(vector<vector<int>> &board, pair<int, int> dest)
{
  vector<vector<int>> visited;
  visited.resize(4, vector<int>(4, 1e7));

  queue<info> q;
  int res = 1e7;
  info temp;
  temp.y = y;
  temp.x = x;
  temp.cnt = 0;
  q.push(temp);
  int cnt = 0;
  cout << board[y][x] << "[" << y << "][" << x << "]->"<< board[dest.first][dest.second] << "[" << dest.first << "][" << dest.second << "]" << endl;
  while (!q.empty())
  {
    info now = q.front(); q.pop();
    visited[now.y][now.x] = now.cnt;
    cout << "now[" << now.y <<"][" << now.x << "]" << now.cnt << endl;
    if (now.y == dest.first && now.x == dest.second) {
      y = now.y;
      x = now.x;
      board[now.y][now.x] = 0;
      cout << "clear"<< now.cnt + 1 << endl;
      res = min(res, now.cnt + 1);
      continue;
    }
    // if (board[now.y][now.x] != 0)
    //   continue;
    for (int i = 0; i < 4; ++i) {
      info next;
      next.y = now.y + dy[i];
      next.x = now.x + dx[i];
      next.cnt = now.cnt + 1;
      if (ft_can(next.y, next.x) && visited[next.y][next.x] > next.cnt) {
        cout << "push1[" << next.y <<"][" << next.x << "]" << board[next.y][next.x] << endl;
        q.push(next);
        bool flag = false;
        if (board[next.y][next.x] == 0) {
          while (ft_can(next.y + dy[i], next.x + dx[i]) ) {
            next.y += dy[i];
            next.x += dx[i];
            flag = true;
            if (board[next.y][next.x] != 0)
              break ;
          }
            if (flag) {
              cout << "push2[" << next.y <<"][" << next.x << "]" << board[next.y][next.x] << endl;
              if (visited[next.y][next.x] > next.cnt)
                q.push(next);
            }
          }
      }
    }
  }
  return res;
}

int solution(vector<vector<int>> board, int r, int c)
{
  int answer = 1e7;
  string card;
  card_pos.resize(7);
  vector<vector<int>> boards;
  boards.resize(4, vector<int>(4, 0));
  for (int i = 0; i < 4; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
      if (board[i][j] != 0)
      {
        card_pos[board[i][j]].push_back(make_pair(i, j));
      }
    }
  }
  for (int i = 0; i <= 6; ++i)
  {
    if (card_pos[i].size() != 0)
      card += to_string(i);
  }
  do
  {
    vector<string> pair_order = ft_pair_order(card.size());
    for (int i = 0; i < pair_order.size(); ++i)
    {
      y = r;
      x = c;
      int res = 0;
      for (int t = 0; t < 4; ++t) {
        for (int k = 0; k < 4; ++k)
          boards[t][k] = board[t][k];
      }
      cout << card << " "<< pair_order[i] << endl;
      for (int j = 0; j < card.size(); ++j)
      {
        int temp;
        if (pair_order[i][j] == '0')
        {
          temp = bfs(boards, card_pos[card[j] - '0'][0]);
          if (temp == 1e7)
            break ;
          res += temp;
          temp = bfs(boards, card_pos[card[j] - '0'][1]);
          if (temp == 1e7)
            break ;
          res += temp;
        }
        else
        {
          temp = bfs(boards, card_pos[card[j] - '0'][1]);
          if (temp == 1e7)
            break ;
          res += temp;
          temp = bfs(boards, card_pos[card[j] - '0'][0]);
          if (temp == 1e7)
            break ;
          res += temp;
        }
        cout << "res" << res << endl;
        cout << endl;
      }
      cout << "lastres" << res << endl;
      cout << endl;
      if (res != 0)
        answer = min(answer, res);
    }
  } while (next_permutation(card.begin(), card.end()));
  return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  // vector<vector<int> > a = {{1,0,0,3},{2,0,0,0},{0,0,0,2},{3,0,1,0}};
  // vector<vector<int> > a = {{3, 0, 0, 2}, {0, 0, 1, 0}, {0, 1, 0, 0}, {2, 0, 0, 3}};
  vector<vector<int>> a = {{1, 5, 0, 2}, {6, 4, 0, 0}, {0, 2, 1, 5}, {0, 0, 6, 4}};
  int sol = solution(a, 1, 0);
  cout << sol << endl;
}

/*
board	r	c	result
{{1,0,0,3],{2,0,0,0],[0,0,0,2],[3,0,1,0]]	1	0	14
[[3,0,0,2],[0,0,1,0],[0,1,0,0],[2,0,0,3]]	0	1	16

*/
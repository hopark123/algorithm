#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<vector<bool> > visited;
int cnt = 0;

bool ft_wall(int y, int x, vector<vector<int> > picture) {
  if (x < 0 || x >= picture[0].size() || y < 0 || y >= picture.size() || picture[y][x] == 0)
    return false;
  return true;
}

int ft_cnt(int y, int x, int nbr, vector<vector<int> > &picture) {
  int flag = 0;
  visited[y][x] = true;
  picture[y][x] = 0;
  ++cnt;
  // for (int i = 0; i < picture.size(); ++i ){
  //     for (int j = 0; j < picture[i].size(); ++j) {
  //       cout << picture[i][j] << " ";
  //     }
  //     cout << endl;
  // }
  //   cout << endl;
  for (int i = 0; i < 4; ++i) {
    int ty = y + dy[i];
    int tx = x + dx[i];
    if (ft_wall(ty, tx, picture)) {
      if (picture[ty][tx] == nbr) {
        // cout <<"A"<< cnt << endl;
        // cout <<"B" << cnt << endl;
        ft_cnt(ty, tx, nbr, picture);
      }
    }
    else
      ++flag;
  }
  // cout << "cnt" << cnt << " " << nbr << endl;
  return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    visited.resize(picture.size());
    for (int i = 0; i < picture.size(); ++i )
        visited[i].resize(picture[i].size());

    for (int i = 0; i < picture.size(); ++i ){
      for (int j = 0; j < picture[i].size(); ++j) {
          if (picture[i][j] !=0) {
            cnt = 0;
            // cout << picture[i][j] <<"==============="<< endl;
            max_size_of_one_area = max(max_size_of_one_area, ft_cnt(i, j, picture[i][j], picture));
            ++number_of_area;
          }
      }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}


int main()
{
  ios::sync_with_stdio(false);
  vector<vector<int> > a;
  vector<int> b;
  b.push_back(1);
  b.push_back(1);
  b.push_back(1);
  b.push_back(0);
  a.push_back(b);
  b.clear();
  b.push_back(1);
  b.push_back(2);
  b.push_back(2);
  b.push_back(0);
  a.push_back(b);
  b.clear();
    b.push_back(1);
  b.push_back(0);
  b.push_back(0);
  b.push_back(1);
  a.push_back(b);
  b.clear();
  b.push_back(0);
  b.push_back(0);
  b.push_back(0);
  b.push_back(1);
  a.push_back(b);
  b.clear();
  b.push_back(0);
  b.push_back(0);
  b.push_back(0);
  b.push_back(3);
  a.push_back(b);
  b.clear();
      b.push_back(0);
  b.push_back(0);
  b.push_back(0);
  b.push_back(3);
  a.push_back(b);
  b.clear();
  vector<int> sol = solution(7, 4, a);
  for(auto it : sol)
    cout << it << endl;
}


/*
6	4	[[1, 1, 1, 0], [1, 2, 2, 0], [1, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 3], [0, 0, 0, 3]]	[4, 5]
*/
#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;

int N, M;

bool cnt(int low, int high, int y, int x, vector<string> img, int size) {
  int black = 0;
  int white = 0;
  for (int i = 1; i < size; ++i) {
    for (int j = 1; j < size; ++j) {
      if (img[y + i][x + j] == '#')
        ++black;
      else
        ++white;
    }
  }
  int cal = black * 100  / (size - 1) / (size - 1);
  cout << "[" << black << "][" << white << "]" << cal << endl;
  if (low <= cal && cal < high) {
    cout << "true" << endl;
    return true;
  }

  return false;
}

bool bold(int y, int x, vector<string> img, int size) {
  for (int i = 0; i <= size; ++i) {
    if (img[y][x + i] != '#' || img[y + size][x + i] != '#' || img[y + i][x] != '#' || img[y + i][x + size] != '#')
      return false;
  }
  cout << "tr" << size << endl;
  return true;
}

int solution(int low, int high, vector<string> img) {
    int answer = 0;
    N = img.size();
    M = img[0].size();
    for (int i = 0; i < N; ++i)
      cout << img[i] << endl;
    cout << endl;
    cout << endl;

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        for (int k = 2; i + k < N && j + k < M; ++k) {
          if (bold(i, j, img, k)) {
            for (int m = 0; m <= k; ++m) {
              for (int w = 0; w <= k; ++w) {
                cout << img[i + m][j + w];
              }
              cout << endl;
            }
            if (cnt(low, high, i, j, img, k))
              ++answer;
            cout << endl;
            cout << endl;
          }
        }
      }
    }
    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  vector<string> a = {".########......", ".####...#......", ".#.####.#.#####", ".#.#..#.#.#..##", ".#.##.#.#.#...#", ".#.####.#.#...#", ".#....###.#####", ".########......"};
  int sol = solution(25, 51, a);
  cout << sol << endl;
}


/*
{".########......", ".####...#......", ".#.####.#.#####", ".#.#..#.#.#..##", ".#.##.#.#.#...#", ".#.####.#.#...#", ".#....###.#####", ".########......"}

*/
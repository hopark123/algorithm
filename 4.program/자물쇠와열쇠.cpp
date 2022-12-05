#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

vector<vector<int> > rotate(vector<vector<int> > key) {
    vector<vector<int> > res(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            res[i][j] = key[j][abs(N - i - 1)];
        }
    }
    return res;
}

bool setting(vector<vector<int> > key, vector<vector<int> > lock, int y, int x) {
    int cnt = 3;
    while (1) {
        vector<vector<int> > table(2 * N + M, vector<int>(2 * N + M, 8));
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < M; ++j)
                table[i + N][j + N] = lock[i][j];
        for (int i = 0; i < N && i + y < N + M; ++i) {
            for (int j = 0; j < N && j + x < N + M; ++j) {
                if (i + y < N || j + x <  N)
                    continue;
                table[i + y][j + x] ^= key[i][j];
            }
        }
        int flag = 1;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                flag *= table[i + N][j + N];
            }
        }
        if (flag)
            return true;
        if (cnt-- == 0)
            break ;
        key = (rotate(key));
    }
    return false;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    N = key.size();
    M = lock.size();
    rotate(key);
    for (int i = 0; i < N + M; ++i) {
        for (int j = 0; j < N + M; ++j) {
            if (setting(key, lock, i, j)) {
                answer = true;
                break ;
            }
        }
    }
    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  vector<vector<int> > a = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
  vector<vector<int> > b = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
 
  bool sol = solution(a, b);
  cout << sol << endl;
}


/*

key	lock	result
{{0, 0, 0}, {1, 0, 0}, {0, 1, 1}}	{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}}	true
*/
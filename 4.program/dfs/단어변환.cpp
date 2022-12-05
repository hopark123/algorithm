#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int N;
int res  = 1e7;
vector<int> visited;

int check(string A, string B) {
    int res = 0;
    for (int i = 0; i < A.length(); ++i) {
      if (A[i] != B[i])
          ++res;
      if (res >= 2)
          return -1;
    }
    return res;
}


void dfs(string target, vector<string> words, int index, int cnt) {
  visited[index] = min(visited[index], cnt);
  if (words[index] == target) {
    res = min(res, cnt);
    return ;
  }
  for (int i = 0; i < N; ++i) {
    if (check(words[index], words[i]) == 1 && visited[i] > cnt) {
      dfs(target, words, i, cnt + 1);
    }
  }
}

int solution(string begin, string target, vector<string> words) {
  N = words.size();
  visited.resize(N, 1e7);

  if (begin == target)
    return 1;
  for (int i = 0; i < N; ++i) {
    int flag = check(begin, words[i]);
    if (flag == 0)
      dfs(target, words, i, 0);
    else if (flag == 1)
      dfs(target, words, i, 1);
  }
    return res == 1e7 ? 0 : res ;
}

int main()
{
  ios::sync_with_stdio(false);
  int sol = solution("aaa", "ccc", {"aaa","ccc", "aca", "cca", "hih"});
  // int sol = solution("hot", "cog", {"hot", "dot", "dog", "lot", "log", "cog"});
  cout << sol << endl;
}


/*


*/


/* dij 너무 복잡하게 구현한느낌
int N;
vector<vector<int> > edge;

int check(string A, string B) {
    int res = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] != B[i])
            ++res;
        if (res >= 2)
            return -1;
    }
    return res;
}

int dij(string begin, int end, vector<string> words) {
    vector<int> res(edge.size(), 1e7);
    priority_queue<pair<int, int> > pq;
    res[0] = 0;
    pq.push({0, 0});
    int i = 0;
    while (!pq.empty()) {
        pair<int, int> top = pq.top(); pq.pop();
        if (res[top.second] < -top.first) continue;
        res[top.second] = -top.first;
        for (int i = 0; i < edge[top.second].size(); ++i) {
            int next = edge[top.second][i];
            if (res[next] > top.first + 1);
                pq.push({top.first - 1, edge[top.second][i]});
        }
    }
    return res[end + 1];
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int end = -1;
    N = begin.size();
    edge.resize(words.size() + 1);
    for (int i = 0; i < words.size(); ++i) {
        if (check(begin, words[i]) != -1) {
            edge[0].push_back(i + 1);
        }
        if (target == words[i]) {
            end = i;
        }
    }
    if (end == -1) {
        return 0;
    }
    for (int i = 0; i < words.size(); ++i) {
        for (int j = i + 1; j < words.size(); ++j) {
            if (check(words[i], words[j]) != -1) {
                edge[i + 1].push_back(j + 1);
                edge[j + 1].push_back(i + 1);
            }
        }
    }
    return dij(begin, end, words);
}
*/
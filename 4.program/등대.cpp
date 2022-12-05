#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<bool> visited;
vector<vector<int> > arr;

bool compare(pair<int, vector<int> > a, pair<int, vector<int> > b) {
    return a.second.size() > b.second.size();
}


int res = 1e7;
int N;

pair<int, int> dfs(int node) {
    visited[node] = true;
    cout << node << " " << endl;
    int pick = 1;
    int not_pick = 0;
    
    for (int i = 0; i < arr[node].size(); ++i) {
        if (visited[arr[node][i]]) {
            pair<int, int> child = dfs(arr[node][i]);
            pick += min(child.first, child.second);
            not_pick += child.first;
        }
    }
    cout << pick << "-" << not_pick << endl;
    
    return make_pair(pick, not_pick);
}

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;
    N = n;
    arr.resize(n + 1);
    for (int i = 0; i < lighthouse.size(); ++i) {
        int a = lighthouse[i][0];
        int b = lighthouse[i][1];
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dfs(1);
    
    return answer;
}

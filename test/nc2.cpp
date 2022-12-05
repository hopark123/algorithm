#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > edge(13);
vector<int> visited;
int res = 2e7;

vector<int> dij(int st) {
    priority_queue<pair<int, int> > pq;
    vector<int> vec(13, 1e7);

    vec[st] = 0;
    pq.push(make_pair(0, st));
    while (!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second; pq.pop();
        if (cost > vec[here]) continue;
        for (int i = 0; i < edge[here].size(); ++i) {
            int there = edge[here][i];
            int here_to_there = vec[here] + 1;
            if (here_to_there < vec[there]) {
                vec[there] = here_to_there;
                pq.push(make_pair(-here_to_there, there));
            }
        }
    }
    return vec;
}

int solution(vector<int> music) {
    int answer = 0;
    vector<vector<int> > edges = {{2, 3}, {1,3}, {1,2,4,5}, {3,5}, {3,4,6,7}, {5,7}, {5,6,8}, {7, 9, 10}, {8, 10}, {8, 9, 11, 12}, {10, 12}, {10, 11}};

    for (int i = 0; i < edges.size(); ++i) {
        for (auto &it : edges[i])
            edge[i + 1].push_back(it);
    }

    int st = 1;
    for (int i = 0; i < music.size(); ++i) {
        vector<int> vec = dij(st);
        answer += vec[music[i]];
        st = music[i];   
    }
    return answer;
}


#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


bool com(pair<string, int> a, pair<string, int> b) {
    return a.second >= b.second ;
}

class _compare {
    public:
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if (a.first < b.first)
            return true;
        else if (a.first == b.first)
            return a.second > b.second;
        else
            return false;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, long long> unmp;
    map<string, priority_queue<pair<int, int>, vector<pair<int, int> >, _compare > > info;
    for (int i = 0; i < genres.size(); ++i) {
        unmp[genres[i]] += plays[i];
      info[genres[i]].push({plays[i], i});
    }
    vector<pair<string, int> > vec(unmp.begin(), unmp.end());
    sort(vec.begin(), vec.end(), com);
    for (auto &it : vec) {
        string type = it.first;
        answer.push_back(info[type].top().second);
        info[type].pop();
        if (!info[type].empty())
            answer.push_back(info[type].top().second);
    }
    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  vector<vector<string> > a;
  vector<string> b;
 
  b.clear();
  int sol = solution(a);
  cout << sol << endl;
}


/*


*/
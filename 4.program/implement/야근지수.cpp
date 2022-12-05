#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    long long sum_work = 0;
    vector<long long> minus(works.size(), 0);
    priority_queue<pair<long long, int> > pq;
    for(int i = 0; i < works.size(); ++i) {
        pq.push({works[i], i});
        sum_work += works[i];
    }
    if (sum_work <= n)
        return answer;
    while (!pq.empty() && n > 0) {
        pair<long long, int> top = pq.top(); pq.pop();
        --top.first;
        --works[top.second];
        --n;
        if (top.first >= 1) {
            pq.push(top);
        }
    }
    for (int i = 0; i < works.size(); ++i) {
        answer += works[i] * works[i];
    }
    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
 
  long long sol = solution(5, {5, 3, 1});
  cout << sol << endl;
}

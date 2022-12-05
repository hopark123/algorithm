solution.cpp
2022-10-23 12:59:23
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


int guard = 0;
vector<long long> res;
void dfs(vector<string> maps, int cnt, int index, int guard) {
    if (cnt >= maps.size()) {
        res.push_back(cnt);
        return ;
    }
    if (maps[maps.size() - 1 - cnt][index] == 'B')
        --guard;
    else if (maps[maps.size() - 1 - cnt][index] == 'S')
        ++guard;
    if (guard < 0) {
        res.push_back(cnt);
        return ;
    }
    if (cnt == maps.size() -1) {
        res.push_back(cnt);
        return ;
    }
    dfs(maps, cnt + 1, index, guard);
    if (index < maps[0].size() - 1)
        dfs(maps, cnt + 1, index + 1, guard);
    if (index > 0)
        dfs(maps, cnt + 1, index - 1, guard);
}


vector<long long> solution(vector<string> maps) {
    vector<long long> answer;
    int index = 0;
    for (int i = 0; i < maps[maps.size() - 1].size(); ++i)
        if (maps[maps.size() - 1][i] == 'C')
            index = i;

    dfs(maps, 0, index, 0);
    sort(res.begin(), res.end());
    long long ma = res[res.size() - 1];
    int res_index;
    for (int i = 0; i < res.size(); ++i) {
        if (res[i] == ma) {
            res_index = i;
            break ;
        }
    }

    answer.push_back(ma);
    answer.push_back(res.size() - res_index);
    return answer;
}

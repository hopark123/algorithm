solution.cpp
2022-10-23 12:59:01
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
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<string> st;


vector<string> solution(vector<string> dic) {
    vector<string> answer;

    for (int i = 0; i < dic.size(); ++i) {
        for (int j = 0; j < dic.size(); ++j) {
            string str;
            if (i == j)
                continue;
            str = dic[i] + dic[j];
            st.insert(str);
            if (dic[i][dic[i].size() - 1] == dic[j][0]) {
                str = dic[i].substr(0, dic[i].size() - 1) + dic[j];
                st.insert(str);
            }
        }

    }
    for (auto &it : dic) {
        for (auto &itt : st) {
            if (itt.compare(it) == 0) {
                answer.push_back(it);
                break ;
            }
        }
    }
    sort(answer.begin(), answer.end());
    if (answer.size() == 0)
        answer.push_back("-1");
    return answer;
}

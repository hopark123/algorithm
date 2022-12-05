solution.cpp
2022-10-23 12:59:17
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
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int eat = 0;
priority_queue<int> pq;

vector<long long> solution(long long n, long long m) {
    vector<long long> answer;
    pq.push(-n);
    int i = 0;
    while (eat != m) {
        int nb = -pq.top(); pq.pop();
        if (nb == 1)
            ++eat;
        else if (nb % 2 == 0) {
            pq.push(-(nb / 2));
            if (nb / 2 == 1) {
                ++eat;
            }
            else {
                pq.push(-(nb / 2));
            }
        }
        else {
            pq.push(-(nb + 1)/ 2);
            if ((nb - 1)/ 2 == 1) {
                ++eat;
            }
            else {
                pq.push(-(nb - 1)/ 2);
            }
        }
    }
    while (!pq.empty()) {
        answer.push_back(-pq.top());
        pq.pop();
    }
    sort(answer.begin(), answer.end(), greater<int>());
    return answer;
}

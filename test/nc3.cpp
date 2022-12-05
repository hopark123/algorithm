#include <string>
#include <vector>

using namespace std;

int max_nbr = -2e7;
vector<vector<vector<int> > > vec(5);

vector<int> ft_sol(vector<int> vec, int index) {
    vector<int> res;

    if (index <= vec.size() / 2) {
        for (int i = 0; i < index; ++i) {
            int left = vec[i];
            int right = vec[2 * index - i - 1];
            res.push_back(left + right);
            max_nbr = max(left + right, max_nbr);
        }
        for (int i = index * 2; i < vec.size(); ++i) {
            res.push_back(vec[i]);
            max_nbr = max(vec[i], max_nbr);
        }
    }
    else {
        for (int i = vec.size() - index; i > 0; --i) {
            int left = vec[index - i];
            int right = vec[index + i - 1];
            res.push_back(left + right);
            max_nbr = max(left + right, max_nbr);
        }
        for (int i = 0; i < -vec.size() + 2 * index; ++i) {
            res.push_back(vec[i]);
            max_nbr = max(vec[i], max_nbr);
        }
    }
    return (res);
}

int solution(vector<int> paper, int n) {
    int answer = -2;

    for (int i = 0; i < paper.size(); ++i)
        max_nbr = max(max_nbr, paper[i]);
    vec[0].push_back(paper);
    for (int t = 1; t <= n; ++t){
        for (int i = 0; i < vec[t - 1].size(); ++i){
            for (int j = 1; j < vec[t - 1][i].size(); ++j) {
                vector<int> res = ft_sol(vec[t - 1][i], j);
                vec[t].push_back(res);
            }
        }
    }
    answer = max_nbr;
    return answer;
}

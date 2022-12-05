#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
string res_front;
string res_back;

void ft_answer(int index, string p) {
    queue<char> q;
    int cnt = 0;
    bool right = true;
    for (int i = index; i < p.length(); ++i) {
        q.push(p[i]);
        cnt += pow( -1, p[i] - 40);
        if (cnt < 0)
          right = false;
        if (cnt == 0) {
          if (right) {
            while (!q.empty()) {
              res_front.push_back(q.front());
              q.pop();
            }
            ft_answer(i + 1, p);
            return ;
          }
          else {
            q.pop();
            res_front.push_back('(');
            ft_answer(i + 1 , p);
            res_front.push_back(')');
            while (!q.empty()) {
              if (q.size() == 1)
                break ;
              char c = q.front() + pow(-1, q.front() - 40);
              res_front.push_back(c);
              q.pop();
            }
            return ;
          }
        }

    }

}
string solution(string p) {
    string answer = "";
    ft_answer(0, p);
    answer = res_front + res_back;
    return answer;
}


int main()
{
    ios::sync_with_stdio(false);
    string a ="()))((()";
    // string a = ")(";
    // string a = ")()(()";

    string sol = solution(a);
    cout << sol;
}


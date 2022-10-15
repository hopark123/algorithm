#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

string distance(pair<int, int> left, pair<int, int> right, pair<int, int> num, string hand) {
    int left_dis;
    int right_dis;

    left_dis = abs(num.first - left.first) + abs(num.second - left.second);
    right_dis = abs(num.first - right.first) + abs(num.second - right.second);
    cout << num.first << num.second<< left_dis << "  "  << right_dis << endl;
    if (right_dis > left_dis)
        return ("L");
    else if (right_dis < left_dis)
        return ("R");
    else {
        return (hand == "right" ? "R" : "L");
    }
}

pair<int, int> findPos(int num) {
    pair<int, int> res;
    if (num == 0) {
        res.first = 3;
        res.second = 1;
        return (res);
    }
    else  {
        res.first = (num - 1) / 3;
        res.second = (num - 1) % 3;
        return (res);
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> left = make_pair(3, 0);
    pair<int, int> right = make_pair(3, 2);
    for(vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        string res;
        cout << (*it) << endl;
        if ((*it) == 1 || (*it) == 4 || (*it) == 7)
            res = "L";
        else if ((*it) == 3 || (*it) == 6 || (*it) == 9)
            res = "R";
        else
            res = distance(left, right, findPos(*it), hand);
        if (res == "R")
            right = findPos(*it);
        else
            left = findPos(*it);
        answer += res;
    }
    return answer;
}
int main()
{
    ios::sync_with_stdio(false);
    vector<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(8);
    a.push_back(2);
    a.push_back(1);
    a.push_back(7);
    a.push_back(8);
    a.push_back(9);
    a.push_back(0);
    string sol = solution(a, "right");
    cout << sol << endl;
}



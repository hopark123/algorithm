#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <time.h>

using namespace std;

deque<deque<int> > dq; 
vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer;
    int N = rc.size();
    int M = rc[0].size();
    for (int i = 0; i < N; ++i)  {
      deque<int> temp(M - 2);
      for(int j = 1; j < M - 1; ++j) 
        temp[j - 1] = rc[i][j];
        // temp.push_back(rc[i][j]);
      dq.push_back(temp);
    }
    deque<int> head(N);
    deque<int> tail(N);
    for (int i = 0; i < N; ++i)  {
      head[i] = rc[i][0];
      tail[i] = rc[i][M-1];
      // head.push_back(rc[i][0]);
      // tail.push_back(rc[i][M - 1]);
    }
    for (auto &it : operations) {
      if (it == "ShiftRow") {
        deque<int> temp = *(dq.end() - 1);
        dq.pop_back();
        dq.push_front(temp);
        int head_nbr = *(head.end() - 1);
        int tail_nbr = *(tail.end() - 1);
        head.pop_back();
        tail.pop_back();
        head.push_front(head_nbr);
        tail.push_front(tail_nbr);
      }
      else {
        int temp;

        temp = *(tail.end() - 1);
        tail.pop_back();
        dq[N - 1].push_back(temp);

        temp = dq[N - 1].front();
        dq[N - 1].pop_front();
        head.push_back(temp);

        temp = head.front();
        head.pop_front();
        dq[0].push_front(temp);

        temp = *(dq[0].end() - 1);
        dq[0].pop_back();
        tail.push_front(temp);
      }
    }
    for (int i = 0; i < N; i++) {
      vector<int> temp;
      temp.push_back(head[i]);
      for (auto &itt : dq[i])
        temp.push_back(itt);
      temp.push_back(tail[i]);
      answer.push_back(temp);
    }
    return answer;
}

int main()
{
  // ios::sync_with_stdio(false);
  vector<vector<int> > a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  // vector<vector<int> > a = {{1, 2}, {4, 5}};
  // vector<vector<int> > a;
  // cout << "a" << endl;
  // for (int i = 0; i < 50000; ++i) {
  //   vector<int> temp;
  //   // cout << i << endl;
  //   for (int j = 0; j < 50000; ++j) {
  //     temp.push_back(random());
  //   }
  //   a.push_back(temp);
  // }
    time_t start, end;
    double result;
    start = time(NULL);
    vector<string> b = {"Rotate", "ShiftRow"};
    vector<vector<int > > sol = solution(a, b);
    end = time(NULL); // 시간 측정 끝
    result = (double)(end - start);

    // 결과 출력
  for (auto &it : sol) {
    for (auto &itt : it)
      cout << itt << " ";
    cout << endl;
  }
  printf("%f", result);

  // cout << sol << endl;
}

   
/*

{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}	{"Rotate", "ShiftRow"}	{{8, 9, 6}, {4, 1, 2}, {7, 5, 3}}
{{8, 6, 3}, {3, 3, 7}, {8, 4, 9}}	{"Rotate", "ShiftRow", "ShiftRow"}	{{8, 3, 3}, {4, 9, 7}, {3, 8, 6}}
{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}	{"ShiftRow", "Rotate", "ShiftRow", "Rotate"}	{{1, 6, 7 ,8}, {5, 9, 10, 4}, {2, 3, 12, 11}}
*/
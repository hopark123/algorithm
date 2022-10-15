#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0 ;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater());
    for (int i = 0; i < A.size(); ++i) {
      answer += A[i] * B[i];
      // cout << temp << " "; 
    }
    // int answer2 = temp;
    // do {
    //     long long temp = 0;
    //     answer = min(answer, temp);
    //     cout << answer << endl;
    // }
    // while(next_permutation(A.begin(), A.end()));
    // // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    // int answer2 = (int)answer;
    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  vector<int> a  = {1, 4, 2};
  vector<int> b  = {5, 4, 4};
  a.resize(1000, random());
  b.resize(1000, random());
  int sol = solution(a, b);
  cout << sol << endl;
}


/*
A	B	answer
[1, 4, 2]	[5, 4, 4]	29
[1,2]	[3,4]	10
*/
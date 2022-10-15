#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;

long long solution(long long n) {
    long long answer = -1;
    if (sqrt(n) * sqrt(n) == n)
      answer = pow((sqrt(n) + 1), 2);
    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  int sol = solution(3);
  cout << sol << endl;
}


/*


*/
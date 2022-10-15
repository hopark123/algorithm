#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;



int solution(vector<int> people, int limit) {
    int answer = 0;
    int i = 0;
    int j = people.size() - 1;
    sort(people);
    while(i <= j) {
      answer++;
      // cout<< answer << "@@" << people[i] << " " << people[j] << endl;
      if (people[i] + people[j] <= limit)
        i++;
      --j;
    }
    return answer;
}


int main()
{
  ios::sync_with_stdio(false);
  vector<int> a  = {70, 50, 80, 50};
  int sol = solution(a, 100);
  cout << sol << endl;
}


/*

people	limit	return
[70, 50, 80, 50]	100	3
[70, 80, 50]	100	3

*/
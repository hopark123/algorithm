#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  vector<vector<string> > a;
  vector<string> b;
 
  b.clear();
  int sol = solution(1, 1, 5, {"08:00", "08:01", "08:02", "08:03"});
  cout << sol << endl;
}


/*

n	t	m	timetable	answer
1	1	5	{"08:00", "08:01", "08:02", "08:03"}	"09:00"
2	10	2	{"09:10", "09:09", "08:00"}	"09:09"
2	1	2	{"09:00", "09:00", "09:00", "09:00"}	"08:59"
1	1	5	{"00:01", "00:01", "00:01", "00:01", "00:01"}	"00:00"
1	1	1	{"23:59"}	"09:00"
10	60	45	{"23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"}	"18:00"

*/
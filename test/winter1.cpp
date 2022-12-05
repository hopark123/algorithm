#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string line) {
    string answer = "";
    int i = 1;
    answer += line[0];
    char temp = line[0];

    while (line[i]) {
        cout << temp << "@" << line[i]<< endl;
        if (temp == line[i]) {
            answer += "*";
            while (1) {
                if (temp != line[i + 1]) {
                    break;
                }
                ++i;
            }
            cout << "k" << line[i] << endl;
        }
        else {
            answer += line[i];
        }
        cout<<"[" << answer <<"]"<< endl;
        temp = line[i];
        ++i;
    }
    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  string a = "aabbbc";
 
  string sol = solution(a);
  cout << sol << endl;
}


/*

"aabbbc"
기댓값 〉
"a*b*c"
*/
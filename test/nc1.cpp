#include <string>
#include <vector>

using namespace std;

string solution(string source) {
    string answer = "";
    string temp = source;
    int i = 0 ;

    while (++i < 10) {
        string str = "";
        vector<int> alp(26, 0);

        for (int i = 0; i < temp.size(); ++i) {
            ++alp[temp[i] - 'a'];
        }
        for (int i = 0; i < temp.size(); ++i) {
            if (alp[temp[i] - 'a'] > 1) {
                str += temp[i]; 
                --alp[temp[i] - 'a'];
            }
        }
        for(int i = 0; i < 26; ++i) {
            if (alp[i] == 1) {
                answer += i + 'a';
            }
        }
        if (str.size() == 0)
            break ;
        temp = str;
    }
    return answer;
}

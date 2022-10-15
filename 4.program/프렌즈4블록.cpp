#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

bool arr[32][32];
int dx[4] = {0, 0, 1, 1};
int dy[4] = {0, 1, 0, 1};

int delDrop(int m, int n, char ***board)
{
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        string res;
        for (int j = 0; j < m; ++j)
        {
            if ((*board)[i][j] == '7')
                ++cnt;
            else if ((*board)[i][j] != '8')
                res += (*board)[i][j];
        }
        char *str;
        str = (char *)malloc(sizeof(char) * m);
        size_t k = 0;
        for (k = 0; k < res.length(); ++k)
            str[k] = res[k];
        for (; k < (size_t)m; ++k)
            str[k] = '8';
        free((*board)[i]);
        (*board)[i] = str;
    }
    return cnt;
}

bool checkdel(int m, int n, char ***board)
{
    int flag = false;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < m - 1; j++)
        {
            int flag = 0;
            char type = (*board)[i][j];
            if (type == '8')
                break;
            for (int k = 0; k < 4; ++k)
            {
                if (type == (*board)[i + dx[k]][j + dy[k]])
                    ++flag;
            }
            if (flag == 4)
            {
                for (int k = 0; k < 4; ++k)
                {
                    arr[i + dx[k]][j + dy[k]] = true;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (arr[i][j]) {
                (*board)[i][j] = '7';
                flag = true;
            }
        }
    }
    return flag;
}

int solution(int m, int n, vector<string> board)
{
    int answer = 0;
    char **new_str;
    new_str = (char **)malloc(sizeof(char *) * 31);
    for (int i = 0; i < 31; ++i)
    {
        new_str[i] = (char *)malloc(sizeof(char) * 31);
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            new_str[i][j] = board[m - 1 - j][i];
        }
    }
    while (1) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                arr[i][j] = false;
        if (!checkdel(m, n, &new_str))
            break ;
        answer += delDrop(m, n, &new_str);
        cout <<"res"<< endl;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cout << new_str[i][j];
            }
            cout << endl;
        }
        // cout << endl;
        // cout << endl;
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    vector<string> a;
    a.push_back("CCZXZ");
    a.push_back("CCZXZ");
    a.push_back("XXZXZ");
    a.push_back("AAZAA");
    a.push_back("AAAAA");
    a.push_back("ZAAXX");
    int sol = solution(6, 5, a);
    cout << sol << endl;
}

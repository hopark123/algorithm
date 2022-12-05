// #include <bits/stdc++.h>
#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;
using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'minNum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER samDaily
 *  2. INTEGER kellyDaily
 *  3. INTEGER difference
 */

int minNum(int samDaily, int kellyDaily, int difference) {
    int day = 0;
    int sam = difference;
    int kelly = 0;
    while (1) {
        ++day;
        sam += samDaily;
        kelly += kellyDaily;
        if (sam < kelly)
            break ;
    }

    return day;
}

int main()
{
    int sol = minNum(4, 5, 1);
    cout << sol << endl;
    return 0;
}

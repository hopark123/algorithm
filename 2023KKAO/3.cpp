#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

priority_queue<pair<int, long long> > pq;
int arr[8];
bool	check(int a, int i) {
	return (a & (1 << i));
}


vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;

  for (int i = 0; i < pow(4, emoticons.size()); ++i) {
    int temp = i;
    for (int j = emoticons.size() - 1;  j >= 0; --j) {
      temp = temp % (int)pow(4, j + 1);
      arr[j] = (temp / (int)pow(4, j) + 1) * 10;
    }
    vector<long long> sale(101, 0);
    // cout << emoticons.size() << endl;
    for (int i = 0; i < users.size(); ++i) {
      for (int j = 0; j < emoticons.size(); ++j) {
        // cout <<"["<< (double)emoticons[j]<< "][" <<  (100 - arr[j])<<"][" <<(double)emoticons[j] * 0.01 * (100 - arr[j])  << "]"<< endl;
        if (arr[j] >= users[i][0]) {
          // cout << "arr[j]" << arr[j] << endl;
          sale[i] += (double)emoticons[j] * 0.01 * (100 - arr[j]);
        }
      }
    }
    int plus = 0;
    // for (int i = 0; i < emoticons.size(); ++i) {
    //   cout << arr[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < users.size(); ++i) {
    //   cout << sale[i] << " ";
    // }
    // cout << endl;
    int money = 0;
    for (int i = 0; i < users.size(); ++i) {
      if (sale[i] >= users[i][1]) {
        sale[i] -= users[i][1];
        ++plus;
        sale[i] = 0;
      }
      money += sale[i];
    }
    // cout << endl;
    pq.push(make_pair(plus, money));
  }
  answer.push_back(pq.top().first);
  answer.push_back(pq.top().second);
  return answer;
}

int main()
{
  vector<int> a;
  vector<vector<int> > b;
 
  // a.push_back(40);
  // a.push_back(10000);
  // b.push_back(a);
  // a.clear();
  // a.push_back(25);
  // a.push_back(10000);
  // b.push_back(a);
  // a.clear();
  // a.push_back(7000);
  // a.push_back(9000);


  a.push_back(40);
  a.push_back(2900);
  b.push_back(a);
  a.clear();
  a.push_back(23);
  a.push_back(10000);
    b.push_back(a);
  a.clear();
  a.push_back(11);
  a.push_back(5200);
    b.push_back(a);
  a.clear();
  a.push_back(5);
  a.push_back(5900);
    b.push_back(a);
  a.clear();
  a.push_back(40);
  a.push_back(3100);
    b.push_back(a);
  a.clear();
  a.push_back(27);
  a.push_back(9200);
    b.push_back(a);
  a.clear();
  a.push_back(32);
  a.push_back(6900);
  b.push_back(a);
  a.clear();
  a.push_back(1300);
  a.push_back(1500);
  a.push_back(1600);
  a.push_back(4900);

  vector<int> sol = solution(b, a);
  for(auto it : sol)
    cout << it << endl;
}


/*



[[40, 10000], [25, 10000]]
[7000, 9000]
[[40, 2900], [23, 10000], [11, 5200], [5, 5900], [40, 3100], [27, 9200], [32, 6900]]
[1300, 1500, 1600, 4900]
 




*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;




bool compare(pair<int, int> a, pair<int, int> b) {
  return (a.second < b.second);
}

int solution(vector<int> food_times, long long k) {
    int answer = -1;
    int size = food_times.size();
    int cycle = 0;

    vector<pair<int, int> > vec;
    for (int i = 0; i < size; ++i) {
      vec.push_back({food_times[i], i + 1});
    }
    sort(vec.begin(), vec.end());
    for (vector<pair<int, int> >::iterator it = vec.begin(); it != vec.end(); ++it) {
      long long eat = it->first - cycle;
      cout <<k <<" " << eat * size << endl;
      if (k >= eat * size) {
        k -= eat * size;
        cycle += eat;
        --size;
      }
      else {
        k %= size;
        sort(it, vec.end(), compare);
        return (it + k)->second;
      }
    }
    return -1;
}

int main()
{
  ios::sync_with_stdio(false);
  // vector<int> a = {3, 1, 2};
  vector<int> a = {3, 2, 2, 10, 15};
  int sol = solution(a, 500);
  cout << sol << endl;
}


/*
food_times	k	result
{3, 1, 2}	5	1

*/
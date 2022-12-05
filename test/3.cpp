#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
using namespace std;



long getMinimumHealth(vector<int> initial_players, vector<int> new_players, int rank) {
  sort(initial_players.begin(), initial_players.end(), greater<int>());

  multiset<int> st;
  long res = 0;
  int score =initial_players[rank - 1];
  
  for (int i = 0; i < rank; ++i)
    st.insert(initial_players[i]);
  
  int index = 0;
  res += *st.begin();

  cout << res << endl;
  auto it = st.begin();
  for (int i = 0; i < new_players.size(); ++i) {
    cout << new_players[i] << "**" << *it << endl;
    if (new_players[i] > *it) {
      st.insert(new_players[i]);
      ++it;
      // score = initial_players[rank] > new_players[i]? new_players[i] : initial_players[rank];
    }
    res += *it;
  cout << res << endl;
  }
  return (res);
}



int main()
{
  ios::sync_with_stdio(false);
  
  vector<int> a = {1, 2, 5};
  vector<int> b = {2, 5,4};
  // vector<int> a = {1, , 3};
  // vector<int> b = {2, 2,4};

  long sol = getMinimumHealth(a, b, 3);
  cout << sol << endl;
}


/*
3
1
2
5
3
2
5
4
3
nput (stdin)
3
1
1
3
3
2
2
4
2
Your Output (stdout)
1
Expected Output
8
*/
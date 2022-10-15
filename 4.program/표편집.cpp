#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <stack>
using namespace std;

typedef struct s_Node {
  int n;
  s_Node *prev;
  s_Node *next;
  s_Node(int _n, s_Node *_prev, s_Node *_next) : n(_n), prev(_prev), next(_next) {};
} Node;



string solution(int n, int k, vector<string> cmd) {
  string answer(n, 'X');
  stack<Node*> stk;
  Node *list = new Node(0, NULL, NULL);
  Node *temp = list;
  
  for (int i = 1; i < n; ++i) {
    temp->next = new Node(i, temp, NULL);
    temp = temp->next; 
  }
  for (int i = 0; i < k; ++i) 
    list = list->next;
  for (auto &c : cmd) {
    // cout << c << endl;
    // cout << list->n << endl;
    switch (c[0])
    {
      case 'U':
      {
        int temp = stoi(c.substr(2));
        while (temp--) list = list->prev;
        break;
      }
      case 'D' :
      {
        int temp = stoi(c.substr(2));
        while (temp--) list = list->next;
        break;
      }
      case 'C' :
      {
        if (list->prev)
          list->prev->next = list->next;
        if (list->next)
          list->next->prev = list->prev;
        temp = list->next;
        if (temp == NULL)
          temp = list->prev;
        stk.push(list);
        list = temp;
        // cout << list->n << endl;
        break;
      }
      case 'Z' :
      {
        Node* r = stk.top(); stk.pop();
        if(r->prev != NULL) r->prev->next = r;
        if(r->next != NULL) r->next->prev = r;
        break;
      }
    default:
      break;
    }
  }
  while (list->prev)
    list = list->prev;
  while (list) {
    answer[list->n] = 'O';
    list = list->next;
  }
  return answer;
}
int main()
{
  ios::sync_with_stdio(false);
  // vector<string> a = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z"};
  vector<string> a = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"};
  string sol = solution(8, 2, a);
  cout << sol << endl;
}


/*
n	k	cmd	result
8	2	["D 2","C","U 3","C","D 4","C","U 2","Z","Z"]	"OOOOXOOO"
8	2	["D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"]	"OOXOXOOO"

*/



/*

set<int> st;
stack<int> stk;

string solution(int n, int k, vector<string> cmd) {
    string answer(n,'X');
    for (int i = 0; i < n; ++i) {
      st.insert(i);
    }
    // set<int>::iterator it = st.begin();
    // for (int i = 0; i < k; ++i)
  //   ++it;
     auto it = st.find(k);
    for (auto &c : cmd) {
      // cout << c << endl;
      if(c[0] =='U') {
        int nbr = stoi(c.substr(2));
        // ft_up(it, nbr);
        while(nbr--) it = prev(it);

      }
      else if(c[0] =='D') {
        int nbr = stoi(c.substr(2));
        // ft_down(it, nbr);
        while(nbr--) it = next(it);
      }
      else if(c[0] =='C') {
        stk.push(*it);
        // if (st.erase(it) == st.end() ?
        it = st.erase(it);
        if (it == st.end())
          --it;
          // it = st.begin();
      }
      else if(c[0] =='Z') {
        if (stk.empty())
          continue;
        int temp = stk.top(); stk.pop();
        st.insert(temp);
      }
      cout << *it << endl;
    }
    it = st.begin();
    for (auto &itt : st)
      answer[itt] = 'O';
    return answer;
}

*/
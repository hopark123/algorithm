#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;



class Node {
  public : 
    int y;
    int x;
    int nbr;
    Node *left;
    Node *right;
    
    Node(int _nbr, int _y, int _x) : nbr(_nbr), x(_x), y(_y), left(NULL), right(NULL) {};

    void insert(Node *par, Node *child) {
      if (par->x > child->x) {
        if (par->left)
          insert(par->left, child);
        else {
          par->left = child;
        }
      }
      else {
        if (par->right)
          insert(par->right, child);
        else {
          par->right = child;
        }
      }
      return ;
    }

    void pre_order(Node *node, vector<int> &pre_res) {
      if (node == NULL) return;
      pre_res.push_back(node->nbr);
      pre_order(node->left, pre_res);
      pre_order(node->right, pre_res);
    }

    void post_order(Node *node, vector<int> &post_res) {
      if (node ==NULL) return;
      post_order(node->left, post_res);
      post_order(node->right, post_res);
      post_res.push_back(node->nbr);
    }
};

class _Compare {
	public :
	bool operator() (Node *a, Node *b) {
    if (a->y < b->y)
    return true;
  else if (a->y > b->y)
    return false;
  else {
    return a->x > b->x;
    }
  }
};

priority_queue<Node *, vector<Node *>, _Compare> pq;

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<int> pre_res;
    vector<int> post_res;

    for (int i = 0; i < nodeinfo.size(); ++i) {
      Node *temp = new Node(i + 1, nodeinfo[i][1], nodeinfo[i][0]);
      pq.push(temp);
    }
    Node *tree = pq.top(); pq.pop();

    while (!pq.empty()) {
      Node *temp = pq.top(); pq.pop();
      tree->insert(tree, temp);
    }
    tree->pre_order(tree, pre_res);
    tree->post_order(tree, post_res);
    answer.push_back(pre_res);
    answer.push_back(post_res);
    return answer;
}


int main()
{
  ios::sync_with_stdio(false);
  vector<vector<int> > a ={{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}};
 
  vector<vector<int> > sol = solution(a);
  for (auto &it : sol) {
    for (auto &itt : it)
      cout << itt << " ";
    cout << endl;
  }
}


/*
nodeinfo	result
{{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}}	{{7,4,6,9,1,8,5,2,3},{9,6,5,8,1,4,3,2,7}}

*/
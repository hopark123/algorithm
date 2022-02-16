#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int>		in;
vector<int>		pt;
int		n;
int		i;
void		preorder(int in_st, int in_end,int pt_st, int pt_end,int flag) {
	int _root = find(in.begin(), in.end(), pt[pt_end]) - (in.begin());
	// cout << flag << "||"; 
	if (in_st > in_end || pt_st > pt_end) 	return ;
	// cout << in_st << "->" << in_end << "|" << pt_st << "->" << pt_end << "(" << _root <<")\t";
	// cout << "["<<pt[pt_end] << "]\n";
	cout <<pt[pt_end] << " ";
	preorder(in_st, _root - 1, pt_st, pt_st + _root - in_st - 1, 0);
	preorder(_root + 1, in_end, pt_st + _root - in_st, pt_end - 1, 1);
}


int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		in.push_back(temp);
	}
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		pt.push_back(temp);
	}
	preorder(0, n - 1, 0, n - 1, 0);
}

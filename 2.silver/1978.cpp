#include <iostream>

using namespace std;

int		d[1005];
int		N;

void	dp(int n){ 
	if (d[n] == -1)
		return ;
	for (int i = 2; i * n < 1005; i++ )
		d[i * n] = -1;

}
int main() {

	cin >> N;
	d[1] = -1;
	for(int i = 2; i < 1005; i++)
		dp(i);
	int		res = 0;
	while (N--)
	{
		int		temp;
		cin >> temp;
		if (d[temp] != -1)
			res++;
	}
	cout << res << endl;
}
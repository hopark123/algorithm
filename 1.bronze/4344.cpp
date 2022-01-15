#include <iostream>
#include <vector>

using namespace std;

int	C, N;
vector<float> vec;

int main()
{
	cin >> C;
	float	aver;
	float	res;
	while (C--)
	{
		cin >> N;
		aver = 0;
		res = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> res;
			aver += res;
			vec.push_back(res);
		}
		aver /= N;
		res = 0;
		for (int i = 0 ; i < N; i++)
		{
			if (vec[i] > aver)
				res++;
		}
		vec.clear();
		printf("%.3f%%\n", (float)(res / N) * 100);
	}
}
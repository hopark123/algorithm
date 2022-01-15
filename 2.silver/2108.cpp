#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int		arr[8005];

int main()
{
	int			N;
	int	sum = 0;
	vector<int> vec;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int	temp;
		cin >> temp;

		vec.push_back(temp);
		arr[temp + 4000]++;
		sum += temp;
	}
	int flag = 0;
	int	_max = 0, res = sum;
	for (int i = 0; i < 8002; i++)
		_max = max(_max, arr[i]);
	for (int i = 0; i < 8002; i++)
	{
		if (_max == arr[i])
		{
			res = i;
			if (flag == 1)
			{
				res = i;
				break ;
			}
			flag = 1;
		}
	}
	sort(vec.begin(), vec.end());
	sum = round((float)sum / N);
	printf("%d\n",sum);
	printf("%d\n", vec[vec.size() / 2]);
	printf("%d\n", res - 4000);
	printf("%d", vec.back() - vec.front());

}
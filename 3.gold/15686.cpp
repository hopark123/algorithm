#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int		N, M;
int		arr[55][55];
int		dis[100][15];
int		dp[15];
int		res = 10000000;
vector<pair<int, int> > house, chicken;


int		cal_chickendis(void)
{
	int		res = 0;

	for (size_t i = 0; i < house.size(); i++)
	{
		int _min = 1000000000;
		for (size_t j = 0; j < chicken.size(); j++)
		{
			if (dp[j] == 1)
				_min = min(_min, dis[i][j]);
		}
		res += _min;
	}
	return (res);
}

void	cal_dis(void)
{
	for (int i = 0; (size_t)i < house.size(); i++)
	{
		for (int j = 0; (size_t)j < chicken.size(); j++)
			dis[i][j] = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
	}

}

void	bruteForce(int index, int cnt)
{
	if (cnt == M)
	{
		res = min(res, cal_chickendis());
		return ;
	}
	for (int i = index; (size_t)i < chicken.size(); i++)
	{
		dp[i] = 1;
		bruteForce(i + 1, cnt + 1);
		dp[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N >>  M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				house.push_back(make_pair(i, j));
			if (arr[i][j] == 2)
				chicken.push_back(make_pair(i, j));
		}	
	}
	cal_dis();
	bruteForce(0, 0);
	cout << res << endl;

}



// #include <iostream>
// #include <algorithm>

// using namespace std;


// int		N, M, H, C;
// int		arr[55][55];
// int		dis[100][15];
// int		dp[14];
// int		res = 10000000;


// void	chickenmap(void)
// {
// 	int h = 0;
// 	int c = 0;
// 	for (int i = 0; i < N; i++)
// 	{
// 		for (int j = 0; j < N; j++)
// 		{
// 			if (arr[i][j] == 1)
// 			{
// 				c = 0;
// 				for (int k = 0; k < N; k++)
// 				{
// 					for (int t = 0; t < N; t++)
// 					{
// 						if (arr[k][t] == 2)
// 						{
// 							dis[h][c] = abs(i - k) + abs(j - t);
// 							c++;
// 						}
// 					}
// 				}
// 				h++;
// 			}
// 		}
// 	}

// }

// int		cal_chickendis(void)
// {
// 	int		res = 0;

// 	for (int i = 0; i < H; i++)
// 	{
// 		int _min = 1000000000;
// 		for (int j = 0; j < C; j++)
// 		{
// 			if (dp[j] == 1)
// 				_min = min(_min, dis[i][j]);
// 		}
// 		res += _min;
// 	}
// 	return (res);
// }

// void	bruteForce(int index, int cnt)
// {
// 	if (cnt == M)
// 	{
// 		res = min(res, cal_chickendis());
// 		return ;
// 	}
// 	for (int i = index; i < C; i++)
// 	{
// 		dp[i] = 1;
// 		bruteForce(i + 1, cnt + 1);
// 		dp[i] = 0;
// 	}
// }

// int main()
// {
// 	ios::sync_with_stdio(false);
// 	cin >> N >> M;
// 	for (int i = 0; i < N; i++)
// 	{
// 		for (int j = 0; j < N; j++)
// 		{
// 			cin >> arr[i][j];
// 			if (arr[i][j] == 1)
// 				H++;
// 			if (arr[i][j] == 2)
// 				C++;
// 		}
// 	}
// 	chickenmap();
// 	bruteForce(0, 0);
// 	cout << res;
// }
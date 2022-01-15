#include <iostream>
#include <string.h>

using namespace std;

int		L, C;
char	arr[15];
char	ans[15];


void	sort(void)
{
	char	temp;
	for (int i = 0; i < C; i++)
	{
		for (int j = i; j < C; j++)
		{
			if (arr[i] >= arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

bool	checkVow(void)
{
	for (int i = 0; i < L; i++)
	{
		if (ans[i] && strchr("aeiou", ans[i]))
			return (true);
	}
	return (false);
}

bool checkcons(void)
{
	int res = 0;
	for (int i = 0; i < L; i++)
	{
		if (ans[i] && !strchr("aeiou", ans[i]))
			res++;
	}
	if (res >= 2)
		return (true);
	return (false);
}

void	res(int index, int len)
{
	// cout << "i[" <<index <<"][" << len <<"][" << ans << endl; 
	if (len == L && checkVow() && checkcons())
		cout << ans << endl;
	if (len >= L)
		return ;
	for (int i = index; i < C; i++)
	{
		ans[len] = arr[i];
		res(i + 1, len + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> arr[i];
	sort();
	for (int i = 0; i < C; i++)
	{
		ans[0] = arr[i];
		res(i + 1, 1);
	}
}
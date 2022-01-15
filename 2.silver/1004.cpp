#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int		T;
	int		n;
	int		startX,startY, endX,endY;
	int		*x;
	int		*y;
	int		*r;
	int		res;
	int		check;
	
	cin >> T;
	while (T--)
	{
		res = 0;
		scanf("%d %d %d %d %d", &startX, &startY, &endX, &endY, &n);
		x = (int *)malloc(sizeof(int) * n);
		y = (int *)malloc(sizeof(int) * n);
		r = (int *)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++)
			scanf("%d %d %d", &x[i], &y[i], &r[i]);
		for (int i = 0; i < n; i++)
		{
			int dis = pow((x[i] - startX),2) + pow((y[i] - startY),2);
			if (dis < pow(r[i], 2))
				check++;
			dis = pow((x[i] - endX),2) + pow((y[i] - endY),2);
			if (dis < pow(r[i], 2))
				check++;
			if (check == 1)
				res++;
			check = 0;
		}
		cout << res << endl;
		free(x);
		free(y);
		free(r);
	}
}
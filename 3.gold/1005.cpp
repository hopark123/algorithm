#include <iostream>
#include <math.h>
using namespace std;


int		dp[10005];

typedef struct s_order
{
	int				num;
	struct	s_order *next;
}				t_order;

t_order		**init_order(int N)
{
	t_order		**res;

	res = (t_order **)malloc(sizeof(t_order *) * N);
	for (int i = 0; i < N; i++)
	{

		res[i] = (t_order *)malloc(sizeof(t_order));
		res[i]->num = i + 1;
		res[i]->next = NULL;
	}
	return (res);

}

// void	print_order(t_order **order, int N, int *D)
// {
// 	for (int i = 0; i < N; i++)
// 		cout << "[" << D[i] <<"]";
// 	cout << endl;
// 	for (int i = 0; i < N; i++)
// 	{
// 		t_order *temp = order[i];
// 		cout << i + 1;
// 		while (temp)
// 		{
// 			cout << "(" << temp->num << ")";
// 			temp = temp->next;
// 		}
// 		cout << endl;
// 	}
// }

void		add_order(t_order **order, int dest, int src)
{
	t_order		*res;
	t_order		*temp;

	temp = order[dest - 1];
	res = (t_order *)malloc(sizeof(t_order));
	res->num = src;
	res->next = NULL;
	temp = order[dest - 1];
	while (temp && temp->next)
		temp = temp->next;
	temp->next = res;
	temp = order[dest - 1];
}

void		free_order(t_order **order, int N)
{

	for (int i = 0; i < N; i++)
	{
		t_order	*temp = order[i];
		t_order *temp2;
		while (temp)
		{
			temp2 = temp->next;
			free(temp);
			temp = temp2;
		}
	}
	free(order);
}

void	dfs(t_order **order, int N, int *D, int W)
{
	t_order		*temp;
	int			time = 0;

	dp[W - 1] = -1;
	temp = order[W - 1]->next;
	while (temp)
	{
		int		bridge = temp->num;

		if (dp[bridge - 1] != -1)
			dfs(order, N, D, bridge);
		temp = temp->next;
	}
	temp = order[W - 1]->next;
	while (temp)
	{
		time = max(D[temp->num - 1], time);
		temp = temp->next;
	}
	D[W - 1] = time + D[W - 1];

}

int main()
{
	int		T;
	int		N, K, W;
	int		*D;
	t_order	**order;
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--)
	{
		cin >> N;
		cin >> K;
		D = (int *)malloc(sizeof(int) * N);
		for (int i = 0; i < N; i++)
			dp[i] = 0;
		order = init_order(N);
		for (int i = 0; i < N; i++)
			cin >> D[i];
		for (int i = 0; i < K; i++)
		{
			int		dest;
			int		src;
			scanf("%d %d", &src, &dest);
			add_order(order, dest, src);
		}
		cin >> W;
		dfs(order, N, D, W);
		cout << D[W-1] << endl;
		free_order(order, N);
		free(D);
	}
}
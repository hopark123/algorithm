#include <iostream>
#include <limits.h>
#include <math.h>

using namespace std;

int main()
{
	int		res = INT_MAX;
	int		cnt1, cnt2;
	int		M,N;
	char	str[52][52];
	int		arr1[52][52];
	int		arr2[52][52];

	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >>  str[i][j];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if ((i + j) % 2 == 0 && str[i][j] != 'B')
				arr1[i][j] = 1;
			else if ((i + j) % 2 == 1 && str[i][j] != 'W')
				arr1[i][j] = 1;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if ((i + j) % 2 == 0 && str[i][j] != 'W')
				arr2[i][j] = 1;
			else if ((i + j) % 2 == 1 && str[i][j] != 'B')
				arr2[i][j] = 1;
		}
	}
	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			cnt1 = 0;
			cnt2 = 0;
			for (int k = 0; k < 8; k++)
			{
				for (int t = 0; t < 8; t++)
				{
					if (arr1[i + k][j + t] == 1)
						cnt1++;
					if (arr2[i + k][j + t] == 1)
						cnt2++;
				}

			}
			res = min(res, cnt1);
			res = min(res, cnt2);
		}
	}
	cout << res << endl;
}


// #include<stdio.h>

// int main(){
// 	int i,j,n,m,p,q,temp,s=64;
// 	char a[50][51];
// 	scanf("%d %d",&n,&m);
// 	for(i=0;i<n;i++)
// 		scanf("%s",a[i]);
// 	for(i=0;i<=n-8;i++)
// 		for(j=0;j<=m-8;j++){
// 			temp=0;
// 			for(p=0;p<8;p++)
// 				for(q=0;q<8;q++){
// 					if((p+q)%2==1&&a[i+p][j+q]!='B')temp++;
// 					else if((p+q)%2==0&&a[i+p][j+q]!='W')temp++;
// 				}
// 			if(temp>32)
// 				temp=64-temp;
// 			if(temp<s)
// 				s=temp;
// 		}
// 	printf("%d",s);
// }
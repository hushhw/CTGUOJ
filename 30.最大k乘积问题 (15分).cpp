// 3.最大k乘积问题 (15分)
	// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	设I是一个n位十进制整数.如果将I划分为k段,则可得到k个整数.这k个整数的乘积称为I的一个k乘积.试设计一个算法,对于给定的I和k ,求出I的最大k乘积.
	// 	Input
	// 	输入的第1行中有2个正整数n和k.正整数n是序列的长度;正整数k是分割的段数.接下来的一行中是一个n位十进制整数.（n<=10）
	// 	Output
	// 	输出计算结果，第1行中的数是计算出的最大k乘积.
	// 	n位十进制整数.（n<=10）
	// 
	// 	输入样例
	// 	2 1
	// 	15
	// 
	// 	输出样例
	// 	15

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int dp[20][20];

int main()
{
	int n,k;
	int a[11],m[11][11];
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=1; i<=n; i++)
		{
			char h;
			cin>>h;
			a[i]=h-'0';
		}
		memset(m,0,sizeof(m));

		for(int i=1; i<=n; i++)
		{
			m[i][i] = a[i];
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				m[i][j] = m[i][j-1]*10 + m[j][j];
			}
		}

		for(int i=1; i<=n; i++)
		{
			dp[i][1] = m[1][i];
		}

		for(int i=1; i<=n; i++)
		{
			for(int j=0; j<i; j++)
			{
				for(int k=1; k<i; k++)
				{
					dp[i][j] = max(dp[i][j],dp[k][j-1]*m[k+1][i]);
				}
			}
		}
		cout<<dp[n][k]<<endl;
	}
	return 0;
}
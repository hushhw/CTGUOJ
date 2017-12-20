// 5.0-1背包问题 (20分)
// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
// 	题目内容：
// 	背包最大允许装载为C, 有n个物品要放进背包，每个物品的重量为w[1],w[2],...w[n],每个物品的价值为v[1],v[2],...v[n], 请选择物品装进背包，使得价值最大。C为整数。
// 	输入描述
// 	第一行为物体个数n,以及背包容量C；
// 	第二行为n个重量（实数），空格隔开
// 	第三行为n个价值（实数），空格隔开
// 
// 	输出描述
// 	第一行为最大装载的总价值
// 	第二行为每个物品是否装载，1表示装，0表示不装，中间用空格隔开
// 	(测试数据能保证最优解唯一)
// 
// 	输入样例
// 	5 10
// 	2 2 6 5 4
// 	6 3 5 4 6
// 
// 	输出样例
// 	15
// 	1 1 0 0 1
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

struct ball 
{
	int w,m;
};

int main()
{
	int n,C;
	ball a[101];
	int dp[101][101];
	int x[101];
	while(scanf("%d%d",&n,&C)!=EOF)
	{
		for(int i=0; i<n; i++)
			cin>>a[i].w;
		for(int i=0; i<n; i++)
			cin>>a[i].m;
		memset(dp,0,sizeof(dp));
		memset(x,0,sizeof(x));
		for(int i=1; i<=n; i++)
		{
			for(int j=0; j<=C; j++)
			{
				if(i!=1)
					dp[i][j] = dp[i-1][j];
				if(j>=a[i-1].w)
				dp[i][j] = dp[i-1][j] > (dp[i-1][j - a[i-1].w] + a[i-1].m) ? dp[i-1][j] : (dp[i-1][j - a[i-1].w] + a[i-1].m);		
				//cout<<dp[i][j]<<" ";
			}
			//cout<<endl;
		}
		cout<<dp[n][C]<<endl;
		for(int i=n; i>0; i--)
		{
			if(dp[i][C]>dp[i-1][C])
			{
				x[i-1]=1;
				C -= a[i-1].w;
			}
		}
		for(int j=0; j<n; j++)
		{
			cout<<x[j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
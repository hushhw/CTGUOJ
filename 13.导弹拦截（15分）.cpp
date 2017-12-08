// 2.导弹拦截 (15分)
// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
// 	题目内容：
// 	某国为了防御敌国的导弹袭击，研发出一套导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发拦截
// 	炮弹能够到达任意的高度，但是以后每一发拦截炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的多枚导弹来
// 	袭。
// 	输入描述
// 	输入的第一行为导弹的个数n (0<n<10000),接下来的一行为导弹依次飞来的高度h（不大于
// 	30000 的正整数）
// 
// 	输出描述
// 	输出最多拦截的导弹个数。
// 
// 	输入样例
// 	6
// 	5 3 2 4 1 3
// 
// 	输出样例
// 	4

#include <cstdio>
#include <iostream>
#include <string>
#define Nmax 10001
using namespace std;

int a[Nmax],dp[Nmax];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i,j;
		for(i=0; i<n; i++)
			cin>>a[i];
		memset(dp,0,sizeof(dp));
		for(i=1; i<n; i++)
		{
			for(j=0; j<i; j++)
			{
				if(a[j]>a[i] && dp[j]+1>dp[i])
					dp[i] = dp[j]+1;
			}
		}
		int max=dp[0];
		for(i=0; i<n; i++)
		{
			if(dp[i]>max)
				max=dp[i];
		}
		cout<<max+1<<endl;
	}
	return 0;
}
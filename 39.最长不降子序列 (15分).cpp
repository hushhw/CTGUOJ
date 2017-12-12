// 3.最长不降子序列 (15分)
// 	C时间限制：1 毫秒 |  C内存限制：3000 Kb
// 	题目内容：
// 	所谓子序列，就是在原序列里删掉若干个元素后剩下的序列，
// 	以字符串"abcdefg"为例子，去掉bde得到子序列"acfg"现在的问题是，
// 	给你一个数字序列，你要求出它最长的单调不降子序列。
// 	输入描述
// 	多组测试数据，每组测试数据第一行是n(1<=n<=10000)，表示n个数据，
// 	下一行是n个比10^9小的正整数
// 
// 	输出描述
// 	对于每组测试数据输出一行，每行内容是最长的单调不降子序列
// 	的长度
// 
// 	输入样例
// 	5
// 	1 2 4 8 16
// 	5
// 	1 10 4 9 7
// 	9
// 	0 0 0 1 1 1 5 5 5
// 
// 	输出样例
// 	5
// 	3
// 	9
#include <cstdio>
#include <iostream>
#include <string>
#define N 10001
using namespace std;

int dp[N];

int main()
{
	int n;
	int a[N];
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0; i<n; i++)
			cin>>a[i];
		memset(dp,0,sizeof(dp));
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<i; j++)
			{
				if(a[i]>=a[j] && dp[i]<dp[j]+1)
					dp[i] = dp[j]+1;

			}
		}
		int max=dp[0];
		for(int i=0; i<n; i++)
		{
			if(dp[i]>max)
				max=dp[i];
		}
		cout<<max+1<<endl;
	}
	return 0;
}
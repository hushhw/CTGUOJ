// 4.滑雪 (10分)
// 	C时间限制：1 毫秒 |  C内存限制：3000 Kb
// 	题目内容：
// 	Michael喜欢滑雪这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael想知道载一个区域中最长底滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子 
// 	1  2  3  4 5
// 	16 17 18 19 6
// 	15 24 25 20 7
// 	14 23 22 21 8
// 	13 12 11 10 9
// 	一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。
// 	输入描述
// 	输入的第一行表示区域的行数R和列数C(1<=R,C<=100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。
// 
// 	输出描述
// 	输出最长区域的长度。
// 
// 	输入样例
// 	5 5
// 	1 2 3 4 5
// 	16 17 18 19 6
// 	15 24 25 20 7
// 	14 23 22 21 8
// 	13 12 11 10 9
// 
// 	输出样例
// 	25

#include <cstdio>
#include <iostream>
#include <string>
#define Nmax 101
using namespace std;

int a[Nmax][Nmax];
int dp[Nmax][Nmax];
int N,M;

int inMap(int x,int y)
{  
	if(x>=0 && x<=N-1 && y>=0 && y<=M-1) 
		return 1;  
	return 0;  
}  

int max2(int a,int b,int c,int d)
{  
	return max(max(a,b),max(c,d));  
}  

int sking(int n, int i, int j)
{
	int l=0,r=0,u=0,d=0;

	if(dp[i][j]) 
		return dp[i][j];  
	if(inMap(i-1,j))
	{
		if(a[i-1][j]<n)
		{
			u=sking(a[i-1][j],i-1,j);
		}
	}
	if(inMap(i+1,j))
	{
		if(a[i+1][j]<n)
		{
			d=sking(a[i+1][j],i+1,j);
		}
	}
	if(inMap(i,j-1))
	{
		if(a[i][j-1]<n)
		{
			l=sking(a[i][j-1],i,j-1);
		}
	}
	if(inMap(i,j+1))
	{
		if(a[i][j+1]<n)
		{
			r=sking(a[i][j+1],i,j+1);
		}
	}

	dp[i][j]=max2(l,r,u,d)+1;
	return dp[i][j];
}

int main()
{
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		int i,j;
		for(i=0; i<N; i++)
			for(j=0; j<M; j++)
			{
				cin>>a[i][j];
			}
			int ans=-1;
			for(i=0; i<N; i++)
			{
				for(j=0; j<M; j++)
				{
					ans = max(ans,sking(a[i][j],i,j));
				}
			}
			cout<<ans<<endl;
	}
	return 0;
}


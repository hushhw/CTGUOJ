// 3.涂色问题 (15分)
	// 	C时间限制：1 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	有排成一行的ｎ个方格，用红(Red)、粉(Pink)、绿(Green)三色涂每个格子，每格涂一色，要求任何相邻的方格不能同色，且首尾两格也不同色．求全部的满足要求的涂法。
	// 	输入描述
	// 	输入正整数n
	// 
	// 	输出描述
	// 	输出结果
	// 
	// 	输入样例
	// 	5
	// 
	// 	输出样例
	// 	30



#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{

// 	找规律的题目：
// 		首先易知f(1)=3;f(2)=6;f(3)=6;f(4)=18;
// 
// 	现在考虑n>3的情况，若第n-1个格子和第一个格子不同，则为f(n-1)；
// 
// 		若第n-1个格子和第1个格子相同，则第n-2个格子和第一个格子必然不同，此时为f(n-2)再乘第n-1个格子的颜色数，很显然第n-1个格子可以是第一个格子（即第n-2个格子）的颜色外的另外两种，这样为2*f(n-2)；
// 
// 		因此总的情况为f(n)=f(n-1)+2*f(n-2);
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a[101];
		a[1]=3;
		a[2]=6;
		a[3]=6;
		for(int i=4; i<=n; i++)
		{
			a[i] = a[i-1] + a[i-2]*2;
		}
		cout<<a[n]<<endl;
	}
	return 0;
}
// 3.极差 (15分)
// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
// 	题目内容：
// 	在黑板上写了N个正整数组成的一个数列，进行如下操作：每次擦去其中的两个数a和b，
// 	然后在数列中加入一个数a*b＋1，如此下去直至黑板上剩下一个数，在所有按这种操作方式
// 	最后得到的数中，最大的为max，最小的为min，则该数列的极差定义为M＝max－min.请你编程，
// 	对于给定的数列，计算极差.
// 	输入描述
// 	输入包含多个测试集.每个测试集的第一行N表示正整数序列长度（0＜＝N＜＝50000），随后第二行是N个正整数.当N为0时结束.
// 
// 	输出描述
// 	每个结果一行.
// 
// 	输入样例
// 	3
// 	3 5 7
// 
// 	输出样例
// 	4
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#define N 50001
using namespace std;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int n;
	int a[N];
	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=0; i<n; i++)
			cin>>a[i];
		sort(a,a+n);
		int min=a[0]*a[1]+1;
		for(int i=2; i<n; i++)
		{
			min = min*a[i]+1;
		}
		sort(a,a+n,cmp);
		int max=a[0]*a[1]+1;
		for(int i=2; i<n; i++)
		{
			max = max*a[i]+1;
		}
		int sum=0;
		sum = min-max;
		cout<<sum<<endl;
	}
	return 0;
}
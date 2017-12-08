// 8.寻找第K大值 (15分)
// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
// 	题目内容：
// 	在一个整数数组中，寻找第k大值所在位置。假设每个数值都不一样。要求算法时间复杂性通常情况下为线性。
// 	输入描述
// 	包括一个数组长度n,一个k, 以及紧接着的n个整数值。整数之间用空格隔开。
// 
// 	输出描述
// 	第k大值所在位置编号。规定数组的第一个位置编号为0.
// 
// 	输入样例
// 	7 3
// 	1 4 3 9 8 7 2
// 
// 	输出样例
// 	5

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n,k;
	int a[101],b[101];
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=0; i<n; i++)
		{
			cin>>a[i];
			b[i]=a[i];
		}
		sort(a,a+n);
		for(int i=0; i<n; i++)
		{
			if(b[i]==a[n-k])
				cout<<i<<endl;
		}
	}
	return 0;
}

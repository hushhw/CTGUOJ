
// 6.最大子段和 (20分)
// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
// 	题目内容：
// 	实数序列a[1],a[2],...a[n], 一个子段指一段连续的子序列a[i],a[i+1],...a[j], 其中1<=i<=j<=n. 要求给出具有最大和的子段。要求算法时间复杂性为o(n)。
// 	输入描述
// 	第一行输入一个整数n,表示原序列共有n个数据；
// 	第二行输入n个实数，用空格隔开。
// 
// 	输出描述
// 	最大和的子段，每个数据也用空格隔开。
// 	（本题的测试数据能保证最大和的那一个子段是唯一的）
// 
// 	输入样例
// 	7
// 	-1 3 -2 4 -1 6 -5
// 
// 	输出样例
// 	3 -2 4 -1 6

#include <cstdio>
#include <iostream>
#include <string>
#define NUM 101
using namespace std;

int main()
{
	int n;
	int a[101];
	while(scanf("%d",&n)!=EOF)
	{
		int i;
		for(i=0; i<n; i++)
			cin>>a[i];
		int sum = -999999;
		int b=0;
		int begin=0,bestj;
		for(i=0; i<n; i++)
		{
			if(b>0)
			{
				b+=a[i];
			}
			else
			{
				b = a[i];
				begin = i;
			}
			if(b>sum)
			{
				sum = b;
				bestj = i;
			}
		}
		for(i=begin; i<=bestj; i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}
// 7.组合数 (15分)
	// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	找出n个自然数（1,2···n）中取r个数的组合，例如当n=5，r=3时所有组合为
	// 	1 2 3 
	// 	1 2 4
	// 	1 2 5
	// 	1 3 4
	// 	1 3 5
	// 	1 4 5
	// 	2 3 4
	// 	2 3 5
	// 	2 4 5
	// 	3 4 5
	// 	此题只需求出组合数的个数
	// 	输入描述
	// 	输入两个正整数n、r
	// 
	// 	输出描述
	// 	计算出n个自然数中取r个数的组合数的个数
	// 
	// 	输入样例
	// 	5 3
	// 	20 18
	// 
	// 	输出样例
	// 	10
	// 	190

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if(b>a/2)
			b = a-b;
		int sum=0,sum_a=1,sum_b=1;
		for(int i=1; i<=b; i++)
			sum_b*=i;
		while(b)
		{
			sum_a*=a;
			a--;
			b--;
		}
		sum = sum_a/sum_b;
		cout<<sum<<endl;
	}
	return 0;
}
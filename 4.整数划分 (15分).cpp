/*
1.整数划分 (15分)
	C时间限制：2 毫秒 |  C内存限制：65535 Kb
	题目内容：
	对于一个正整数n的划分，就是把n变成一系列正整数之和的表达式。注意，分划与顺序无关，例如6=5+1跟6=1+5是
	同一种分划。另外，单独这个整数本身也算一种分划。
	例如：对于正整数n=5，可以划分为：
	1+1+1+1+1
	1+1+1+2
	1+1+3
	1+2+2
	2+3
	1+4
	5
	输入描述
	输入一个正整数n

	输出描述
	输出n整数划分的总数k

	输入样例
	5

	输出样例
	7
	*/

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int huafen(int n, int w)
{
	if(n==1 || w==1)
		return 1;
	else if(n<w)
		return huafen(n,n);
	else if(n==w)
		return huafen(n,n-1)+1;
	else if(n>w)
		return huafen(n,w-1) + huafen(n-w,w);
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		cout<<huafen(n,n)<<endl;
	}
	return 0;
}
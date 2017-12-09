// 8.完美数 (15分)
// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
// 	题目内容：
// 	如果有一正整数n，其真因数的总和等于n，则称之为完美数。
// 	例如以下几个数都是完美数：
// 	6=1+2+3
// 	28=1+2+4+7+14
// 	496=1+2+4+8+16+31+62+124+248
// 	求小于n的所有完美数.
// 
// 	输入描述
// 	输入一个正整数n
// 
// 	输出描述
// 	输出小于n的完美数，按升序输出，每个数据占一行
// 
// 	输入样例
// 	10
// 
// 	输出样例
// 	6

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

bool signal(int n)
{
	int sum=0;
	for(int i=1; i<n; i++)
	{
		if(n%i==0)
			sum+=i;
	}
	if(sum==n)
		return true;
	else
		return false;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=6; i<=n; i++)
		{
			if(signal(i))
				cout<<i<<endl;
		}
	}
	return 0;
}
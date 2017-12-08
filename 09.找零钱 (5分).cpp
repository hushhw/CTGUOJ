// 
	// 3.找零钱 (5分)
	// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	一个小孩买了价值少于1美元的糖，假设提供了数目不限的面值为2 5美分、1 0美分、5美分、及1美分的硬币，写一个算法让小孩用最少的硬币付款。1美元=100美分
	// 	输入描述
	// 	糖的价格
	// 
	// 	输出描述
	// 	4种硬币的个数，中间用空格隔开。
	// 
	// 	输入样例
	// 	75
	// 
	// 	输出样例
	// 	3 0 0 0

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a=0,b=0,c=0,d=0;
		while(n)
		{
			if(n>=25)
			{
				n-=25;
				a++;
			}
			else if(n<25 && n>=10)
			{
				n-=10;
				b++;
			}
			else if(n<10 && n>=5)
			{
				n-=5;
				c++;
			}
			else if(n<5 && n>=1)
			{
				n--;
				d++;
			}
		}
		cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	}
	return 0;
}
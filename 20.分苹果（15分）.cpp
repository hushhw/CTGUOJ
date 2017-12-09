// 2.分苹果 (15分)
// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
// 	题目内容：
// 	把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？M, N为自然数。说明：如有7个苹果，2个盘子，则(5, 1, 1)和(1, 5, 1)和(1, 1, 5)都是同一种分法。
// 	输入描述
// 	第一行一个整数表示数据的组数（多组数据），对于每组数据第一行是苹果个数M (1 ≤ m ≤ 100) ，第二行是盘子个数N(1 ≤ n ≤ 100)。
// 
// 	输出描述
// 	每组数据输出一行,放苹果的方法个数。
// 
// 	输入样例
// 	1 
// 	3 
// 	2
// 
// 	输出样例
// 	2

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int sum;

int apple(int m, int n)
{
	if(n>m)
		n=m;
	if(m==1 || n==1 ||m==0)
		return 1;
	else
	{
		return apple(m-n,n)+apple(m,n-1);
	}
}

int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		int m,n;
		cin>>m>>n;
		sum = apple(m,n);
		cout<<sum<<endl;
	}
	//system("pause");
	return 0;
}
// 4.花儿朵朵 (15分)
// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
// 	题目内容：
// 	春天到了，花儿朵朵盛开，hrdv是一座大花园的主人，在他的花园里种着许多种鲜花，每当这个时候，就会有一大群游客来他的花园欣赏漂亮的花朵，游客们总是会询问，某个时间有多少种花儿同时在盛开着？hrdv虽然知道每种花儿的开花时间段，但是他不能很快的答出游客的问题，你能编写一个程序帮助他吗？
// 	输入描述
// 	第一行有个整数t,表示有t组测试数据，每组测试数据第一行为两个整数n,m，表示有n种花;游客询问m个时间。随后有n行，每一行有两个整数x,y，表示这一种花的盛开时间是从x到y；随后有m行，每行有一个整数，代表游客询问的时间。
// 
// 	输出描述
// 	对于每次游客的询问，输出一个整数在单独的一行，表示这个时间盛开的花有多少种。
// 
// 	输入样例
// 	2
// 	1 1
// 	5 10
// 	4
// 	2 3
// 	1 4
// 	4 8
// 	1
// 	4
// 	6
// 
// 	输出样例
// 	0
// 	1
// 	2
// 	1

#include <cstdio>
#include <iostream>
#include <string>
#define Nmax 1001
using namespace std;

struct time
{
	int x,y;
};

int main()
{
	int N;
	cin>>N;
	time t[Nmax];
	int a[Nmax];
	while(N--)
	{
		int n,m;
		int sum;
		cin>>n>>m;
		int i,j;
		for(i=0; i<n; i++)
			cin>>t[i].x>>t[i].y;
		for(i=0; i<m; i++)
		{
			cin>>a[i];
			sum=0;
			for(j=0; j<n; j++)
			{
				if(a[i]>=t[j].x && a[i]<=t[j].y)
					sum++;
			}
			cout<<sum<<endl;
		}
	}
	system("pause");
	return 0;
}
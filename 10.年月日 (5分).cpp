// 3.年月日 (5分)
	// 	C时间限制：1 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	输入某年某月某日，判断这一天是这一年的第几天？
	// 	输入描述
	// 	依次输入年月日，中间用空格隔开，如
	// 	2012 6 10
	// 
	// 	输出描述
	// 	2012-6-10是这年的第162天
	// 
	// 	输入样例
	// 	2012 6 10
	// 
	// 	输出样例
	// 	162

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
	int y,m,d;
	while(scanf("%d%d%d",&y,&m,&d)!=EOF)
	{
		int sum=0;
		for(int i=1;i<m;i++)
			sum+=month[i];
		sum+=d;
		if(((y%4)==0 && (y%100)!=0)||(y%400==0))
			sum++;
		cout<<sum<<endl;
	}
	return 0;
}
// 8.灯泡 (15分)
	// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	一百个灯泡排成一排，第一轮将所有灯泡打开；
	// 	第二轮每隔一个灯泡关掉一个。即排在偶数的灯泡被关掉，
	// 	第三轮每隔两个灯泡，将开着的灯泡关掉，关掉的灯泡打开。
	// 	依次类推，第n轮结束的时候，还有几盏灯泡亮着。
	// 	输入描述
	// 	程序输入n( 0 < n < 101)
	// 
	// 	输出描述
	// 	输出亮的灯数。
	// 
	// 	输入样例
	// 	2
	// 
	// 	输出样例
	// 	50

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a[101]={0};
	int n;
	cin>>n;
	int sum=0;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=100; j++)
		{
			if(j%i==0)
			{
				if(a[j]==0)
					a[j]=1;
				else
					a[j]=0;
			}
		}
	}
	for(int j=1; j<=100; j++)
		sum+=a[j];
	cout<<sum<<endl;
	system("pause");
	return 0;
}

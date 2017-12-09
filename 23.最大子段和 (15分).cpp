// 5.最大字段和 (15分)
// 	C时间限制：1 毫秒 |  C内存限制：3000 Kb
// 	题目内容：
// 	给定长度为n的整数序列，a[1...n], 求[1,n]某个子区间[i , j]使得a[i]+…+a[j]和最大.或者求出最大的这个和.例如(-2,11,-4,13,-5,2)的最大子段和为20,所求子区间为[2,4].
// 	输入描述
// 	第一行为一个整数n，表示数组有n个数据，第二行依次输入n个整数
// 
// 	输出描述
// 	计算出n个整数中连续k个数的最大和
// 
// 	输入样例
// 	5
// 	1 2 3 4 5
// 
// 	7
// 	6 -5 5 8 -13 5 7
// 
// 	输出样例
// 	15
// 	14

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
		for(i=0; i<n; i++)
		{
			if(b>0)
				b+=a[i];
			else
				b = a[i];
			if(b>sum)
			{
				sum = b;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
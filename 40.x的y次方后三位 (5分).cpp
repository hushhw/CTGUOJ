// 4.x的y次方后三位 (5分)
	// 	C时间限制：1 毫秒 |  C内存限制：65535 Kb
	// 	题目内容：
	// 	解本题最直接的方法是：将13累乘13次方截取最后三位即可。
	// 	但是由于计算机所能表示的整数范围有限，用这种“正确”的算法不可能得到正确的结果。事实上，题目仅要求最后三位的值，完全没有必要求13的13次方的完整结果。
	// 	研究乘法的规律发现：乘积的最后三位的值只与乘数和被乘数的后三位有关，与乘数和被乘数的高位无关。利用这一规律，可以大大简化程序。
	// 	输入描述
	// 	数据分n组，对于每组数据有两个正整数x和y（x的y次方必须大于100）
	// 
	// 	输出描述
	// 	对于每组输出，输出一个值，即x的y次方结果的最后三位数
	// 	提示：13的13次方为：302875106592253（这个数已经超出一般计算机表示的范围了）
	// 
	// 	输入样例
	// 	1
	// 	13 13
	// 
	// 	输出样例
	// 	253
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while (n--)
	{
		int x,y;
		cin>>x>>y;
		int m=x,sum=0;
		for(int i=0; i<y-1; i++)
		{
			sum = x*m;
			m = sum%1000;
		}
		cout<<m<<endl;
	}
	system("pause");
	return 0;
}

// 3.分数 (15分)
	// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	写出一个程序，接受一个以N/D的形式输入的分数，其中N为分子，D为分母，输出它的小数形式。
	// 
	// 	本题中，0≤N≤65535，0<D≤65535，设运算结果小数点后最多保留100位。
	// 	输入描述
	// 	分别输入N D
	// 
	// 	输出描述
	// 	如果它的小数形式存在循环，则要将其循环节用括号括起来。例如：
	// 	1/3= 0.(3)
	// 
	// 	输入样例
	// 	1 7
	// 
	// 	输出样例
	// 	0.(142857)

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

void moni(int N, int D)
{
	int i=0;
	int a[101];
	int l=0,signal=0;
	while(N<D && i<100 && signal==0)
	{
		N*=10;
		a[i]=N/D;
		N = N%D;
		for(int j=0; j<i; j++)
		{
			if(a[j]==a[i])
			{
				l=j;
				signal=-1;
				break;
			}
		}
		i++;
	}

	if(N==D || i>=100)
	{
		for(int j=0; j<i-1; j++)
			cout<<a[j];
	}
	if(signal!=0)
	{
		for(int j=0; j<i-1; j++)
		{
			if(j!=l)
				cout<<a[j];
			else if(j==l)
				cout<<"("<<a[j];
		}
		cout<<")";
	}
}

int main()
{
	int N,D;
	while(scanf("%d%d",&N,&D)!=EOF)
	{
		int z,y;
		if(N>=D)
		{
			z=N/D;
			y=N%D;
			cout<<z<<".";
			moni(y,D);
		}
		else
		{
			cout<<"0.";
			moni(N,D);
		}
		cout<<endl;
	}
	return 0;
}
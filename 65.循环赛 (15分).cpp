// 18.循环赛 (15分)
// 	C时间限制：1 毫秒 |  C内存限制：3000 Kb
// 	题目内容：
// 	设有n个运动员要进行网球循环赛。设计一个满足以下要求的比赛日程表：
// 	（1）每个选手必须与其他n-1个选手各比赛一次；
// 	（2）每个选手一天只能参加一场比赛；
// 	（3）当n是偶数时，循环赛进行n-1天。当n是奇数时，循环赛进行n天。
// 	输入描述
// 	输入正整数n，n表示参赛人数，假设n位选手的顺序编号为1,2,...,n(由于此题有多种答案，故测试数据为样例数据，即通过样例数据就能AC了)
// 
// 	输出描述
// 	第一行第一个数打印0，其后为1...m（根据n的奇偶性而定），表示
// 	比赛日期。第一列为1...n，表示参赛选手的编号。余下的n行m列表示第n号选手
// 	在第m天的比赛对手。用0表示该选手该天比赛轮空，每个数据占三位。
// 
// 	提示：
// 	根据分而治之的原则，可从其中一半选手(2^(n-1位)的比赛日程，导出全体n位选手的日程，最终细分到只有两位选手的比赛日程出发。
// 
// 	输入样例
// 	3
// 
// 	输出样例
// 	0  1  2  3
// 	1  2  3  0
// 	2  1  0  3
// 	3  0  1  2
#include <cstdio>  
#include <iostream>
#include <string>
#define N 1000  
using namespace std;

int a[10][10];

void copy(int n)
{
	int i,j;
	int m = n/2;
	for(  i = 0 ; i < m ; i++ )
	{
		for(  j = 0 ; j < m ; j++ )
		{
			a[i][j + m] = a[i][j] + m;
			a[i + m][j] = a[i][j + m];
			a[i + m][j + m] = a[i][j];
		}
	}
}

void copyodd(int n)
{      
	int m=n/2,b[100],i,j;
	for (  i = 0 ; i < m ; i++ )
	{
		b[i]=m+i;
		b[m+i]=b[i];
	}

	for(  i = 0 ; i < m ; i++ )
	{
		for (  j = 0 ; j < m+1 ; j++ )
		{	
			if (a[i][j]>=m)
			{ 
				a[i][j]=b[i];
				a[m+i][j]=(b[i]+m)%n;
			}
			else
				a[m+i][j]=a[i][j]+m;
		}
		for (  j = 1 ; j < m ; j++ )
		{
			a[i][m+j]=b[i+j];
			a[b[i+j]][m+j]=i;
		}
	}
}

void makecopy(int n)
{ 
	if( (n/2>1) && (n%2!=0)) 
		copyodd(n);
	else 
		copy(n);
}



void tourna(int n)
{
	if( n == 1 )
	{
		a[1][1] = 1;
		return;
	}

	if (n%2!=0)
	{ 
		tourna (n+1);
		return;
	}

	tourna(n/2);
	makecopy(n);
}




int main()
{  
	int n = 1,i,j;
	int k;
	while(~scanf("%d",&n))
	{
		tourna(n);
		int num;
		if(n%2==0)
			num=n-1;
		else
			num=n;
// 		for( i = 0; i<=num; i++)
// 		{
// 			if(i==0)
// 				printf("0");
// 			else
// 				printf("%3d",i);
// 		}
// 		cout<<endl;
		for(  i = 0 ; i <= num ; i++ )
		{
			for(  j = 0 ; j <= num ; j++ )
			{
				if(a[i][j]>n)
					a[i][j]=0;
				if(j==0)
					printf("%d", a[i][j]);
				else
					printf("%3d", a[i][j]);
			}
			printf("\n");
		}
	}
	
	system("pause");
	return 0;
}
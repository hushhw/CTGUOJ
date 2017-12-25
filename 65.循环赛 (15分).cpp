// 18.ѭ���� (15��)
// 	Cʱ�����ƣ�1 ���� |  C�ڴ����ƣ�3000 Kb
// 	��Ŀ���ݣ�
// 	����n���˶�ԱҪ��������ѭ���������һ����������Ҫ��ı����ճ̱�
// 	��1��ÿ��ѡ�ֱ���������n-1��ѡ�ָ�����һ�Σ�
// 	��2��ÿ��ѡ��һ��ֻ�ܲμ�һ��������
// 	��3����n��ż��ʱ��ѭ��������n-1�졣��n������ʱ��ѭ��������n�졣
// 	��������
// 	����������n��n��ʾ��������������nλѡ�ֵ�˳����Ϊ1,2,...,n(���ڴ����ж��ִ𰸣��ʲ�������Ϊ�������ݣ���ͨ���������ݾ���AC��)
// 
// 	�������
// 	��һ�е�һ������ӡ0�����Ϊ1...m������n����ż�Զ���������ʾ
// 	�������ڡ���һ��Ϊ1...n����ʾ����ѡ�ֵı�š����µ�n��m�б�ʾ��n��ѡ��
// 	�ڵ�m��ı������֡���0��ʾ��ѡ�ָ�������ֿգ�ÿ������ռ��λ��
// 
// 	��ʾ��
// 	���ݷֶ���֮��ԭ�򣬿ɴ�����һ��ѡ��(2^(n-1λ)�ı����ճ̣�����ȫ��nλѡ�ֵ��ճ̣�����ϸ�ֵ�ֻ����λѡ�ֵı����ճ̳�����
// 
// 	��������
// 	3
// 
// 	�������
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
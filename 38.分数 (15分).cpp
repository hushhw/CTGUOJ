// 3.���� (15��)
	// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
	// 	��Ŀ���ݣ�
	// 	д��һ�����򣬽���һ����N/D����ʽ����ķ���������NΪ���ӣ�DΪ��ĸ���������С����ʽ��
	// 
	// 	�����У�0��N��65535��0<D��65535����������С�������ౣ��100λ��
	// 	��������
	// 	�ֱ�����N D
	// 
	// 	�������
	// 	�������С����ʽ����ѭ������Ҫ����ѭ���������������������磺
	// 	1/3= 0.(3)
	// 
	// 	��������
	// 	1 7
	// 
	// 	�������
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
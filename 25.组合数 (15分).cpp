// 7.����� (15��)
	// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
	// 	��Ŀ���ݣ�
	// 	�ҳ�n����Ȼ����1,2������n����ȡr��������ϣ����統n=5��r=3ʱ�������Ϊ
	// 	1 2 3 
	// 	1 2 4
	// 	1 2 5
	// 	1 3 4
	// 	1 3 5
	// 	1 4 5
	// 	2 3 4
	// 	2 3 5
	// 	2 4 5
	// 	3 4 5
	// 	����ֻ�����������ĸ���
	// 	��������
	// 	��������������n��r
	// 
	// 	�������
	// 	�����n����Ȼ����ȡr������������ĸ���
	// 
	// 	��������
	// 	5 3
	// 	20 18
	// 
	// 	�������
	// 	10
	// 	190

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if(b>a/2)
			b = a-b;
		int sum=0,sum_a=1,sum_b=1;
		for(int i=1; i<=b; i++)
			sum_b*=i;
		while(b)
		{
			sum_a*=a;
			a--;
			b--;
		}
		sum = sum_a/sum_b;
		cout<<sum<<endl;
	}
	return 0;
}
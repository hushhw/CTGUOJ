// 4.�ر�������� (15��)
	// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
	// 	��Ŀ���ݣ�
	// 	YF�����������������Ȳ�ϲ��6��Ҳ��ϲ��8����������������4��7�����һ��������ֻ����4��7��������Ϊ���������������������
	// 	���ڸ�������������a,b��Ҫ�󷵻�a,b֮����������ĸ���������a,b����
	// 	��������
	// 	��һ��������Ŀn,��ʾ������n��ab
	// 	��2�п�ʼ��ÿ��һ��a b, �ո������
	// 
	// 	�������
	// 	ÿ�����һ��������a,b֮����������ĸ�����
	// 
	// 	��������
	// 	3
	// 	11 20
	// 	4 7
	// 	1 10
	// 
	// 	�������
	// 	0
	// 	2
	// 	2

#include <cstdio>
#include <iostream>
#include <string>
#define SUM 101
using namespace std;

bool signal(int n)
{
	int x=0;
	int a[SUM];
	while(n)
	{
		a[x] = n%10;
		x++;
		n = n/10;
	}
	for(int i=x-1; i>=0; i--)
	{
		if(a[i]!=4 && a[i]!=7)
			return false;
	}
	return true;
}

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		int i;
		int sum=0;
		for(i=a; i<=b; i++)
		{
			if(signal(i))
				sum++;
		}
		cout<<sum<<endl;
	}
	system("pause");
	return 0;
}
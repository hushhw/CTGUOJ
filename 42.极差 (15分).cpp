// 3.���� (15��)
// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
// 	��Ŀ���ݣ�
// 	�ںڰ���д��N����������ɵ�һ�����У��������²�����ÿ�β�ȥ���е�������a��b��
// 	Ȼ���������м���һ����a*b��1�������ȥֱ���ڰ���ʣ��һ�����������а����ֲ�����ʽ
// 	���õ������У�����Ϊmax����С��Ϊmin��������еļ����ΪM��max��min.�����̣�
// 	���ڸ��������У����㼫��.
// 	��������
// 	�������������Լ�.ÿ�����Լ��ĵ�һ��N��ʾ���������г��ȣ�0����N����50000�������ڶ�����N��������.��NΪ0ʱ����.
// 
// 	�������
// 	ÿ�����һ��.
// 
// 	��������
// 	3
// 	3 5 7
// 
// 	�������
// 	4
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#define N 50001
using namespace std;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int n;
	int a[N];
	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=0; i<n; i++)
			cin>>a[i];
		sort(a,a+n);
		int min=a[0]*a[1]+1;
		for(int i=2; i<n; i++)
		{
			min = min*a[i]+1;
		}
		sort(a,a+n,cmp);
		int max=a[0]*a[1]+1;
		for(int i=2; i<n; i++)
		{
			max = max*a[i]+1;
		}
		int sum=0;
		sum = min-max;
		cout<<sum<<endl;
	}
	return 0;
}
// 8.Ѱ�ҵ�K��ֵ (15��)
// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
// 	��Ŀ���ݣ�
// 	��һ�����������У�Ѱ�ҵ�k��ֵ����λ�á�����ÿ����ֵ����һ����Ҫ���㷨ʱ�临����ͨ�������Ϊ���ԡ�
// 	��������
// 	����һ�����鳤��n,һ��k, �Լ������ŵ�n������ֵ������֮���ÿո������
// 
// 	�������
// 	��k��ֵ����λ�ñ�š��涨����ĵ�һ��λ�ñ��Ϊ0.
// 
// 	��������
// 	7 3
// 	1 4 3 9 8 7 2
// 
// 	�������
// 	5

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n,k;
	int a[101],b[101];
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=0; i<n; i++)
		{
			cin>>a[i];
			b[i]=a[i];
		}
		sort(a,a+n);
		for(int i=0; i<n; i++)
		{
			if(b[i]==a[n-k])
				cout<<i<<endl;
		}
	}
	return 0;
}

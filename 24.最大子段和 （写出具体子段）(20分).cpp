
// 6.����Ӷκ� (20��)
// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
// 	��Ŀ���ݣ�
// 	ʵ������a[1],a[2],...a[n], һ���Ӷ�ָһ��������������a[i],a[i+1],...a[j], ����1<=i<=j<=n. Ҫ������������͵��ӶΡ�Ҫ���㷨ʱ�临����Ϊo(n)��
// 	��������
// 	��һ������һ������n,��ʾԭ���й���n�����ݣ�
// 	�ڶ�������n��ʵ�����ÿո������
// 
// 	�������
// 	���͵��ӶΣ�ÿ������Ҳ�ÿո������
// 	������Ĳ��������ܱ�֤���͵���һ���Ӷ���Ψһ�ģ�
// 
// 	��������
// 	7
// 	-1 3 -2 4 -1 6 -5
// 
// 	�������
// 	3 -2 4 -1 6

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
		int begin=0,bestj;
		for(i=0; i<n; i++)
		{
			if(b>0)
			{
				b+=a[i];
			}
			else
			{
				b = a[i];
				begin = i;
			}
			if(b>sum)
			{
				sum = b;
				bestj = i;
			}
		}
		for(i=begin; i<=bestj; i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}
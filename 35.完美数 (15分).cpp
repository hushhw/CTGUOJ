// 8.������ (15��)
// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
// 	��Ŀ���ݣ�
// 	�����һ������n�������������ܺ͵���n�����֮Ϊ��������
// 	�������¼�����������������
// 	6=1+2+3
// 	28=1+2+4+7+14
// 	496=1+2+4+8+16+31+62+124+248
// 	��С��n������������.
// 
// 	��������
// 	����һ��������n
// 
// 	�������
// 	���С��n���������������������ÿ������ռһ��
// 
// 	��������
// 	10
// 
// 	�������
// 	6

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

bool signal(int n)
{
	int sum=0;
	for(int i=1; i<n; i++)
	{
		if(n%i==0)
			sum+=i;
	}
	if(sum==n)
		return true;
	else
		return false;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=6; i<=n; i++)
		{
			if(signal(i))
				cout<<i<<endl;
		}
	}
	return 0;
}
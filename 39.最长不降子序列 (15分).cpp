// 3.����������� (15��)
// 	Cʱ�����ƣ�1 ���� |  C�ڴ����ƣ�3000 Kb
// 	��Ŀ���ݣ�
// 	��ν�����У�������ԭ������ɾ�����ɸ�Ԫ�غ�ʣ�µ����У�
// 	���ַ���"abcdefg"Ϊ���ӣ�ȥ��bde�õ�������"acfg"���ڵ������ǣ�
// 	����һ���������У���Ҫ�������ĵ������������С�
// 	��������
// 	����������ݣ�ÿ��������ݵ�һ����n(1<=n<=10000)����ʾn�����ݣ�
// 	��һ����n����10^9С��������
// 
// 	�������
// 	����ÿ������������һ�У�ÿ����������ĵ�������������
// 	�ĳ���
// 
// 	��������
// 	5
// 	1 2 4 8 16
// 	5
// 	1 10 4 9 7
// 	9
// 	0 0 0 1 1 1 5 5 5
// 
// 	�������
// 	5
// 	3
// 	9
#include <cstdio>
#include <iostream>
#include <string>
#define N 10001
using namespace std;

int dp[N];

int main()
{
	int n;
	int a[N];
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0; i<n; i++)
			cin>>a[i];
		memset(dp,0,sizeof(dp));
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<i; j++)
			{
				if(a[i]>=a[j] && dp[i]<dp[j]+1)
					dp[i] = dp[j]+1;

			}
		}
		int max=dp[0];
		for(int i=0; i<n; i++)
		{
			if(dp[i]>max)
				max=dp[i];
		}
		cout<<max+1<<endl;
	}
	return 0;
}
// 5.0-1�������� (20��)
// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
// 	��Ŀ���ݣ�
// 	�����������װ��ΪC, ��n����ƷҪ�Ž�������ÿ����Ʒ������Ϊw[1],w[2],...w[n],ÿ����Ʒ�ļ�ֵΪv[1],v[2],...v[n], ��ѡ����Ʒװ��������ʹ�ü�ֵ���CΪ������
// 	��������
// 	��һ��Ϊ�������n,�Լ���������C��
// 	�ڶ���Ϊn��������ʵ�������ո����
// 	������Ϊn����ֵ��ʵ�������ո����
// 
// 	�������
// 	��һ��Ϊ���װ�ص��ܼ�ֵ
// 	�ڶ���Ϊÿ����Ʒ�Ƿ�װ�أ�1��ʾװ��0��ʾ��װ���м��ÿո����
// 	(���������ܱ�֤���Ž�Ψһ)
// 
// 	��������
// 	5 10
// 	2 2 6 5 4
// 	6 3 5 4 6
// 
// 	�������
// 	15
// 	1 1 0 0 1
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

struct ball 
{
	int w,m;
};

int main()
{
	int n,C;
	ball a[101];
	int dp[101][101];
	int x[101];
	while(scanf("%d%d",&n,&C)!=EOF)
	{
		for(int i=0; i<n; i++)
			cin>>a[i].w;
		for(int i=0; i<n; i++)
			cin>>a[i].m;
		memset(dp,0,sizeof(dp));
		memset(x,0,sizeof(x));
		for(int i=1; i<=n; i++)
		{
			for(int j=0; j<=C; j++)
			{
				if(i!=1)
					dp[i][j] = dp[i-1][j];
				if(j>=a[i-1].w)
				dp[i][j] = dp[i-1][j] > (dp[i-1][j - a[i-1].w] + a[i-1].m) ? dp[i-1][j] : (dp[i-1][j - a[i-1].w] + a[i-1].m);		
				//cout<<dp[i][j]<<" ";
			}
			//cout<<endl;
		}
		cout<<dp[n][C]<<endl;
		for(int i=n; i>0; i--)
		{
			if(dp[i][C]>dp[i-1][C])
			{
				x[i-1]=1;
				C -= a[i-1].w;
			}
		}
		for(int j=0; j<n; j++)
		{
			cout<<x[j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
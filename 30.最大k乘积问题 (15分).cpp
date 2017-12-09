// 3.���k�˻����� (15��)
	// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
	// 	��Ŀ���ݣ�
	// 	��I��һ��nλʮ��������.�����I����Ϊk��,��ɵõ�k������.��k�������ĳ˻���ΪI��һ��k�˻�.�����һ���㷨,���ڸ�����I��k ,���I�����k�˻�.
	// 	Input
	// 	����ĵ�1������2��������n��k.������n�����еĳ���;������k�Ƿָ�Ķ���.��������һ������һ��nλʮ��������.��n<=10��
	// 	Output
	// 	�������������1���е����Ǽ���������k�˻�.
	// 	nλʮ��������.��n<=10��
	// 
	// 	��������
	// 	2 1
	// 	15
	// 
	// 	�������
	// 	15

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int dp[20][20];

int main()
{
	int n,k;
	int a[11],m[11][11];
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=1; i<=n; i++)
		{
			char h;
			cin>>h;
			a[i]=h-'0';
		}
		memset(m,0,sizeof(m));

		for(int i=1; i<=n; i++)
		{
			m[i][i] = a[i];
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				m[i][j] = m[i][j-1]*10 + m[j][j];
			}
		}

		for(int i=1; i<=n; i++)
		{
			dp[i][1] = m[1][i];
		}

		for(int i=1; i<=n; i++)
		{
			for(int j=0; j<i; j++)
			{
				for(int k=1; k<i; k++)
				{
					dp[i][j] = max(dp[i][j],dp[k][j-1]*m[k+1][i]);
				}
			}
		}
		cout<<dp[n][k]<<endl;
	}
	return 0;
}
// 4.��ѩ (10��)
// 	Cʱ�����ƣ�1 ���� |  C�ڴ����ƣ�3000 Kb
// 	��Ŀ���ݣ�
// 	Michaelϲ����ѩ�Ⲣ����֣� ��Ϊ��ѩ��ȷ�ܴ̼�������Ϊ�˻���ٶȣ������������������б�����ҵ��㻬���µף��㲻�ò��ٴ������»��ߵȴ������������㡣Michael��֪����һ����������׻��¡�������һ����ά��������������ÿ�����ִ����ĸ߶ȡ�������һ������ 
// 	1  2  3  4 5
// 	16 17 18 19 6
// 	15 24 25 20 7
// 	14 23 22 21 8
// 	13 12 11 10 9
// 	һ���˿��Դ�ĳ���㻬���������������ĸ���֮һ�����ҽ����߶ȼ�С��������������У�һ���ɻ��еĻ���Ϊ24-17-16-1����Ȼ25-24-23-...-3-2-1��������ʵ�ϣ��������һ����
// 	��������
// 	����ĵ�һ�б�ʾ���������R������C(1<=R,C<=100)��������R�У�ÿ����C������������߶�h��0<=h<=10000��
// 
// 	�������
// 	��������ĳ��ȡ�
// 
// 	��������
// 	5 5
// 	1 2 3 4 5
// 	16 17 18 19 6
// 	15 24 25 20 7
// 	14 23 22 21 8
// 	13 12 11 10 9
// 
// 	�������
// 	25

#include <cstdio>
#include <iostream>
#include <string>
#define Nmax 101
using namespace std;

int a[Nmax][Nmax];
int dp[Nmax][Nmax];
int N,M;

int inMap(int x,int y)
{  
	if(x>=0 && x<=N-1 && y>=0 && y<=M-1) 
		return 1;  
	return 0;  
}  

int max2(int a,int b,int c,int d)
{  
	return max(max(a,b),max(c,d));  
}  

int sking(int n, int i, int j)
{
	int l=0,r=0,u=0,d=0;

	if(dp[i][j]) 
		return dp[i][j];  
	if(inMap(i-1,j))
	{
		if(a[i-1][j]<n)
		{
			u=sking(a[i-1][j],i-1,j);
		}
	}
	if(inMap(i+1,j))
	{
		if(a[i+1][j]<n)
		{
			d=sking(a[i+1][j],i+1,j);
		}
	}
	if(inMap(i,j-1))
	{
		if(a[i][j-1]<n)
		{
			l=sking(a[i][j-1],i,j-1);
		}
	}
	if(inMap(i,j+1))
	{
		if(a[i][j+1]<n)
		{
			r=sking(a[i][j+1],i,j+1);
		}
	}

	dp[i][j]=max2(l,r,u,d)+1;
	return dp[i][j];
}

int main()
{
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		int i,j;
		for(i=0; i<N; i++)
			for(j=0; j<M; j++)
			{
				cin>>a[i][j];
			}
			int ans=-1;
			for(i=0; i<N; i++)
			{
				for(j=0; j<M; j++)
				{
					ans = max(ans,sking(a[i][j],i,j));
				}
			}
			cout<<ans<<endl;
	}
	return 0;
}


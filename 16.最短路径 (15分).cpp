// 5.���·�� (15��)
	// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
	// 	��Ŀ���ݣ�
	// 	��5������(A,B,C,D,E),����ÿ�����е��������е�ֱ�������֪����������֮��ֻ��һ����·������ӳ���A������������е����·�����롣
	// 	��������
	// 	4�����ݣ� ��һ����A��(B,C,D,E)��ֱ����룬�ڶ�����B����C,D,E����ֱ����룬����������4����D��E��ֱ����롣
	// 
	// 	�������
	// 	A���е�(B,C,D,E)����̾��롣
	// 
	// 	��������
	// 	2 3 4 5  
	// 	3 4 2 
	// 	4 3   
	// 	3
	// 
	// 	�������
	// 	2 3 4 4

#include <cstdio>
#include <iostream>
#include <string>
#define N 6
#define M 6
using namespace std;

int main()
{
	int biao[N][M];
	int inf = 99999999; //��inf(infinity����д)�洢һ��������Ϊ��������ֵ 
	int i,j,u;
	int k=2,min ;
	int first[M],signal[M]={0};
	memset(first,0,sizeof(first));
	memset(biao,0,sizeof(biao));
	for(i=1; i<N; i++)
	{
		for(j=1; j<M; j++)
		{
			if(i==j)
				biao[i][j]=0;
			if(i>j)
				biao[i][j]=inf;

		}
	}
	
	for(i=1; i<N-1; i++)
	{
		for(j=k; j<M; j++)
		{
			cin>>biao[i][j];
		}
		k++;
	}

	for(i=1; i<N; i++)
		first[i] = biao[1][i];
	signal[1]=1;
	for(i=1; i<N; i++)
	{
		min = inf;
		for(k=1; k<M; k++)
		{
			if(signal[k]==0 && first[k]<min)
			{
				min=first[k];
				u=k;
			}
		}
		signal[u]=1;

		for(j=2; j<M; j++)
		{
			if(biao[u][j]<inf)
			{
				if(first[j] > min+biao[u][j])
					first[j] = min+biao[u][j];
			}
			
		}
	}

	for(i=2; i<N; i++)
		cout<<biao[1][i]<<" ";
	cout<<endl;

	system("pause");
	return 0;
}
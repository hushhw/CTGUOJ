// 5.最短路径 (15分)
	// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	有5个城市(A,B,C,D,E),其中每个城市到其他城市的直达距离已知，两个城市之间只有一条公路。计算从城市A到其他任意城市的最短路径距离。
	// 	输入描述
	// 	4行数据， 第一行是A到(B,C,D,E)的直达距离，第二行是B到（C,D,E）的直达距离，。。。，第4行是D到E的直达距离。
	// 
	// 	输出描述
	// 	A城市到(B,C,D,E)的最短距离。
	// 
	// 	输入样例
	// 	2 3 4 5  
	// 	3 4 2 
	// 	4 3   
	// 	3
	// 
	// 	输出样例
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
	int inf = 99999999; //用inf(infinity的缩写)存储一个我们认为的正无穷值 
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
// 3.�������� (5��)
	// 	Cʱ�����ƣ�1 ���� |  C�ڴ����ƣ�3000 Kb
	// 	��Ŀ���ݣ�
	// 	һ������������ʱ��ת����������n*n�ľ���
	// 	��������
	// 	����Ĺ�ģ��0~50����5��ʾ5��5�еľ���
	// 
	// 	�������
	// 	����Ĺ�ģ��0~50����5��ʾ5��5�еľ���ÿ����ռ5λ
	// 
	// 	��������
	// 	5
	// 
	// 	�������
	// 	25    24   23   22    21
	// 	10     9    8    7    20
	// 	11     2    1    6    19
	// 	12     3    4    5    18
	// 	13    14   15   16    17
#include <cstdio>
#include <iostream>
#include <string>
#define N 51
using namespace std;

int main()
{
	int n;
	int a[N][N];
	while(scanf("%d",&n)!=EOF)
	{
		int i,j;
		int k=0;
		int sum = n*n;
		while(k <= n/2)
		{
			for(j=k; j<=n-k-1; j++)
				a[k][j] = sum--;
			for(i=k+1; i<=n-k-1; i++)
				a[i][n-k-1] = sum--;
			for(j=n-k-2; j>=k; j--)
				a[n-k-1][j] = sum--;
			for(i=n-k-2; i>=k+1; i--)
				a[i][k] = sum--;
			k++;
		}

		for(i = 0;i<n;i++)  
		{  
			for(j = 0;j<n;j++)  
				if(j==0)  
					printf("%d",a[i][j]);  
				else  
					printf("%5d",a[i][j]);  
			printf("\n");  
		}  
	}
	return 0;
}
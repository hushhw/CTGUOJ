// 15.���ų��� (15��)
// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
// 	��Ŀ���ݣ�
// 	��һ�ҳ��⳵��˾��ͨ������ԤԼ���ų��⡣���յ�M��ԤԼ����ϣ���ó�ʱ�������ǣ�s1,f1��,(s2,f2),...,(sM,fM).
// 	��������Ҫ׼��������������ɳ��⡣��ʾ�������黹����һ���ͻ��ſ���ʹ�á�
// 	��������
// 	��һ����M�����M����ԤԼ��ʱ������
// 
// 	�������
// 	������Ҫ�ĳ���̨��
// 
// 	��������
// 	4
// 	1,5
// 	2,7
// 	3,6
// 	8,10
// 
// 	�������
// 	3
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int sum[101]={0};

struct fangkuai
{
	int L,R;
	int num;
};

int main()
{
	int N;
	fangkuai a[101];
	int b[101];
	while(scanf("%d",&N)!=EOF)
	{
		int m=0;
		for(int i=0; i<N; i++)
		{
			cin>>a[i].L>>a[i].R;
			a[i].num=0;
		}
		int max=0;
		for(int i=0; i<N; i++)
		{
			max = sum[a[i].L];
			for(int j=a[i].L; j<=a[i].R; j++)
			{
				sum[j]++;
				if(sum[j]>max)
					max = sum[j];
			}
			for(int k=a[i].L; k<=a[i].R; k++)
			{
				sum[k]=max;
			}
			b[m++]=max;
		}
		int MAX=b[0];
		for(int i=0; i<m; i++)
		{
			if(b[i]>MAX)
				MAX=b[i];
		}
		cout<<MAX<<endl;

	}
	return 0;
}
// 3.������ (5��)
	// 	Cʱ�����ƣ�1 ���� |  C�ڴ����ƣ�3000 Kb
	// 	��Ŀ���ݣ�
	// 	����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿
	// 	��������
	// 	�������������գ��м��ÿո��������
	// 	2012 6 10
	// 
	// 	�������
	// 	2012-6-10������ĵ�162��
	// 
	// 	��������
	// 	2012 6 10
	// 
	// 	�������
	// 	162

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
	int y,m,d;
	while(scanf("%d%d%d",&y,&m,&d)!=EOF)
	{
		int sum=0;
		for(int i=1;i<m;i++)
			sum+=month[i];
		sum+=d;
		if(((y%4)==0 && (y%100)!=0)||(y%400==0))
			sum++;
		cout<<sum<<endl;
	}
	return 0;
}
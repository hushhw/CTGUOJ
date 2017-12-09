// 3.N�ʺ� (15��)
	// 	Cʱ�����ƣ�1 ���� |  C�ڴ����ƣ�3000 Kb
	// 	��Ŀ���ݣ�
	// 	���������еĻʺ��������ˮƽ�ߣ���ֱ�ߣ�����б��ǰ�����Ե��������������ӣ�����������а˸��ʺ�����˸��ʺ�����ల���µ�
	// 	�����������ϣ�1970����1971�꣬ E.W.Dijkstra��N.Wirth��������������������ʽ���֮���ɡ�
	//  ��N*N�ķ������̷�����N���ʺ�ʹ�����ǲ��໥������������2���ʺ�������ͬһ�ţ�ͬһ�У�Ҳ�������������̱߿��45�ǵ�б���ϡ�
	// 	����Ҫ��N�ʺ�ķ��ý�����ж�����
	// 	��������
	// 	����һ��������N��NС��16��
	// 
	// 	�������
	// 	������
	// 
	// 	��������
	// 	8
	// 
	// 	�������
	// 	92

#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

#define NUM 20
int n;
int x[NUM];
int sum;

bool Place(int t)
{
	int i;
	for(i=1; i<t; i++)
		if((abs(t-i)==abs(x[i]-x[t])) || (x[i]==x[t]))
			return false;
	return true;
}

void Backtrack(int t)
{
	int i;
	if(t>n)
		sum++;
	else
	{
		for(i=1; i<=n; i++)
		{
			x[t] = i;
			if(Place(t))
				Backtrack(t+1);
		}
	}
}


int main()
{
	
	while(scanf("%d",&n)!=EOF)
	{
		sum = 0;
		Backtrack(1);
		cout<<sum<<endl;
	}
	return 0;
}
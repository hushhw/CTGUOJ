/*
1.�������� (15��)
	Cʱ�����ƣ�2 ���� |  C�ڴ����ƣ�65535 Kb
	��Ŀ���ݣ�
	����һ��������n�Ļ��֣����ǰ�n���һϵ��������֮�͵ı��ʽ��ע�⣬�ֻ���˳���޹أ�����6=5+1��6=1+5��
	ͬһ�ַֻ������⣬���������������Ҳ��һ�ַֻ���
	���磺����������n=5�����Ի���Ϊ��
	1+1+1+1+1
	1+1+1+2
	1+1+3
	1+2+2
	2+3
	1+4
	5
	��������
	����һ��������n

	�������
	���n�������ֵ�����k

	��������
	5

	�������
	7
	*/

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int huafen(int n, int w)
{
	if(n==1 || w==1)
		return 1;
	else if(n<w)
		return huafen(n,n);
	else if(n==w)
		return huafen(n,n-1)+1;
	else if(n>w)
		return huafen(n,w-1) + huafen(n-w,w);
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		cout<<huafen(n,n)<<endl;
	}
	return 0;
}
// 6.Լɪ�� (5��)
// 	Cʱ�����ƣ�1 ���� |  C�ڴ����ƣ�3000 Kb
// 	��Ŀ���ݣ�
// 	��n����Χ��һȦ��˳���źš��ӵ�һ���˿�ʼ��������1��3��������������3��
// 
// 	���˳�Ȧ�ӣ���������µ���ԭ���ڼ��ŵ���λ?
// 	��������
// 	������n
// 
// 	�������
// 	ֱ��������
// 
// 	��������
// 	10
// 
// 	�������
// 	4


//http://blog.csdn.net/hushhw/article/details/78346290

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int Joseph(int n,int m)/*����Լɪ�򻷵ĵݹ麯��*/    
{    
	if(n<=1||m<=1)    
		return -1;    

	if(n==2)    
	{    
		if(m%2==0)    
			return 1;    
		else    
			return 2;    
	}    
	else    
	{    
		return (Joseph(n-1,m)+m-1)%n+1;    
	}    
}    


int main()    
{    
	int n;    
	while((scanf("%d",&n))!=EOF)
	{  
		printf("%d\n",Joseph(n,3));
	}
	    
	return 0;    
}    
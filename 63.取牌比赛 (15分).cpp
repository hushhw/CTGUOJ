// 16.ȡ�Ʊ��� (15��)
	// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
	// 	��Ŀ���ݣ�
	// 	������������ȡ����Ϸ��һ����M���ƣ�ÿ�ο���ȡ1,2,����5�ţ�ȡ�����һ���Ƶ���Ϊʤ��������ж���ȡ�Ƶ��Ƿ���ʤ����
	// 	��������
	// 	����M
	// 
	// 	�������
	// 	Y����N
	// 
	// 	��������
	// 	2
	// 
	// 	�������
	// 	Y
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int fun(int a){  
	int s[1000]={0};  
	s[0]=0;  
	s[1]=1;  
	s[2]=1;  
	s[3]=0;  
	s[4]=1;  
	s[5]=1;  
	for(int i=6;i<200;i++){  
		if(s[i-1]==0||s[i-2]==0||s[i-5]==0)  
			s[i]=1;  
		else  
			s[i]=0;  
	}
	return s[a];
}  

int main()
{
	int M;
	while(scanf("%d",&M)!=EOF)
	{
		if(fun(M))
			cout<<"Y"<<endl;
		else
			cout<<"N"<<endl;
	}
	return 0;
}
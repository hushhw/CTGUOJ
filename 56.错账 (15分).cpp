// 9.���� (15��)
	// 	Cʱ�����ƣ�3 ���� |  C�ڴ����ƣ�3000 Kb
	// 	��Ŀ���ݣ�
	// 	ĳ�����Ž���ʱ�����ܽ���ͷ���ܿ����Ǵ���ϸ��©����ĳ1�ʻ򼸱ʡ������֪��ϸ��Ŀ�嵥����ͨ������ҵ�©��������1�ʻ򼸱���
	// 	����ж��ֿ��ܣ���������п��ܵ������
	// 	��������
	// 	��һ�����д���ܽ���������һ������n����ʾ���潫Ҫ�������ϸ��Ŀ��������
	// 	�ٽ�������n���������ֱ��ʾÿ����Ŀ�Ľ�Ϊ�˷��㣬����������еĽ���������ÿ�ʽ�����1000��������ϸ����������100��
	// 
	// 	�������
	// 	���п���©���Ľ����ϡ�ÿ�����1�С����֮�䣬���������������еĴ��������ϵ��Ⱥ������������ͬһ��������һ�����ݵ�λ�á�ÿ�����ڲ��ļ������ݰ���ֵ��С�������У��м��ÿո�ֿ���
	// 
	// 	��������
	// 	6
	// 	5
	// 	3
	// 	2
	// 	4
	// 	3
	// 	1
	// 
	// 	�������
	// 	3 4
	// 	1 3 3
	// 	1 2 4

#include<iostream>  
#include<stdio.h>  
#include<memory.h>  
#include<algorithm>  
using namespace std;  
int num[100],result[100][100],temp[100];  
bool used[100];  
int p,s;  


void init()  
{  
	p=0,s=0;  
	memset(used,false,sizeof(used));  
	for(int i=0;i<100;i++)  
	{  
		num[i]=10000;  
		for(int j=0;j<100;j++)  
			result[i][j]=10000;  
	}  

}  

void showResult()  
{  
	int i,j;  
	for(i=0;i<p;i++)  
	{  
		for(j=0;result[i][j]!=10000;j++)  
			cout<<result[i][j]<<' ';  
		cout<<endl;  
	}  
}  

bool cmp(int len)  
{  
	int i,j;  
	for(i=0;i<p;i++)  
	{  
		for(j=0;j<len;j++)  
		{  
			if(result[i][j]!=temp[j])  
				break;  
		}  
		if(j==len)  
			return false;//�����˳�˵������һģһ����      
	}  
	return true;  
}  


void save(int n)  
{  
	int i,j,len;  
	s=0;  
	for(i=0;i<n;i++)  
	{  
		if(used[i]==false)  
		{  
			temp[s]=num[i];  
			s++;  
		}  

	}  
	len=s;  
	s=0;  
	if(cmp(len))  
	{  
		for(i=0;i<len;i++)  
			result[p][i]=temp[i];  
		p++;  
	}  

}  

void search(int sum,int n,int w_sum)  
{  
	if(sum>w_sum)  
		return;  
	if(sum==w_sum)  
	{  
		save(n);  
		return;  
	}  
	for(int i=0;i<n;i++)  
	{  
		if(used[i]==false)  
		{  
			used[i]=true;  
			search(sum+num[i],n,w_sum);  
			used[i]=false;  
		}  
	}  
}  

int main()  
{  
	init();  
	int w_sum,n,i;  
	cin>>w_sum>>n;  
	for(i=0;i<n;i++)  
	{  
		cin>>num[i];  
	}  
	sort(num,num+100);  
	search(0,n,w_sum);  
	showResult(); 
	system("pause");
	return 0;  
}  

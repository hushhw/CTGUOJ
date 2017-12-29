// 9.错账 (15分)
	// 	C时间限制：3 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	某财务部门结账时发现总金额不对头。很可能是从明细上漏掉了某1笔或几笔。如果已知明细账目清单，能通过编程找到漏掉的是哪1笔或几笔吗？
	// 	如果有多种可能，则输出所有可能的情况。
	// 	输入描述
	// 	第一行是有错的总金额，接下来是一个整数n，表示下面将要输入的明细账目的条数。
	// 	再接下来是n行整数，分别表示每笔账目的金额。为了方便，这里假设所有的金额都是整数；每笔金额不超过1000，金额的明细条数不超过100。
	// 
	// 	输出描述
	// 	所有可能漏掉的金额组合。每个组合1行。组合之间，按首数据在输入中的次序决定组合的先后，如果首数据是同一个，则看下一个数据的位置。每组金额内部的几个数据按照值从小到大排列，中间用空格分开。
	// 
	// 	输入样例
	// 	6
	// 	5
	// 	3
	// 	2
	// 	4
	// 	3
	// 	1
	// 
	// 	输出样例
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
			return false;//正常退出说明存在一模一样的      
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

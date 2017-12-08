// 合并排序 (10分)
	// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	使用合并排序算法，对输入的n个数据进行按升序排序。
	// 	输入描述
	// 	分两行，第一行是整数n,第二行是n个整数，每个整数之间用空格间隔。
	// 
	// 	输出描述
	// 	按升序排序的n个整数
	// 
	// 	输入样例
	// 	8
	// 	9 8 7 6 5 4 3 2
	// 
	// 	输出样例
	// 	2 3 4 5 6 7 8 9

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#define Nmax 101
using namespace std;
int a[Nmax];

void merge(int left,int mid, int right)
{
	int ll, rl, i;  
	ll=mid-left+1;
	rl=right-mid;
	int L[Nmax], R[Nmax]; 
	for(i=0; i<ll; i++)  
		L[i]=a[left+i];  
	for(i=0; i<rl; i++)  
		R[i]=a[mid+i+1];  
	L[ll]=32767;  
	R[rl]=32767;  
	ll=0;  
	rl=0;  
	for(i=0; i<right-left+1; i++)  
	{  
		if(L[ll]<R[rl])  
		{  
			a[left+i]=L[ll];  
			ll++;  
		}  
		else  
		{  
			a[left+i]=R[rl];  
			rl++;   
		}  
	} 
}

void mergesort(int l, int r)
{
	if(l<r)
	{
		int mid = (l+r)/2;
		mergesort(l,mid);
		mergesort(mid+1,r);
		merge(l, mid, r);
	}
}


int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i;
		for(i=0; i<n; i++)
			cin>>a[i];
		mergesort(0,n-1);
		for(i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}
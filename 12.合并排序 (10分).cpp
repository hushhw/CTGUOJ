// �ϲ����� (10��)
	// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
	// 	��Ŀ���ݣ�
	// 	ʹ�úϲ������㷨���������n�����ݽ��а���������
	// 	��������
	// 	�����У���һ��������n,�ڶ�����n��������ÿ������֮���ÿո�����
	// 
	// 	�������
	// 	�����������n������
	// 
	// 	��������
	// 	8
	// 	9 8 7 6 5 4 3 2
	// 
	// 	�������
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
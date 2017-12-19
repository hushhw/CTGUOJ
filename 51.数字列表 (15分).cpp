// 7.�����б� (15��)
	// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
	// 	��Ŀ���ݣ�
	// 	��������M�����ֵ��б����б����������ֵ����������������������б�ʹ�����б����������ֵĳ˻���һ����ȫƽ����.
	// 
	// 	��������
	// 	�����ļ���������������ݡ���һ�а�����������N , M ( 1 <= N <= 30 , 1 <= M <= 30000 ). N 
	// 
	// 	���������ĸ�����������һ����N���������������е���������Ȼ��һ�а���M�������������б�
	// 
	// 	�������
	// 	����ÿ�����ݣ��������б������λ������l r��l�Ǹ����б����б��е���ʼλ�ã�r�ǽ���λ��
	// 
	// 	���������������������б���������l��С��һ����������������������б������None����
	// 
	// 	��������
	// 	3 4
	// 	2 3 5
	// 	4 9 25 6
	// 	3 4
	// 	2 3 5
	// 	6 6 3 3
	// 	0 0
	// 
	// 	�������
	// 	1 3
	// 	1 4


#include <iostream>  
#include <cstdio>
#include <string>
using namespace std;  

struct node{  
	int flag[10];  
	int pos;  
}tree[100000];  

int cnt;  

void insert(char *ch,int pos)  
{  
	int len = strlen(ch);  
	int i,p,num;  
	p = 1;  
	for(i=0;i<len;i++)  
	{  
		num = ch[i] - '0';  
		if(tree[p].flag[num]==0)  
		{  
			cnt++;  
			tree[p].flag[num] = cnt;  
		}  
		p = tree[p].flag[num];  
	}  
	tree[p].pos = pos;  
}  

int find(char *ch)  
{  
	int len = strlen(ch);  
	int i,p,num;  
	p = 1;  
	for(i=0;i<len;i++)  
	{  
		num = ch[i] - '0';  
		if(tree[p].flag[num]==0)  
			return -1;  
		p = tree[p].flag[num];  
	}  
	return tree[p].pos;  
}  

int main()  
{  
	int n[40];  
	int N,M;  
	int l,r,max,i,j,pos;  
	int num,k,s;  
	char ch[100];  
	while(scanf("%d%d",&N,&M)&&(N||M))  
	{  
		cnt = 1;  
		memset(tree,0,sizeof(tree));  
		memset(n,0,sizeof(n));  
		l = r = max = s =0;  
		for(i=0;i<N;i++)  
			scanf("%d",&n[i]);  
		for(i=1;i<=M;i++)  
		{  
			scanf("%d",&num);  
			k = 0;  
			for(j=0;j<N;j++)  
			{  
				if(num==1)  
					break;  
				if(n[j]==1)  
					continue;  
				while(num%n[j]==0)  
				{  
					k=k^(1<<j);  
					num/=n[j];  
					s=s^(1<<j);  
					if(num==1)  
						break;  
				}  
				if(num==1)  
					break;  
			}  
			if(k==0)  
			{  
				if(max==0)  
				{  
					l = r = i;  
					max = 1;  
				}  
			}  
			if(s!=0)  
			{  
				sprintf(ch,"%d",s);  
				pos = find(ch);  
				if(pos>0)  
				{  
					if(i-pos>max)  
					{  
						max = i - pos;  
						l = pos + 1;  
						r = i;  
					}  
				}  
				else  
					insert(ch,i);  
			}  
			else  
			{  
				l = 1;  
				r = i;  
				max = i;  
			}  
		}  
		if(max==0)  
			printf("None\n");  
		else  
			printf("%d %d\n",l,r);  
	}  
	return 0;  
}  

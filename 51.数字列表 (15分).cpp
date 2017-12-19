// 7.数字列表 (15分)
	// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	给出包含M个数字的列表，和列表中所有数字的所有质因数。求出最长的子列表，使得子列表中所有数字的乘积是一个完全平方数.
	// 
	// 	输入描述
	// 	输入文件包含多组测试数据。第一行包含两个整数N , M ( 1 <= N <= 30 , 1 <= M <= 30000 ). N 
	// 
	// 	是质因数的个数。接下来一行有N个整数，给出所有的质因数。然后一行包含M个整数，给出列表。
	// 
	// 	输出描述
	// 	对于每组数据，输出最长子列表的两个位置坐标l r。l是该子列表在列表中的起始位置，r是结束位置
	// 
	// 	。如果多种情况都满足子列表长度最大，输出l最小的一个。如果不存在这样的子列表输出“None”。
	// 
	// 	输入样例
	// 	3 4
	// 	2 3 5
	// 	4 9 25 6
	// 	3 4
	// 	2 3 5
	// 	6 6 3 3
	// 	0 0
	// 
	// 	输出样例
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

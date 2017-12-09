// 4.二十四点 (15分)
	// 	C时间限制：1 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	问题描述：输入4个数，通过 加、减、乘、除运算看能否得到 结果 24，每个数只用一次。
	// 	输入描述
	// 	输入四个正整数
	// 
	// 	输出描述
	// 	能通过某种方式得到24则输出1，不能则输出0
	// 
	// 	输入样例
	// 	6 6 6 6
	// 
	// 	输出样例
	// 	1

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int w[4] = {0,1,2,3};

int main()
{
	int a[4];
	int i,j,k;
	scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
	sort(a,a+4);
	do{
		for(i=0; i<4; i++)
		{
			for(j=0; j<4; j++)
			{
				for(k=0; k<4; k++)
				{
					int sum=0; 
					switch(w[i])
					{
					case 0:sum = a[0] + a[1];break;
					case 1:sum = a[0] - a[1];break;
					case 2:sum = a[0] * a[1];break;    
					case 3:sum = a[0] / a[1];break;    
					default:break;    
					}
					switch (w[j])
					{
					case 0:sum = sum + a[2];break;    
					case 1:sum = sum - a[2];break;    
					case 2:sum = sum * a[2];break;    
					case 3:sum = sum / a[2];break; 
					default:
						break;
					}
					switch (w[k])
					{
					case 0:sum = sum + a[3];break;    
					case 1:sum = sum - a[3];break;    
					case 2:sum = sum * a[3];break;    
					case 3:sum = sum / a[3];break;
					default:
						break;
					}
					if(sum==24)
					{
						cout<<"1"<<endl;
						//system("pause");
						return 0;
					}
				}
			}
		}
	}while(next_permutation(a,a+4));
	cout<<"0"<<endl;
	//system("pause");
	return 0;
}
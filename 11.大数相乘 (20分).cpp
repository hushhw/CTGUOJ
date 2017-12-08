// 
	// 3.大数相乘 (20分)
	// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	一个整型变量只能用来存贮较小的n!的值，当 n 较大时，可将阶乘值中的每一个数字放在一个一维数组的一个元素中。使用这方法，打印n!的值；
	// 
	// 	输入描述
	// 	整数n
	// 
	// 	输出描述
	// 	n!的值
	// 
	// 	输入样例
	// 	18
	// 
	// 	输出样例
	// 	6402373705728000

#include <cstdio>
#include <iostream>
#include <string>
#define M 100 
using namespace std;

int main() 
{  
	//代码模拟两个数相乘的进位等操作并储存每一位数字
	int n,i,k,a[M],w=0,j,t;  
	scanf("%d",&n);  
	a[0]=1;  
	for(i=1;i<100;i++)   
		a[i]=0;  
	for(i=1;i<=n;i++)  
	{   
		for(j=0;j<=w;j++)   
		{    
			if(j==0)    
			{     
				t=a[j]*i;			
				a[j]=t%10;			//用a[j]来保存每一次相乘后的个位数
				t=t/10;				//t保存相乘后的十位数字
				if(j==w&&t>0)		//用w来控制是否有进位，如果t大于零则说明进位了，则w++
					w++;   
			}    
			else   
			{     
				t=a[j]*i+t;			//因为是有进位，所以要加上t
				a[j]=t%10; 
				t=t/10;    
				if(j==w&&t>0)		//判断是否继续进位
					w++;   
			}  
		}  
	}  
	for(i=w;i>=0;i--)  
		printf("%d",a[i]); 
	printf("\n");
	return 0;
}
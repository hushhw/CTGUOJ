// 6.约瑟夫环 (5分)
// 	C时间限制：1 毫秒 |  C内存限制：3000 Kb
// 	题目内容：
// 	有n个人围成一圈，顺序排号。从第一个人开始报数（从1到3报数），凡报到3的
// 
// 	人退出圈子，问最后留下的是原来第几号的那位?
// 	输入描述
// 	正整数n
// 
// 	输出描述
// 	直接输出结果
// 
// 	输入样例
// 	10
// 
// 	输出样例
// 	4


//http://blog.csdn.net/hushhw/article/details/78346290

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int Joseph(int n,int m)/*计算约瑟夫环的递归函数*/    
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
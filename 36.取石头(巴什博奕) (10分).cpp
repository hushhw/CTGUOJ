// 3.取石头 (10分)
	// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	"有甲乙两个人玩取石子游戏,共有n个石子(1<=n<=30000)两个人轮流取,甲先取.每次最多取m个(1<=m<=30000)最少取一个,当轮到谁取的时候没有石子了,谁就赢.
	// 	比如4个石子,每次最多取3个,那么先取的人(甲)一定赢n和m谁大没有限制.)
	// 	(甲拿走3个,乙只拿走1个,下面轮到甲了,但是没有石子了,甲赢了．）
	// 	现在要求你写一个程序，输入n(总的石子个数），最多可以取的石子个数m，输出甲（先取的人）是否会赢，会赢的话输出YES,否则输出LOSE.
	// 	我们这里假设甲乙两个人都采取最好的策略，也就是甲乙都非常想赢而且足够聪明．
	// 	比如输入11 4　输出LOSE"
	// 	输入描述
	// 	整数n m, 空格隔开
	// 
	// 	输出描述
	// 	YES或者LOSE
	// 
	// 	输入样例
	// 	11 4
	// 
	// 	输出样例
	// 	LOSE

#include<iostream>  
#include<string>  
#include<cstring>  
#include<cstdio>  
#include<algorithm>  
using namespace std;  

int main()  
{  
	int num, limit;   
	while((scanf("%d%d", &num, &limit))!=EOF)  
	{  
		;  
		if(num % (limit + 1) != 0)
			printf("LOSE\n");  
		else  
			printf("YES\n");  
	}  
	return 0;  
}       
// 16.取牌比赛 (15分)
	// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	两个人玩轮流取牌游戏，一共有M张牌，每次可以取1,2,或者5张，取到最后一张牌的人为胜利。编程判断先取牌的是否能胜利。
	// 	输入描述
	// 	牌数M
	// 
	// 	输出描述
	// 	Y或者N
	// 
	// 	输入样例
	// 	2
	// 
	// 	输出样例
	// 	Y
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int fun(int a){  
	int s[1000]={0};  
	s[0]=0;  
	s[1]=1;  
	s[2]=1;  
	s[3]=0;  
	s[4]=1;  
	s[5]=1;  
	for(int i=6;i<200;i++){  
		if(s[i-1]==0||s[i-2]==0||s[i-5]==0)  
			s[i]=1;  
		else  
			s[i]=0;  
	}
	return s[a];
}  

int main()
{
	int M;
	while(scanf("%d",&M)!=EOF)
	{
		if(fun(M))
			cout<<"Y"<<endl;
		else
			cout<<"N"<<endl;
	}
	return 0;
}
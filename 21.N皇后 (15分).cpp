// 3.N皇后 (15分)
	// 	C时间限制：1 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	国际象棋中的皇后可以沿着水平线，垂直线，或者斜线前进，吃掉遇到的所有棋子，如果棋盘上有八个皇后，则这八个皇后如何相安无事的
	// 	放置在棋盘上，1970年与1971年， E.W.Dijkstra与N.Wirth曾经用这个问题来讲解程式设计之技巧。
	//  在N*N的方格棋盘放置了N个皇后，使得它们不相互攻击（即任意2个皇后不允许处在同一排，同一列，也不允许处在与棋盘边框成45角的斜线上。
	// 	该题要求N皇后的放置结果共有多少种
	// 	输入描述
	// 	输入一个正整数N（N小于16）
	// 
	// 	输出描述
	// 	输出结果
	// 
	// 	输入样例
	// 	8
	// 
	// 	输出样例
	// 	92

#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

#define NUM 20
int n;
int x[NUM];
int sum;

bool Place(int t)
{
	int i;
	for(i=1; i<t; i++)
		if((abs(t-i)==abs(x[i]-x[t])) || (x[i]==x[t]))
			return false;
	return true;
}

void Backtrack(int t)
{
	int i;
	if(t>n)
		sum++;
	else
	{
		for(i=1; i<=n; i++)
		{
			x[t] = i;
			if(Place(t))
				Backtrack(t+1);
		}
	}
}


int main()
{
	
	while(scanf("%d",&n)!=EOF)
	{
		sum = 0;
		Backtrack(1);
		cout<<sum<<endl;
	}
	return 0;
}
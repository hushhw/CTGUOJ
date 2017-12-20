// 6.Eight (15分)
	// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	在3*3的棋盘上,摆有八个棋子,每个棋子上标有1至8的某一数字.棋盘中留有一个空格,空格用0来表示.空格周围的棋子可以移到空格中.要求解的问题是：给出一种初始布局和目标布局,为了使题目简单,设目标状态为:
	// 1 2 3
	// 	8 0 4
	// 	7 6 5
	// 	找到一种最少步骤的移动方法,实现从初始布局到目标布局的转变.
	// 	输入描述
	// 	输入初试状态,3*3的九个数字,空格用0表示.
	// 
	// 	输出描述
	// 	只有一行,该行只有一个数字,表示从初始状态到目标状态需要的最少移动次
	// 	(若无法到达目标状态则输出-1).
	// 
	// 	输入样例
	// 	2 8 3
	// 	1 0 4
	// 	7 6 5
	// 
	// 	输出样例
	// 	4
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int count=1;

struct node 
{
	int xy[3][3];
	int dir;
};
struct node sh[102];


void init()
{
	printf("输入起始节点的位置:\n");
	int i,j;
	for(i=0; i<3; i++)
		for(j=0; j<3; j++)
			scanf("%d", &sh[0].xy[i][j]);
	sh[0].dir = -1;
	printf("输入目标节点位置:\n");
	for(i=0; i<3; i++)
		for(j=0; j<3; j++)
			scanf("%d", &sh[101].xy[i][j]);
	sh[101].dir = -1;
}

//找出0的位置
int loction(int num)
{
	int i;
	for (i = 0; i < 9; i++)
		if (sh[num].xy[i / 3][i % 3] == 0) return i;
}

//进行标记
long long sign(int num)
{
	long long  sum;
	sum = sh[num].xy[0][0]*100000000 + sh[num].xy[0][1]*10000000 + sh[num].xy[0][2]*1000000 + sh[num].xy[1][0]*100000 + sh[num].xy[1][1]*10000 + sh[num].xy[1][2]*1000 + sh[num].xy[2][0]*100 + sh[num].xy[2][1]*10 + sh[num].xy[2][2];
	return sum;
}

void mobile(int num)
{
	int temp;
	int loc;
	int up=1,down=1,left=1,right=1;
	loc = loction(num);
	int stand = sh[num].dir;
	//dir的0 1 2 3分别代表左 上 右 下
	if (loc / 3 != 0 && stand != 1)
	{
		sh[count] = sh[num];
		temp = sh[count].xy[loc / 3][loc % 3];
		sh[count].xy[loc / 3][loc % 3] = sh[count].xy[loc / 3 - 1][loc % 3];
		sh[count].xy[loc / 3 - 1][loc % 3] = temp;
		sh[count].dir = 3;
		count++;
	};
	if (loc / 3 != 2 && stand != 3)
	{
		sh[count] = sh[num];
		temp = sh[count].xy[loc / 3][loc % 3];
		sh[count].xy[loc / 3][loc % 3] = sh[count].xy[loc / 3 + 1][loc % 3];
		sh[count].xy[loc / 3 + 1][loc % 3] = temp;
		sh[count].dir = 1;
		count++;
	}
	if (loc % 3 != 0 && stand != 0)
	{
		sh[count] = sh[num];
		temp = sh[count].xy[loc / 3][loc % 3];
		sh[count].xy[loc / 3][loc % 3] = sh[count].xy[loc / 3][loc % 3 - 1];
		sh[count].xy[loc / 3][loc % 3 - 1] = temp;
		sh[count].dir = 2;
		count++;
	}
	if (loc % 3 != 2 && stand != 2)
	{
		sh[count] = sh[num];
		temp = sh[count].xy[loc / 3][loc % 3];
		sh[count].xy[loc / 3][loc % 3] = sh[count].xy[loc / 3][loc % 3 + 1];
		sh[count].xy[loc / 3][loc % 3 + 1] = temp;
		sh[count].dir = 0;
		count++;
	}
}

void display(int num)
{
	int i,j;
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
			printf("%d", sh[num].xy[i][j]);
		printf("\n");
	}
}

int search()
{
	int i=0;
	while(1)
	{
		printf("\n");
		display(i);
		printf("\n");
		if(i==100)
		{
			printf("超出上限次数\n");
			return 0;
		}
		if(sign(i) == sign(101))
		{
			printf("在第%d次找到了", i);
			display(i);
			return i;
		}
		mobile(i);
		i++;
	}
}

int main()
{
	init();
	search();
	return 0;
}
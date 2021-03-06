// 8.甲乙混战 (15分)
	// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	某游戏规则中，甲乙双方每个回合的战斗总是有一方胜利，一方失败。
	// 	游戏规定：失败的一方要把自己的体力值的1/4加给胜利的一方。例如：
	// 	如果双方体力值当前都是4，则经过一轮战斗后，双方的体力值会变为：5，3。
	// 	现在已知：双方开始时的体力值甲：1000，乙：2000。
	// 	假设战斗中，甲乙获胜的概率都是50%求解：双方经过4个回合的战斗，
	// 	体力值之差小于1000的理论概率。
	// 	输入描述
	// 	此题直接编译出结果就可，不需要输入数据
	// 
	// 	输出描述
	// 	输出4个回合的战斗后体力值之差小于1000的理论概率，保留6位小数
	// 
	// 	输入样例
	// 	此题直接编译出结果就可，不需要输入数据
	// 
	// 	输出样例
	// 	0.000000
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int x=1000;
	int y=2000;
	float count=0;
	float f=0;
	for (int i=0; i<16; i++)
	{
		for (int k=0; k<4;k++)
		{
			int t=(i>>k&1);
			if ( t==0)
			{
				x+=y/4;
				y-=y/4;
			}
			else
			{
				y+=x/4;
				x-=x/4;
			}
		}
		if (abs(x-y)<1000)
		{
			count++;
		}
		x=1000;
		y=2000;
	}
	f=count/16;
	printf("%f\n",f);
	system("pause");
	return 0;
}
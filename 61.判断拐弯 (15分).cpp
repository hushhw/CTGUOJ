// 14.判断拐弯 (15分)
	// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	小张用手机传来他开车先后经过的三个地点A, B, C的坐标,请你编程判断小张在B点是左拐弯，还是右拐弯
	// 	输入描述
	// 	A, B, C的坐标
	// 
	// 	输出描述
	// 	left  或者 right
	// 
	// 	输入样例
	// 	0,0
	// 	1,1
	// 	2,1
	// 
	// 	输出样例
	// 	right

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
	int a1,a2,b1,b2,c1,c2;
	while(~scanf("%d,%d%d,%d%d,%d",&a1,&a2,&b1,&b2,&c1,&c2)){
		double k1 = abs(b2-a2)/abs(b1-a1);
		double k2 = abs(c2-b2)/abs(c1-b1);
		if(k2>k1)
			cout<<"left"<<endl;
		else if(k2<k1)
			cout<<"right"<<endl;
	}
	return 0;
}
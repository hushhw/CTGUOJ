// 4.线数目 (15分)
	// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	现有画有黑线（直线或曲线）的白底图片一张，计算出有多少条黑线、并依次输出每条黑线所占的点数。图片我们用0、1图表示，1代表黑点 0 代表白点，某点周围8个方向都算连通，如下图所示，共有3条黑线，长度分别是5、3、5：
	// 	1 0 0 0 0 0 0
	// 	0 1 1 1 1 0 0
	// 	0 0 0 0 0 0 0
	// 	1 1 0 0 0 1 1
	// 	1 0 0 1 1 1 0
	// 	输入描述
	// 	图的宽w、高h，换行输入图的像素点.(测试数据结果唯一确定)
	// 
	// 	输出描述
	// 	黑线条数、换行输出每条线长度.（条数及每个长度各占一行）.
	// 
	// 	输入样例
	// 	7 5 
	// 	1 0 0 0 0 0 0
	// 	0 1 1 1 1 0 0
	// 	0 0 0 0 0 0 0
	// 	1 1 0 0 0 1 1
	// 	1 0 0 1 1 1 0
	// 
	// 	输出样例
	// 	3
	// 	5
	// 	3
	// 	5

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int map[100][100];
int value[20];
int w,h;
int find(int i,int j){
	if(map[i][j]==1){
		map[i][j]=0;
		return find(i-1,j-1)+find(i-1,j)+
			find(i-1,j+1)+find(i,j-1)+
			find(i,j+1)+find(i+1,j-1)+
			find(i+1,j)+find(i+1,j+1)+1;
	}else{
		return 0;
	}
}

int main(){
	int count=0;
	memset(map,0,sizeof(map));//全部赋值为零
	memset(value,0,sizeof(value));
	cin>>w>>h;
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			cin>>map[i][j];
	int k=0;
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
		{

			int sum=find(i,j);
			if(sum!=0){
				count++;
				value[k++]=sum;
			}
		}

		cout<<count<<endl;
		for(int i=0;i<count;i++)
			cout<<value[i]<<endl;        
		return 0;
}
// 5.同色三角形 (15分)
	// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	平面上有n个点（n≤8000），每两个点之间都有一条红色或者是黑色的线段，任意三点均不共线。
	// 	现在，已知哪些点之间连的线段是红色的，剩下的线段都是黑色的，要求计算这些点组成的三角
	// 	形中有多少是同色的（顶点编号从1到n）？
	// 	输入描述
	// 	第一行是n, m（3≤n≤8000），n表示点的个数，m表示红色线段的条数。下面m行，每
	// 	一行都是两个整数a和b，表示点a和点b之间的线段是红色的（a<b）。
	// 
	// 	输出描述
	// 	只有一行，表示同色三角形的个数。
	// 	提示：本题输出数据可能会超出长整数（long int）的范围。
	// 
	// 	输入样例
	// 	6 5
	// 	1 2
	// 	1 3
	// 	2 3
	// 	2 5
	// 	3 6
	// 
	// 	输出样例
	// 	7
#include <iostream>  
#include <cstdio> 
#include <string>
using namespace std;  

#define N 8001  
int colorline[N][N]={0}; //将所有的线设为黑色  

int main()  
{   
	int n,m; //点的数目和红色的条数   
	int x,y; //点的坐标  
	int tri=0; //计数器,同色三角形的个数   
	cin>>n>>m;  
	for(int i=1;i<=m;i++)  
	{   
		//输入红线连接的两个点坐标   
		cin>>x>>y;  
		colorline[x][y]=colorline[y][x]=1; // 1 表示红色线   
	}   
	for(int i=1;i<=n;i++)   
		for(int j=i+1;j<=n;j++)   
			for(int k=j+1;k<=n;k++)   
				if(colorline[i][j]==colorline[i][k]&&colorline[i][j]==colorline[j][k])  
				{
					tri++;   
				}
	cout<<tri<<endl;  
	system("pause");
	return 0;  
}  
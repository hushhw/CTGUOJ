// 7.圣诞广场 (15分)
	// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	Angel最近无聊，去了圣诞岛(CX *^_^*)，他喜欢无目的的乱逛，当然，他不会轻易地回头。Angel想
	// 
	// 	去广场，那么，他什么时候才能到呢？你已经得到了CX的地图，地图上有N(N <= 100)个交叉路口，交
	// 
	// 	叉路口之间有马路相连接(不超过1000条马路)。因为CX的人遵循奇怪的规则，道路都是单向的，不同
	// 
	// 	的道路之间有一定的距离，我们假设Angel所在的地点为点1，广场所在点为N。假设Angel走一单位距
	// 
	// 	离需要一单位时间。问Angel最早和最迟什么时候到达广场？ 
	// 	输入描述
	// 	本题有多组数据，第一行N, M，M是边的数量,以后M行，每行3个整数X, Y, Weight，代表一条从X
	// 
	// 	城市到Y城市，长度为Weight的边。
	// 
	// 	输出描述
	// 	每组数据，第一行是最少时间，第二行是最迟时间，要是可怜的Angel可能永远到不了广场，输
	// 
	// 	出一行Never。
	// 
	// 	输入样例
	// 	5 5
	// 	1 2 1
	// 	1 4 10
	// 	2 3 1
	// 	3 4 1
	// 	4 5 1
	// 
	// 	输出样例
	// 	4
	// 	11
#include <iostream>
#include <cstring>
#define INFINITE  10000000
using namespace std;
int n, m;         //n个点，m条路
int a[100][100];  //权值矩阵 
int dist[100];    //距离 
int pre[100];

int  pathDijkstra(int n, int s){  //s为源点 
	int i, j, k, count;
	int boolInA[100];
	int minpnt, mindis;
	for(int i = 1; i <= n; i++){
		dist[i] = a[s][i];
		pre[i] = s;
		boolInA[i] = 0;
	} 
	boolInA[s] = 1;
	for(count = 1; count <= n; count++){
		mindis = INFINITE;
		for(i = 1; i <= n; i++){
			if(!boolInA[i] && mindis > dist[i]){
				mindis = dist[i];
				minpnt = i;
			}
		}
		boolInA[minpnt] = 1;
		for(int i = 1; i <= n; i++)
			if(!boolInA[i] && dist[i] > dist[minpnt] + a[minpnt][i]){
				dist[i] = dist[minpnt] + a[minpnt][i];
				pre[i] = minpnt;
			}
	}
	cout << dist[5] << endl;
	return 1;
}
int  fpathDijkstra(int n, int s){  //s为源点  水过的 *^_^* 
	int i, j, k, count;
	int boolInA[100];
	int minpnt, mindis;
	for(int i = 1; i <= n; i++){
		dist[i] = a[s][i];
		pre[i] = s;
		boolInA[i] = 0;
	} 
	boolInA[s] = 1;
	for(count = 1; count <= n; count++){
		mindis = -1;
		for(i = 1; i <= n; i++){
			if(!boolInA[i] && mindis <= dist[i]){    //加了个= 
				mindis = dist[i];
				minpnt = i;
			}
		}
		boolInA[minpnt] = 1;
		for(int i = 1; i <= n; i++)
			if(!boolInA[i] && dist[i] < dist[minpnt] + a[minpnt][i]){
				dist[i] = dist[minpnt] + a[minpnt][i];
				pre[i] = minpnt;
			}
	}
	cout << dist[5] << endl;
	return 1;
} 

int main(){
	cin >> n >> m;
	int x, y, v;
	//  int j;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			a[i][j] = INFINITE;
			if(i == j)
				a[i][i] = 0;        
		}
	} 
	for(int i = 1; i <= m; i++){
		cin >> x >> y >> v;
		a[x][y] = v;
	}
	pathDijkstra(n, 1);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] == INFINITE)
				a[i][j] = -1;       
		}
	}
	fpathDijkstra(n, 1);
	//  for(int i = 1; i <= n; i++)
	//      cout << dist[i] << " ";

	return 0;
}
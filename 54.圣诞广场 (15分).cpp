// 7.ʥ���㳡 (15��)
	// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
	// 	��Ŀ���ݣ�
	// 	Angel������ģ�ȥ��ʥ����(CX *^_^*)����ϲ����Ŀ�ĵ��ҹ䣬��Ȼ�����������׵ػ�ͷ��Angel��
	// 
	// 	ȥ�㳡����ô����ʲôʱ����ܵ��أ����Ѿ��õ���CX�ĵ�ͼ����ͼ����N(N <= 100)������·�ڣ���
	// 
	// 	��·��֮������·������(������1000����·)����ΪCX������ѭ��ֵĹ��򣬵�·���ǵ���ģ���ͬ
	// 
	// 	�ĵ�·֮����һ���ľ��룬���Ǽ���Angel���ڵĵص�Ϊ��1���㳡���ڵ�ΪN������Angel��һ��λ��
	// 
	// 	����Ҫһ��λʱ�䡣��Angel��������ʲôʱ�򵽴�㳡�� 
	// 	��������
	// 	�����ж������ݣ���һ��N, M��M�Ǳߵ�����,�Ժ�M�У�ÿ��3������X, Y, Weight������һ����X
	// 
	// 	���е�Y���У�����ΪWeight�ıߡ�
	// 
	// 	�������
	// 	ÿ�����ݣ���һ��������ʱ�䣬�ڶ��������ʱ�䣬Ҫ�ǿ�����Angel������Զ�����˹㳡����
	// 
	// 	��һ��Never��
	// 
	// 	��������
	// 	5 5
	// 	1 2 1
	// 	1 4 10
	// 	2 3 1
	// 	3 4 1
	// 	4 5 1
	// 
	// 	�������
	// 	4
	// 	11
#include <iostream>
#include <cstring>
#define INFINITE  10000000
using namespace std;
int n, m;         //n���㣬m��·
int a[100][100];  //Ȩֵ���� 
int dist[100];    //���� 
int pre[100];

int  pathDijkstra(int n, int s){  //sΪԴ�� 
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
int  fpathDijkstra(int n, int s){  //sΪԴ��  ˮ���� *^_^* 
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
			if(!boolInA[i] && mindis <= dist[i]){    //���˸�= 
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
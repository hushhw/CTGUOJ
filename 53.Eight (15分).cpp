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
#include <iostream>
#include <cstdio>
#include <set>
#include <string>
using namespace std;

typedef int State[9];             //定义状态类型
const int maxstate = 10000000;     
int goal[9]={
	1, 2, 3,
	8, 0, 4,
	7, 6, 5
};
State st[maxstate];               //状态数组，保存所有状态
int dist[maxstate];               //距离数组   
//如果需要打印方案，可以在这里加一个"父亲编号"数组int fa[maxstatue]
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

set<int> vis;
void init_lookup_table(){
	vis.clear();
}
int try_to_insert(int s){
	int v = 0;
	for(int i = 0; i < 9; i++)
		v = v * 10 + st[s][i];
	if(vis.count(v))
		return 0;
	vis.insert(v);
	return 1;
}

int bfs(){                       //bfs,返回目标状态在st数组下标
	init_lookup_table();         //初始化查找表
	int front = 1, rear =  2;    //不使用下标0，因为0被看作“不存在”
	while(front < rear){
		State& s = st[front];   //用引用简化代码          
		if(memcmp(goal, s, sizeof(s)) == 0)
			return front;            //找到目标状态，成功返回
		int z;
		for(z = 0; z < 9; z++)        //找到0的位置
			if(!s[z])
				break;
		int x = z / 3, y = z % 3;
		for(int d = 0; d < 4; d++){
			int newx = x + dx[d];
			int newy = y + dy[d];
			int newz = newx * 3 + newy;
			if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3){   //判断是否移动合法
				State& t = st[rear];
				memcpy(&t, &s, sizeof(s));   //扩展新结点
				t[newz] = s[z];
				t[z] = s[newz];
				dist[rear] = dist[front] + 1; //更新新结点的距离值
				if(try_to_insert(rear))
					rear++;
			}
		}       
		front++; //扩展完毕再修改对首指针
		//      cout << front << " ";
	}
	return 0;    //失败   
}

int main(){
	for(int i = 0; i < 9; i++)
		cin >> st[1][i];
	for(int i = 0; i < 9; i++)
		cin >> goal[i];
	int ans = bfs();
	if(ans > 0)
		cout << dist[ans] ;
	else
		cout << -1;

	return 0;
}
/*
#include<stdio.h>  
#include<string.h>  
#include<iostream>  
#include<queue>  

using namespace std;  

typedef struct{  
	char str[15];  
	int pos;  
	int step;  
}node;  

int vis[370000], f[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};  
char des[15] = "123804765";  

int bfs(char str[]);  
int cantor(char str[]);  
int main(){  
	char str[15];  

	scanf("%s", str);  
	printf("%d\n", bfs(str));  
	return 0;  
}  

int bfs(char str[]){  
	node q, p;  
	queue <node> Q;  
	int i, pos;  

	strcpy(p.str, str);  
	for(i = 0; i < 9; i++){  
		if(str[i] == '0'){  
			p.pos = i;  
			break;  
		}  
	}  
	p.step = 0;  
	vis[cantor(p.str)] = 1;  
	Q.push(p);  

	while(!Q.empty()){  
		q = Q.front();  
		Q.pop();  
		//  printf("pop:%s\n", q.str);  
		//  getchar();  
		if(!strcmp(q.str, des))  
			return q.step;  

		for(i = 0; i < 9; i++){  
			if(q.str[i] == '0'){  
				pos = i;  
				break;  
			}  
		}  

		if(pos > 2){  
			strcpy(p.str, q.str);  
			swap(p.str[pos], p.str[pos - 3]);  
			p.pos = pos - 3;  
			p.step = q.step + 1;  
			if(!vis[cantor(p.str)]){  
				Q.push(p);  
				vis[cantor(p.str)] = 1;  
			}  
		}  

		if(pos < 6){  
			strcpy(p.str, q.str);  
			swap(p.str[pos], p.str[pos + 3]);  
			p.pos = pos + 3;  
			p.step = q.step + 1;  
			if(!vis[cantor(p.str)]){  
				Q.push(p);  
				vis[cantor(p.str)] = 1;  
			}  
		}  

		if(pos % 3){  
			strcpy(p.str, q.str);  
			swap(p.str[pos], p.str[pos - 1]);  
			p.pos = pos - 1;  
			p.step = q.step + 1;  
			if(!vis[cantor(p.str)]){  
				Q.push(p);  
				vis[cantor(p.str)] = 1;  
			}  
		}  

		if(pos % 3 != 2){  
			strcpy(p.str, q.str);  
			swap(p.str[pos], p.str[pos + 1]);  
			p.pos = pos + 1;  
			p.step = q.step + 1;  
			if(!vis[cantor(p.str)]){  
				Q.push(p);  
				vis[cantor(p.str)] = 1;  
			}  
		}  
	}  
}  

int cantor(char str[]){  
	int i, j, ans, temp;  
	int record[15];  

	memset(record, 0, sizeof(record));  
	ans = 1;  
	for(i = 0; i < 9; i++){  
		temp = 0;  
		for(j = '0'; j < str[i]; j++){  
			if(!record[j - '0']){  
				temp++;  
			}  
		}  
		record[str[i] - '0'] = 1;  
		ans += temp * f[8 - i];  
	}  

	return ans;  
}  
*/
/*
//错误版本
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;


int num;
int temp;
int loc;	//标记0所在位置

struct node 
{
	int xy[3][3];
	int dir;
};
struct node sh;

void search(long long s_sum, int s_dir)
{
	for (int i = 0; i < 9; i++)
		if (sh.xy[i / 3][i % 3] == 0) 
			loc = i;
	if(s_sum == 123804765)
	{
		num++;
		return ;
	}
	else
	{
		int stand = s_dir;
		//dir的0 1 2 3分别代表左 上 右 下
		if (loc / 3 != 0 && stand != 1)
		{
			temp = sh.xy[loc/3][loc%3];
			sh.xy[loc/3][loc%3] = sh.xy[loc/3-1][loc%3];
			sh.xy[loc/3-1][loc%3] = temp;
			num++;
			int dir_num = s_dir;
			s_dir=3;
			s_sum = sh.xy[0][0]*100000000 + sh.xy[0][1]*10000000 + sh.xy[0][2]*1000000 + sh.xy[1][0]*100000 + sh.xy[1][1]*10000 + sh.xy[1][2]*1000 + sh.xy[2][0]*100 + sh.xy[2][1]*10 + sh.xy[2][2];
			search(s_sum, s_dir);
			temp = sh.xy[loc/3][loc%3];
			sh.xy[loc/3][loc%3] = sh.xy[loc/3-1][loc%3];
			sh.xy[loc/3-1][loc%3] = temp;
			s_dir=dir_num;
			num--;
		}
		if (loc / 3 != 2 && stand != 3)
		{
			temp = sh.xy[loc/3][loc%3];
			sh.xy[loc/3][loc%3] = sh.xy[loc/3+1][loc%3];
			sh.xy[loc/3+1][loc%3] = temp;
			num++;
			int dir_num = s_dir;
			s_dir=1;
			s_sum = sh.xy[0][0]*100000000 + sh.xy[0][1]*10000000 + sh.xy[0][2]*1000000 + sh.xy[1][0]*100000 + sh.xy[1][1]*10000 + sh.xy[1][2]*1000 + sh.xy[2][0]*100 + sh.xy[2][1]*10 + sh.xy[2][2];
			search(s_sum, s_dir);
			temp = sh.xy[loc/3][loc%3];
			sh.xy[loc/3][loc%3] = sh.xy[loc/3+1][loc%3];
			sh.xy[loc/3+1][loc%3] = temp;
			s_dir=dir_num;
			num--;
		}
		if (loc % 3 != 0 && stand != 0)
		{
			temp = sh.xy[loc/3][loc%3];
			sh.xy[loc/3][loc%3] = sh.xy[loc/3][loc%3-1];
			sh.xy[loc/3][loc%3-1] = temp;
			num++;
			int dir_num = s_dir;
			s_dir=2;
			s_sum = sh.xy[0][0]*100000000 + sh.xy[0][1]*10000000 + sh.xy[0][2]*1000000 + sh.xy[1][0]*100000 + sh.xy[1][1]*10000 + sh.xy[1][2]*1000 + sh.xy[2][0]*100 + sh.xy[2][1]*10 + sh.xy[2][2];
			search(s_sum, s_dir);
			temp = sh.xy[loc/3][loc%3];
			sh.xy[loc/3][loc%3] = sh.xy[loc/3][loc%3-1];
			sh.xy[loc/3][loc%3-1] = temp;
			s_dir=dir_num;
			num--;
		}
		if (loc % 3 != 2 && stand != 2)
		{
			temp = sh.xy[loc/3][loc%3];
			sh.xy[loc/3][loc%3] = sh.xy[loc/3][loc%3+1];
			sh.xy[loc/3][loc%3+1] = temp;
			num++;
			int dir_num = s_dir;
			s_dir=0;
			s_sum = sh.xy[0][0]*100000000 + sh.xy[0][1]*10000000 + sh.xy[0][2]*1000000 + sh.xy[1][0]*100000 + sh.xy[1][1]*10000 + sh.xy[1][2]*1000 + sh.xy[2][0]*100 + sh.xy[2][1]*10 + sh.xy[2][2];
			search(s_sum, s_dir);
			temp = sh.xy[loc/3][loc%3];
			sh.xy[loc/3][loc%3] = sh.xy[loc/3][loc%3+1];
			sh.xy[loc/3][loc%3+1] = temp;
			s_dir=dir_num;
			num--;
		}
	}
	
}

int main()
{
	num=0;
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
		{
			cin>>sh.xy[i][j];
		}
	sh.dir=-1;
	search(0, sh.dir);
	cout<<num<<endl;
	return 0;
}
*/

/*
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int count1=1;

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
int location(int num)
{
	int i;
	for (i = 0; i < 9; i++)
		if (sh[num].xy[i / 3][i % 3] == 0) 
		{
			cout<<"i:"<<i<<endl;
			return i;
		}
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
	loc = location(num);
	int stand = sh[num].dir;
	//dir的0 1 2 3分别代表左 上 右 下
	if (loc / 3 != 0 && stand != 1)
	{
		sh[count1] = sh[num];
		temp = sh[count1].xy[loc / 3][loc % 3];
		sh[count1].xy[loc / 3][loc % 3] = sh[count1].xy[loc / 3 - 1][loc % 3];
		sh[count1].xy[loc / 3 - 1][loc % 3] = temp;
		sh[count1].dir = 3;
		count1++;
	};
	if (loc / 3 != 2 && stand != 3)
	{
		sh[count1] = sh[num];
		temp = sh[count1].xy[loc / 3][loc % 3];
		sh[count1].xy[loc / 3][loc % 3] = sh[count1].xy[loc / 3 + 1][loc % 3];
		sh[count1].xy[loc / 3 + 1][loc % 3] = temp;
		sh[count1].dir = 1;
		count1++;
	}
	if (loc % 3 != 0 && stand != 0)
	{
		sh[count1] = sh[num];
		temp = sh[count1].xy[loc / 3][loc % 3];
		sh[count1].xy[loc / 3][loc % 3] = sh[count1].xy[loc / 3][loc % 3 - 1];
		sh[count1].xy[loc / 3][loc % 3 - 1] = temp;
		sh[count1].dir = 2;
		count1++;
	}
	if (loc % 3 != 2 && stand != 2)
	{
		sh[count1] = sh[num];
		temp = sh[count1].xy[loc / 3][loc % 3];
		sh[count1].xy[loc / 3][loc % 3] = sh[count1].xy[loc / 3][loc % 3 + 1];
		sh[count1].xy[loc / 3][loc % 3 + 1] = temp;
		sh[count1].dir = 0;
		count1++;
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
	system("pause");
	return 0;
}
*/
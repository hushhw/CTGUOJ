// 6.Eight (15��)
	// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
	// 	��Ŀ���ݣ�
	// 	��3*3��������,���а˸�����,ÿ�������ϱ���1��8��ĳһ����.����������һ���ո�,�ո���0����ʾ.�ո���Χ�����ӿ����Ƶ��ո���.Ҫ���������ǣ�����һ�ֳ�ʼ���ֺ�Ŀ�겼��,Ϊ��ʹ��Ŀ��,��Ŀ��״̬Ϊ:
	// 1 2 3
	// 	8 0 4
	// 	7 6 5
	// 	�ҵ�һ�����ٲ�����ƶ�����,ʵ�ִӳ�ʼ���ֵ�Ŀ�겼�ֵ�ת��.
	// 	��������
	// 	�������״̬,3*3�ľŸ�����,�ո���0��ʾ.
	// 
	// 	�������
	// 	ֻ��һ��,����ֻ��һ������,��ʾ�ӳ�ʼ״̬��Ŀ��״̬��Ҫ�������ƶ���
	// 	(���޷�����Ŀ��״̬�����-1).
	// 
	// 	��������
	// 	2 8 3
	// 	1 0 4
	// 	7 6 5
	// 
	// 	�������
	// 	4
#include <iostream>
#include <cstdio>
#include <set>
#include <string>
using namespace std;

typedef int State[9];             //����״̬����
const int maxstate = 10000000;     
int goal[9]={
	1, 2, 3,
	8, 0, 4,
	7, 6, 5
};
State st[maxstate];               //״̬���飬��������״̬
int dist[maxstate];               //��������   
//�����Ҫ��ӡ�����������������һ��"���ױ��"����int fa[maxstatue]
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

int bfs(){                       //bfs,����Ŀ��״̬��st�����±�
	init_lookup_table();         //��ʼ�����ұ�
	int front = 1, rear =  2;    //��ʹ���±�0����Ϊ0�������������ڡ�
	while(front < rear){
		State& s = st[front];   //�����ü򻯴���          
		if(memcmp(goal, s, sizeof(s)) == 0)
			return front;            //�ҵ�Ŀ��״̬���ɹ�����
		int z;
		for(z = 0; z < 9; z++)        //�ҵ�0��λ��
			if(!s[z])
				break;
		int x = z / 3, y = z % 3;
		for(int d = 0; d < 4; d++){
			int newx = x + dx[d];
			int newy = y + dy[d];
			int newz = newx * 3 + newy;
			if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3){   //�ж��Ƿ��ƶ��Ϸ�
				State& t = st[rear];
				memcpy(&t, &s, sizeof(s));   //��չ�½��
				t[newz] = s[z];
				t[z] = s[newz];
				dist[rear] = dist[front] + 1; //�����½��ľ���ֵ
				if(try_to_insert(rear))
					rear++;
			}
		}       
		front++; //��չ������޸Ķ���ָ��
		//      cout << front << " ";
	}
	return 0;    //ʧ��   
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
//����汾
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;


int num;
int temp;
int loc;	//���0����λ��

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
		//dir��0 1 2 3�ֱ������ �� �� ��
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
	printf("������ʼ�ڵ��λ��:\n");
	int i,j;
	for(i=0; i<3; i++)
		for(j=0; j<3; j++)
			scanf("%d", &sh[0].xy[i][j]);
	sh[0].dir = -1;
	printf("����Ŀ��ڵ�λ��:\n");
	for(i=0; i<3; i++)
		for(j=0; j<3; j++)
			scanf("%d", &sh[101].xy[i][j]);
	sh[101].dir = -1;
}

//�ҳ�0��λ��
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

//���б��
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
	//dir��0 1 2 3�ֱ������ �� �� ��
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
			printf("�������޴���\n");
			return 0;
		}
		if(sign(i) == sign(101))
		{
			printf("�ڵ�%d���ҵ���", i);
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
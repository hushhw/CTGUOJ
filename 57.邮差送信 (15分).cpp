// 10.邮差送信 (15分)
// 	C时间限制：1 毫秒 |  C内存限制：3000 Kb
// 	题目内容：
// 	有一个邮递员要在n个城市之间来回送信。但有的城市之间有大路相连而有的没有路。
// 	现在要由一个城市到另一个城市送信，中途最少要经过多少个其它的城市呢？
// 	输入描述
// 	第一行是n,k(1<=n<=10000, 1<=k<=20000)，接下来就是k行。这k行每行有两个数a,b(1<=a,b<= n)，表示城市a和b之间有大路k行以后就是两个数p和q。
// 
// 	输出描述
// 	输出从城市p到城市q之间最少要经过的其它的城市的数目。如果p和q之间不连通则输出0
// 
// 	输入样例
// 	6 6
// 	1 4
// 	1 2
// 	2 3
// 	3 4
// 	5 4
// 	5 6
// 	1 6
// 
// 	输出样例
// 	2

//经典的dfs题
//解析详见：http://blog.csdn.net/zlambert/article/details/65695000
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int n,k,x,y;
int far[200];		//求路径，即存储它前一个结点
int m=0,s=0;
bool a[200][200];	//存路径
bool vis[200];		//标记

int print(int a)
{
	if(a==0)
		return s;
	else
		s++;
	//cout<<"a:"<<a<<endl;
	//cout<<"f[a]:"<<far[a]<<endl;
	print(far[a]);
}

void dfs()
{
	int q[11000], head=0, tail=1;	//q模拟队列
	q[tail] = x;					//将第一个位置入队
	far[x]=0;
	vis[x]=1;			//标记为已访问
	while(head < tail)	//如果队列非空，则移出队列首部状态，扩展他所有的子状态
	{
		head++;			//移出首部元素
		for(int i=1; i<=n; ++i)
		{
			if(a[q[head]][i]==1 && vis[i]==0)	//如果有联通并且未访问
			{
				tail++;
				q[tail]=i;		//满足条件则把该元素存入队列
				far[i]=q[head];	//far指向队首
				//cout<<"far:"<<far[i]<<endl;
				//cout<<"q:"<<q[tail]<<endl;
				vis[i]=1;		//标记为已访问
				if(q[tail]==y)
				{
					cout<<print(q[tail])-2<<endl;
					m=1;
					return ;
				}
			}
		}
	}
	if(head == tail)    //未找到
		cout << 0;
}

int main()
{
	memset(a,0,sizeof(a));
	memset(vis,0,sizeof(vis));
	memset(far,0,sizeof(far));
	int b,c;
	cin>>n>>k;
	for(int i=1; i<=k; ++i)
	{
		cin>>b>>c;
		a[b][c]=1;
		a[c][b]=1;
	}
	cin>>x>>y;
	dfs();
	system("pause");
	return 0;
}
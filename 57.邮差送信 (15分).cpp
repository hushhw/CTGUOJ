// 10.�ʲ����� (15��)
// 	Cʱ�����ƣ�1 ���� |  C�ڴ����ƣ�3000 Kb
// 	��Ŀ���ݣ�
// 	��һ���ʵ�ԱҪ��n������֮���������š����еĳ���֮���д�·�������е�û��·��
// 	����Ҫ��һ�����е���һ���������ţ���;����Ҫ�������ٸ������ĳ����أ�
// 	��������
// 	��һ����n,k(1<=n<=10000, 1<=k<=20000)������������k�С���k��ÿ����������a,b(1<=a,b<= n)����ʾ����a��b֮���д�·k���Ժ����������p��q��
// 
// 	�������
// 	����ӳ���p������q֮������Ҫ�����������ĳ��е���Ŀ�����p��q֮�䲻��ͨ�����0
// 
// 	��������
// 	6 6
// 	1 4
// 	1 2
// 	2 3
// 	3 4
// 	5 4
// 	5 6
// 	1 6
// 
// 	�������
// 	2

//�����dfs��
//���������http://blog.csdn.net/zlambert/article/details/65695000
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int n,k,x,y;
int far[200];		//��·�������洢��ǰһ�����
int m=0,s=0;
bool a[200][200];	//��·��
bool vis[200];		//���

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
	int q[11000], head=0, tail=1;	//qģ�����
	q[tail] = x;					//����һ��λ�����
	far[x]=0;
	vis[x]=1;			//���Ϊ�ѷ���
	while(head < tail)	//������зǿգ����Ƴ������ײ�״̬����չ�����е���״̬
	{
		head++;			//�Ƴ��ײ�Ԫ��
		for(int i=1; i<=n; ++i)
		{
			if(a[q[head]][i]==1 && vis[i]==0)	//�������ͨ����δ����
			{
				tail++;
				q[tail]=i;		//����������Ѹ�Ԫ�ش������
				far[i]=q[head];	//farָ�����
				//cout<<"far:"<<far[i]<<endl;
				//cout<<"q:"<<q[tail]<<endl;
				vis[i]=1;		//���Ϊ�ѷ���
				if(q[tail]==y)
				{
					cout<<print(q[tail])-2<<endl;
					m=1;
					return ;
				}
			}
		}
	}
	if(head == tail)    //δ�ҵ�
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
// 15.安排车辆 (15分)
// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
// 	题目内容：
// 	有一家出租车公司，通过网络预约安排出租。现收到M个预约单，希望用车时间区间是（s1,f1）,(s2,f2),...,(sM,fM).
// 	问最少需要准备几辆车才能完成出租。提示：车辆归还后，下一个客户才可以使用。
// 	输入描述
// 	第一行是M，随后M行是预约的时间区间
// 
// 	输出描述
// 	最少需要的车的台数
// 
// 	输入样例
// 	4
// 	1,5
// 	2,7
// 	3,6
// 	8,10
// 
// 	输出样例
// 	3
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int sum[101]={0};

struct fangkuai
{
	int L,R;
	int num;
};

int main()
{
	int N;
	fangkuai a[101];
	int b[101];
	while(scanf("%d",&N)!=EOF)
	{
		int m=0;
		for(int i=0; i<N; i++)
		{
			cin>>a[i].L>>a[i].R;
			a[i].num=0;
		}
		int max=0;
		for(int i=0; i<N; i++)
		{
			max = sum[a[i].L];
			for(int j=a[i].L; j<=a[i].R; j++)
			{
				sum[j]++;
				if(sum[j]>max)
					max = sum[j];
			}
			for(int k=a[i].L; k<=a[i].R; k++)
			{
				sum[k]=max;
			}
			b[m++]=max;
		}
		int MAX=b[0];
		for(int i=0; i<m; i++)
		{
			if(b[i]>MAX)
				MAX=b[i];
		}
		cout<<MAX<<endl;

	}
	return 0;
}
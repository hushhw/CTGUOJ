// 4.考新郎 (10分)
// 	C时间限制：1 毫秒 |  C内存限制：3000 Kb
// 	题目内容：
// 	国庆期间,省城HZ刚刚举行了一场盛大的集体婚礼,为了使婚礼进行的丰富一些,司仪临时想出了有一个有意思的节目,叫做"考新郎",具体的操作是这样的:首先,给每位新娘打扮得几乎一模一样,并盖上大大的红盖头随机坐成一排;然后,让各位新郎寻找自己的新娘.每人只准找一个,并且不允许多人找一个.最后,揭开盖头,如果找错了对象就要当众跪搓衣板..
// 	假设一共有N对新婚夫妇,其中有M个新郎找错了新娘,求发生这种情况一共有多少种可能.
// 	输入描述
// 	N M
// 
// 	输出描述
// 	可能的种数
// 
// 	输入样例
// 	3 2
// 
// 	输出样例
// 	3

#include <cstdio>
#include <iostream>
using namespace std;
long long f[22];  
void init()//错排  
{  
	f[1]=0;  
	f[2]=1;  
	for(int i=3;i<=20;i++)  
	{  
		f[i]=(i-1)*(f[i-1]+f[i-2]);  
	}  
	return ;  
}  

int main()
{
	int N,M;
	init();
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		int x=N,y=M;
		if(M>N/2)
			M = N - M;
		int sum=0, sum_a=1, sum_b=1;
		for(int i=1; i<=M; i++)
			sum_b *= i;
		while(M)
		{
			sum_a*=N;
			N--;
			M--;
		}
		sum = sum_a/sum_b;
		cout<<sum*f[y]<<endl;
	}
	return 0;
}
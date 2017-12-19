// 4.短信套餐 (10分)
	// 	C时间限制：1 毫秒 |  C内存限制：65535 Kb
	// 	题目内容：
	// 	某通信公司为推广手机短信，提出了短信套餐优惠政策。
	// 	用户必须选择一种短信套餐，且只能选择一种。每种套餐的形式为：每月交p元，可以发送免费短信f条。如果超过了f条，则超过的部分按每条a元收费。
	// 	现在你已经预知下个月需要发送m条短信，现在，这家公司的短信套餐种类太多了，请您编个程序告诉他选择最省钱的短信套餐需要交多少钱。
	// 	输入描述
	// 	输入有多组数据。每组数据第一行为整数n和m，用一个空格隔开，分别是套餐的种类数和下月短信条数。1<=n<=1000，0<=m<=10000
	// 	下一行有一个实数a，表示超过的部分按每条a元收费。（0<a<=2）
	// 	以下的n行，每行有实数p和整数f，用一个空格隔开，表示这种短信套餐为p元可以发送短信f条。（0<=p<=100,1<=f<=10000）。
	// 
	// 	输出描述
	// 	对每组输入数据，输出采用最省钱的短信套餐需交的费用。保留小数点后两位数。
	// 
	// 	输入样例
	// 	5 222
	// 	0.1
	// 	10 120
	// 	15 200
	// 	20 300
	// 	30 500
	// 	50 1000
	// 
	// 	输出样例
	// 	17.20

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

/*
int main()
{
	int n,m;
	int p[101],f[10001];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		double a;
		double sum[101];
		cin>>a;
		for(int i=0; i<n; i++)
			cin>>p[i]>>f[i];
		for(int i=0; i<n; i++)
		{
			sum[i]=p[i];
			if(m>f[i])
				sum[i]+=(m-f[i])*a;
		}
		double max =sum[0];
		for(int i=0; i<n; i++)
		{
			if(sum[i]<max)
				max=sum[i];
		}
		printf("%.2lf\n",max);
	}
	return 0;
}
*/

int main(){  
	int m,i,n,count=0;  
	float z,s,sum[100]={0},min;  
	float a[100],b[100],x[100]={0.0};  

	while(cin>>m&&m!=00){  
		cin>>n;  
		cin>>z;  

		//int *sum=new int[m]();//int sum[m];  
		//int *a=new int [m]();  
		//int *b=new int [m]();  
		for(i=0;i<m;i++){  
			cin>>a[i];  
			cin>>b[i];  
		}  
		for(i=0;i<m;i++){  
			s=0;  
			if(b[i]<n)  
				s=a[i]+(n-b[i])*z;  
			else  
				s=a[i];  
			sum[i]=s;  
		}  
		min=sum[0];  
		for(i=0;i<m;i++)  
			if(sum[i]<min)  
				min=sum[i];   

		x[count++]=min;  
	}  
	for(i=0;i<count;i++)  
		printf("%.2f\n",x[i]);  
	return 0;  
}  
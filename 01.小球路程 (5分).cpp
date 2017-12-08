#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	double n;
	while(scanf("%lf",&n)!=EOF)
	{
		double sum=n,m=n;
		while(n>=m/1000)
		{
			sum+=n*2.0;
			n = n*0.7;
			
		}
		sum-=m*2.0;
		printf("%.4lf\n",sum);
	}
	return 0;
}
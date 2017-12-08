#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a,b,c,sum=0;
		for(a=0; a<=n/5; a++)
		{
			for(b=0; b<=n/2; b++)
			{
				for(c=0; c<=n; c++)
				{
					if(a*5+b*2+c == n)
						sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
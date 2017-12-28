#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
void fun(int a){  
	int s[1000]={0};  
	s[0]=0;  
	s[1]=0;  
	s[2]=1;  
	s[3]=0;  
	s[4]=1;  
	s[5]=0;  
	s[6]=1;  
	s[7]=0;  
	s[8]=1;  
	for(int i=9;i<1000;i++){  
		if(s[i-1]==0||s[i-3]==0||s[i-7]==0||s[i-8]==0)  
			s[i]=1;  
		else  
			s[i]=0;  
	}  
	printf("%d\n",s[a]);  
}  
int main(){  
	int i,n,a[100];  
	scanf("%d",&n);  
	for(i=0;i<n;i++){  
		scanf("%d",&a[i]);  
		fun(a[i]);  
	}  
	return 0;  
}
// 4.排列组合 (15分)
	// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	对字符串（数字，字母，符号）进行全排列，并统计全排列的种树
	// 	输入描述
	// 	输入一个字符串
	// 
	// 	输出描述
	// 	输出字符串的全排列，每种情况占一行，最后一行输出全排列的个数
	// 
	// 	输入样例
	// 	123
	// 
	// 	输出样例
	// 	123
	// 	132
	// 	213
	// 	231
	// 	312
	// 	321
	// 	6
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string str;
string s[101];
int sum;

bool isSwap(int k, int m)    //排除相等情况
{    
	for(int i=k;i<m;i++)    
		if(str[m]==str[i])    
			return false;    
	return true;    
}    

void Perm(int k, int n)
{
	if(k==n)
	{
		s[sum++] = str;
	}
	else
	{
		for(int i=k; i<=n; i++)
		{
			if(isSwap(k,i))
			{
				swap(str[i], str[k]);
				Perm(k+1, n);
				swap(str[i], str[k]);
			}
		}
	}
}

int main()
{
	
	while(cin>>str)
	{
		sum=0;
		int len = str.length();
		Perm(0,len-1);
		sort(s,s+sum);
		for(int i=0; i<sum; i++)
			cout<<s[i]<<endl;
		cout<<sum<<endl;
	}
	return 0;
}
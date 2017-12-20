// 6.字符典 (15分)
	// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	在数据压缩和数据加密过程中常需要对特殊的字符串进行编码. 给定的字母表A由26
	// 
	// 	个小写英文字母组成A?={a,b,...z}. 该字母表产生的升序字符串指的是字符串中字母按
	// 
	// 	照从左到右出现的次序与字母表中出现的次序相同，且每个字符最多出现1次. 例如，
	// 
	// 	a,b,ab,xyz,ax等都是升序字符串. 现在对字母表A产生的所有长度不超过6的升序字符串
	// 
	// 	按照字典序排列如下.
	// 	1	2	3	…	26	27	28	…
	// 	a	b	c	…	z	ab	ac	…
	// 	对于给定长度不超过6的升序字符串，编程计算出它在上述字典中的编码.
	// 	输入描述
	// 	输入数据的第1行是一个正整数k,表示接下来共有k行.在接下来的k行中，每行给出一个
	// 
	// 	字符串.
	// 
	// 	输出描述
	// 	输出结果，每行对应于一个字符串的编码.
	// 
	// 	输入样例
	// 	3
	// 	a
	// 	b
	// 	abc
	// 
	// 	输出样例
	// 	1
	// 	2
	// 	352
/*
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
 
int main(){  
	string s;  
	int a[100][26];  
	int i,j,k,n,length,sum;  
	cin>>n;  
	while(n--)
	{  
		cin>>s;  
		sum=0;  
		length = s.length();  
		for(i=1;i<=26;i++)  
			a[1][i]=1;  
		for(i=2;i<=length;i++) 
		{
			for(j=1;j<=26;j++)
			{  
				a[i][j]=0;  
				if(26-j>=i-1)
				{  
					for(k=j+1;k<=26;k++)  
						a[i][j]+=a[i-1][k];  
				}  
			}  
		}
		for(i=1;i<length;i++)  
			for(j=1;j<=26;j++)  
				sum+=a[i][j]; 

		for(i=1;i<=s[0]-'a';i++)  
			sum+=a[length][i];  
		for(i=1;i<length;i++)  
			for(j=s[i-1]-'a'+1;j<s[i]-'a';j++)  
				sum+=a[length-i][j];  
		cout<<sum+1<<endl;  
	}
	system("pause");
	return 0;         
}
*/


// 对于此问题，我把它归结于数学中的排列组合知识，从26个字母中任选M个数即是
// 	A（26，M）种排法，但是顺序一定（升序），就成为C（26，M），所以要想知道升序字母串所代表的数，只要算出它是第多少种排法即可。
// 	如 ABC：  编码=一个字母的所有排序+两个字母的所有排序+三个字母的所有排序（多算了，所以后面要减去）-   三个字母里ABC后面的排序。
/*
#include<iostream>
#include<string>
using namespace std;
int zh(int a,int b)
{
	int i,c=a,d=b,sum1=1,sum2=1;
	for(i=0;i<b;i++)
	{
		sum1*=c;
		c--;
	}
	for(i=0;i<b;i++)
	{
		sum2*=d;
		d--;
	}
	return sum1/sum2;
}

int main(){
	string ch;
	int i,a[10];
	while(cin>>ch)
	{
		memset(a,0,sizeof(a));

		a[0]=zh(26,ch.length());
		for(i=1;i<=ch.length();i++)
		{
			a[i]=zh(122-ch[i-1],ch.length()-i+1);
		}
		for(i=1;i<=ch.length();i++)
			a[0]-=a[i];
		for(i=1;i<ch.length();i++)
			a[0]+=zh(26,i);
		cout<<a[0]<<endl;
	}
	return 0;
}
*/

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int f(int i,int k)
{/*以第i个字符开头，长度为k的字符的升序字符个数*/
	int sum=0;
	if(k==1)
		return 1;
	for(int j=i+1;j<=26;j++)
		sum+=f(j,k-1);
	return sum;

}
int g(int k)
{//长度为k的字符串长度
	int sum=0;
	for(int i=1;i<=26;i++)
	{
		sum+=f(i,k);

	}
	return sum;

}
int calculate(string s)
{
	int sum=0;
	int k=s.length ();
	for(int i=1;i<k;i++)
		sum+=g(i);
	int h=s[0]-'a'+1;;//第一个字母
	for(int i=1;i<h;i++)
		sum+=f(i,k);
	for(int i=1,temp=h;i<k;i++)
	{
		int n=s[i]-'a'+1;
		int length=k-i;//获取此时的长度
		for(int j=temp+1;j<n;j++)
			sum+=f(j,length);
		temp=n;
	}
	return sum+1;


}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		cout<<calculate(s)<<endl;
	}
	
	return 0;
}
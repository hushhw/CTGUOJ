// 6.�ַ��� (15��)
	// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
	// 	��Ŀ���ݣ�
	// 	������ѹ�������ݼ��ܹ����г���Ҫ��������ַ������б���. ��������ĸ��A��26
	// 
	// 	��СдӢ����ĸ���A?={a,b,...z}. ����ĸ������������ַ���ָ�����ַ�������ĸ��
	// 
	// 	�մ����ҳ��ֵĴ�������ĸ���г��ֵĴ�����ͬ����ÿ���ַ�������1��. ���磬
	// 
	// 	a,b,ab,xyz,ax�ȶ��������ַ���. ���ڶ���ĸ��A���������г��Ȳ�����6�������ַ���
	// 
	// 	�����ֵ�����������.
	// 	1	2	3	��	26	27	28	��
	// 	a	b	c	��	z	ab	ac	��
	// 	���ڸ������Ȳ�����6�������ַ�������̼�������������ֵ��еı���.
	// 	��������
	// 	�������ݵĵ�1����һ��������k,��ʾ����������k��.�ڽ�������k���У�ÿ�и���һ��
	// 
	// 	�ַ���.
	// 
	// 	�������
	// 	��������ÿ�ж�Ӧ��һ���ַ����ı���.
	// 
	// 	��������
	// 	3
	// 	a
	// 	b
	// 	abc
	// 
	// 	�������
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


// ���ڴ����⣬�Ұ����������ѧ�е��������֪ʶ����26����ĸ����ѡM��������
// 	A��26��M�����ŷ�������˳��һ�������򣩣��ͳ�ΪC��26��M��������Ҫ��֪��������ĸ�������������ֻҪ������ǵڶ������ŷ����ɡ�
// 	�� ABC��  ����=һ����ĸ����������+������ĸ����������+������ĸ���������򣨶����ˣ����Ժ���Ҫ��ȥ��-   ������ĸ��ABC���������
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
{/*�Ե�i���ַ���ͷ������Ϊk���ַ��������ַ�����*/
	int sum=0;
	if(k==1)
		return 1;
	for(int j=i+1;j<=26;j++)
		sum+=f(j,k-1);
	return sum;

}
int g(int k)
{//����Ϊk���ַ�������
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
	int h=s[0]-'a'+1;;//��һ����ĸ
	for(int i=1;i<h;i++)
		sum+=f(i,k);
	for(int i=1,temp=h;i<k;i++)
	{
		int n=s[i]-'a'+1;
		int length=k-i;//��ȡ��ʱ�ĳ���
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
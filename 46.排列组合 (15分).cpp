// 4.������� (15��)
	// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
	// 	��Ŀ���ݣ�
	// 	���ַ��������֣���ĸ�����ţ�����ȫ���У���ͳ��ȫ���е�����
	// 	��������
	// 	����һ���ַ���
	// 
	// 	�������
	// 	����ַ�����ȫ���У�ÿ�����ռһ�У����һ�����ȫ���еĸ���
	// 
	// 	��������
	// 	123
	// 
	// 	�������
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

bool isSwap(int k, int m)    //�ų�������
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
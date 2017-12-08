// 7.砝码组合 (15分)
// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
// 	题目内容：
// 	用天平称重时，我们希望用尽可能少的砝码组合称出尽可能多的重量。
// 	如果只有5个砝码，重量分别是1，3，9，27，81。
// 	则它们可以组合称出1到121之间任意整数重量（砝码允许放在左右两个盘中）。
// 	本题目要求编程实现：对用户输入的重量(1~121)，
// 	给出砝码组合方案（用加减式表示，减代表砝码放在物品盘）。
// 	例如：
// 	输入：
// 	5
// 	输出：
// 	9-3-1
// 
// 	输入：
// 	19
// 	输出：
// 	27-9+1
// 
// 	要求程序输出的组合总是大数在前小数在后。
// 	输入描述
// 	用户输入的重量(1~121)，
// 
// 	输出描述
// 	给出砝码组合方案（用加减式表示，减代表砝码放在物品盘）。
// 
// 	输入样例
// 	19
// 
// 	输出样例
// 	27-9+1

/*
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

char num[]={'+', '-', '1', '3', '9', '2','7', '8','1'};
vector<char> str;

int fama(int n,int signal)
{
	if(n==0)
		return 0;
	if(n>=41 && n<=121)
	{
		if(n>=81)
		{
			n-=81;
			str.push_back(num[7]);
			str.push_back(num[8]);
			if(n!=0 && signal==1)
			str.push_back(num[0]);
			else if(n!=0 && signal==0)
			str.push_back(num[1]);
			return fama(n,1);
		}
		else
		{
			n = 81-n;
			str.push_back(num[7]);
			str.push_back(num[8]);
			if(signal==1)
			{
				str.push_back(num[1]);
				return fama(n,0);
			}
			else
			{
				str.push_back(num[0]);
				return fama(n,0);
			}
		}
		
	}
	else if(n>=14 && n<=40)
	{
		if(n>=27)
		{
			n-=27;
			str.push_back(num[5]);
			str.push_back(num[6]);
			if(n!=0 && signal==1)
				str.push_back(num[0]);
			else if(n!=0 && signal==0)
				str.push_back(num[1]);
			return fama(n,1);
		}
		else
		{
			n = 27 - n;
			str.push_back(num[5]);
			str.push_back(num[6]);
			if(signal==1)
			{
				str.push_back(num[1]);
				return fama(n,0);
			}
			else
			{
				str.push_back(num[0]);
				return fama(n,0);
			}
			
		}
	}
	else if(n>=5 && n<=13)
	{
		if(n>=9)
		{
			n-=9;
			str.push_back(num[4]);
			if(n!=0 && signal==1)
				str.push_back(num[0]);
			else if(n!=0 && signal==0)
				str.push_back(num[1]);
			return fama(n,1);
		}
		else
		{
			n = 9 - n;
			str.push_back(num[4]);
			if(signal==1)
			{
				str.push_back(num[1]);
				return fama(n,0);
			}
			else
			{
				str.push_back(num[0]);
				return fama(n,0);
			}
		}
		
	}
	else if(n>=2 && n<=4)
	{
		if(n>=3)
		{
			n-=3;
			str.push_back(num[3]);
			if(n!=0 && signal==1)
				str.push_back(num[0]);
			else if(n!=0 && signal==0)
				str.push_back(num[1]);
			return fama(n,1);
		}
		else
		{
			n = 3 - n;
			str.push_back(num[3]);
			if(signal==1)
			{
				str.push_back(num[1]);
				return fama(n,0);
			}
			else
			{
				str.push_back(num[0]);
				return fama(n,0);
			}
		}
		
	}
	else if(n==1)
	{
		str.push_back(num[2]);
		return fama(n-1,1);
	}
}

int main()
{
	int n;
	
	while(scanf("%d",&n)!=EOF)
	{
		str.clear();
		fama(n,1);
		vector<char>::iterator i;
		int sum=0;
		for(i=str.begin(); i!=str.end(); i++)
		{
			cout<<endl;
		}
		
	}
	return 0;
}
*/

//三进制解题
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
	return abs(a) > abs(b);
}

int main(){
	int z, count = 0, n, a[10] = {0}, b[10] = {1, 3, 9, 27, 81}, c[10]={0};
	cin >> n;
	z = n;
	while(z >= 3)
	{
		a[count++] = z % 3;
		z = z / 3;

	}
	if(z != 0){
		a[count++] = z;
	}
	
	int s = 0;
	for(int i = 0; i < 10; i++){
		if(a[i] != 0){
			if(a[i] == 1){
				c[s++] = b[i];
			}
			else{
				c[s++] = 0 - b[i];
				a[i + 1]++;
			}
		}
	}
	sort(c, c + 10, cmp);
	for(int i = 0; i < 10; i++){
		if(i == 0)
			cout << c[i];
		else if(c[i] > 0){
			cout << "+" << c[i];
		}
		else if(c[i] < 0)
			cout << c[i];
	}
	return 0;
}
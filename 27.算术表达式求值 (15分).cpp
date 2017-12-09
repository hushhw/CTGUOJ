// 9.算术表达式求值 (15分)
// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
// 	题目内容：
// 	输入一个由数字、+，-，*，/ 组成的算术表达式，求其值。
// 	输入描述
// 	一个表达式，其中每个运算数为正整数
// 
// 	输出描述
// 	计算结果，保留2位小数
// 
// 	输入样例
// 	1+12*3-4/2
// 
// 	输出样例
// 	35.00

#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;

int fu(char ch){
	if(ch == '#' || ch == '=')
		return 0;
	if(ch == '-' || ch == '+')
		return 1;
	if(ch == '*' || ch == '/')
		return 2;    
}

void qiuzhi(string str){
	int i = 0;
	stack <double>s;  //数字栈 
	stack <char>f;    //符号栈    优先级低的高的进栈，比栈顶低，则弹出栈顶的进行运算，直到比栈顶高才进栈 
	f.push('#');
	while(str[i]){
		int a = 0, flag = 0;
		while(str[i] >= '0' && str[i] <= '9')
		{
			a = a * 10 + str[i] - '0';
			i++; 
			flag = 1;
		}
		if(flag)
		{
			s.push(a);
			
		}
		if(fu(str[i]) >= fu(f.top()))
		{
			f.push(str[i]);  
			i++;    
		}
		int flag1 = 0;
		while(fu(str[i]) < fu(f.top()))
		{
			char ch = f.top();
			f.pop();
			double c, d, e;
			c = s.top(); s.pop();
			d = s.top(); s.pop();
			if(ch == '-')
				e = d - c;
			else if(ch == '+')
				e = d + c;            
			else if(ch == '*')
				e = d * c;
			else if(ch == '/')
				e = d * 1.0 / c;        
			s.push(e);    
			flag1 = 1;
		}
		if(flag1){
			if(str[i] == '='){
				double sum = s.top();
				printf("%.2lf\n", sum);
				return;
			}
			f.push(str[i]);
			i++;
		}
	}
}

int main(){
	string str;
	while(cin >> str)
	{
		str += '=';
		qiuzhi(str); 
	}
	system("pause");
	return 0;
}
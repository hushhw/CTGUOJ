// 9.�������ʽ��ֵ (15��)
// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
// 	��Ŀ���ݣ�
// 	����һ�������֡�+��-��*��/ ��ɵ��������ʽ������ֵ��
// 	��������
// 	һ�����ʽ������ÿ��������Ϊ������
// 
// 	�������
// 	������������2λС��
// 
// 	��������
// 	1+12*3-4/2
// 
// 	�������
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
	stack <double>s;  //����ջ 
	stack <char>f;    //����ջ    ���ȼ��͵ĸߵĽ�ջ����ջ���ͣ��򵯳�ջ���Ľ������㣬ֱ����ջ���߲Ž�ջ 
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
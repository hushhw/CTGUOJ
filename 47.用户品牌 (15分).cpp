// 5.用户品牌 (15分)
	// 	C时间限制：1 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	馅饼同学是一个在百度工作，做用户请求（query）分析的同学，他在用户请求中经常会遇到一些很奇葩的词汇。在比方说“johnsonjohnson”、“duckduck”，这些词汇虽然看起来是一些词汇的单纯重复，但是往往都是一些特殊品牌的词汇，不能被拆分开。为了侦测出这种词的存在，你今天需要完成我给出的这个任务——“找出用户请求中循环节最多的子串”。
	// 	输入描述
	// 	输入数据包括多组，每组为一个全部由小写字母组成的不含空格的用户请求（字符串），占一行。用户请求的长度不大于100,000。
	// 
	// 	输出描述
	// 	对于每组输入，输出这组用户请求中循环节最多的子串。如果一个用户请求中有两个循环节数相同的子串，请选择那个字典序最小的。
	// 
	// 	输入样例
	// 	duckduckgo
	// 
	// 	输出样例
	// 	duckduck
#include <iostream>  
#include <string>  
#include <cstring>  
#include <cstdio>  
#include <map>  
using namespace std;  

const int maxn = 1000000 + 10;  
char P[maxn];  
int f[maxn];  

int main(){  

	string s;  
	while(cin >> s){  
		map<int, int> halve;  
		int n = s.size();  

		for(int i = 0; i < n; i++){  
			for(int j=i+1; 2*j-1-i < n; j++){  
				for(int k=0; i+k<j; k++){  
					if(s.at(k+i) != s.at(k+j))  
						break;  
					if(k+i == j-1){  
						halve[i] = j;  
						goto out;  
					}  
				}  
			}  
out:  
			;  
		}  

		int count = 1;  
		string ans;  
		for(int i=0; i<n; i++)  
			if(halve.count(i)){  
				f[i] = i;  
				f[i+1] = i;  
				for(int j = i+1; j < n; j++){  
					int k = f[j];  
					while(k!=i && s[j]!=s[k])k = f[k];  
					f[j+1] = (s[j]==s[k]) ? k+1 : i;  
				}  
				for(int j=i+2; j <= n; j++){  
					if(f[j] > 0 && (j-i) % (j-f[j]) == 0){  
						if((j-i) / (j-f[j]) > count){  
							count =  (j-i) / (j - f[j]);  
							ans = s.substr(i, j-i);  
						}  
					}  
				}  
			}  
			cout << ans << endl;  
	}  
}  
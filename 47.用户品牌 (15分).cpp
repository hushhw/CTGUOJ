// 5.�û�Ʒ�� (15��)
	// 	Cʱ�����ƣ�1 ���� |  C�ڴ����ƣ�3000 Kb
	// 	��Ŀ���ݣ�
	// 	�ڱ�ͬѧ��һ���ڰٶȹ��������û�����query��������ͬѧ�������û������о���������һЩ������Ĵʻ㡣�ڱȷ�˵��johnsonjohnson������duckduck������Щ�ʻ���Ȼ��������һЩ�ʻ�ĵ����ظ���������������һЩ����Ʒ�ƵĴʻ㣬���ܱ���ֿ���Ϊ���������ִʵĴ��ڣ��������Ҫ����Ҹ�����������񡪡����ҳ��û�������ѭ���������Ӵ�����
	// 	��������
	// 	�������ݰ������飬ÿ��Ϊһ��ȫ����Сд��ĸ��ɵĲ����ո���û������ַ�������ռһ�С��û�����ĳ��Ȳ�����100,000��
	// 
	// 	�������
	// 	����ÿ�����룬��������û�������ѭ���������Ӵ������һ���û�������������ѭ��������ͬ���Ӵ�����ѡ���Ǹ��ֵ�����С�ġ�
	// 
	// 	��������
	// 	duckduckgo
	// 
	// 	�������
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
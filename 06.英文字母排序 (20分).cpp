// 3.英文字母排序 (20分)
	// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	编写一个程序，当输入英文字符串时，计算机将这个句子中的英文字母按字典字母顺序重新排列，排列后的单词的
	// 	长度要与原始句子中的长度相同，并且要求只对Ａ到Ｚ的字母重新排列，其它字符保持原来的状态。
	// 	输入描述
	// 	一个字符串，包括大写英文字母，以及其他字符
	// 
	// 	输出描述
	// 	字符串的重新排列，只是大写字母按字典顺序，其他字母保持原位
	// 
	// 	输入样例
	// 	ＴＨＥ ＰＲＩＣＥ ＯＦＢＲＥＡＤ ＩＳ ￥１ ２５ ＰＥＲ ＰＯＵＮＤ
	// 
	// 	输出样例
	// 	ＡＢＣ ＤＤＥＥＥ ＥＦＨＩＩＮＯ ＯＰ ￥１ ２５ ＰＰＲ ＲＲＳＴＵ

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char str[1001];
	gets(str);
	char tc;
	int len = strlen(str);
	for(int i=0; i<len; i++)
	{
		for(int j=i+1; j<len; j++)
		{
			if(str[i]>='A' && str[i]<='Z' && str[j]>='A' && str[j]<='Z')
			{
				if(str[j]<=str[i])
				{
					tc = str[i];
					str[i] = str[j];
					str[j] = tc;
				}
			}
		}
	}
	puts(str);
	system("pause");
	return 0;
}
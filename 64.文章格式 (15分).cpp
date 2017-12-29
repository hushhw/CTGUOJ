// 17.文章格式 (15分)
	// 	C时间限制：3000 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	编写程序实现将一段文章格式化打印出来。打印时每行的长度为20个字符。
	// 	如果一行的最后一个单词超过了本行的20个字符的范围，则应把它移到下一行。
	// 	另外在每个单词之间增加一个空格，最后一个单词前面可能需要增加多个空格，
	// 	使每行的末尾准确地处在第20个位置处。
	// 	输入描述
	// 	输入n个单词（连续输入，每个单词不能超过20个字母，单词间用空格隔开，但不
	// 	要人为转行，也就是说如果输入的单词超过一行也不要按Enter）
	// 
	// 	输出描述
	// 	将上面n个单词分行打印，每行20个字符，如果一行只能放一个单词则单词后用空格填充，
	// 	若一行可放多个单词，则末尾必须为单词，且一个单词不能跨行输出。
	// 
	// 	输入样例
	// 	The relationship between XML functional dependencies and XML keys are also discussed
	// 
	// 	输出样例
	// 	The     relationship
	// 	between          XML
	// 	functional          
	// 	dependencies and XML
	// 	keys are        also
	// 	discussed
/*
超时，还有一点点没有完善的代码。。。
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string str;
string s[101];
int len[101];

void print(int head, int tail)
{
	int sum=0;
	if(tail-head==0)
		cout<<s[tail]<<endl;
	else
	{
		for(int i=head; i<tail; i++)
		{
			cout<<s[i]<<" ";
			sum += len[i]+1;
		}
		sum = 20 - sum - len[tail];
		//cout<<sum;
		while(sum)
		{
			cout<<" ";
			sum--;
		}
		cout<<s[tail]<<endl;
	}
	return;
}

int main()
{
	char c;
	//getchar();
	int i=0, j;
	while(c = getchar())
	{
		
		if(c=='\n')
		{
			s[i] = str;
			len[i] = s[i].length();
			str = "";
			//cout<<"len:"<<len[i]<<endl;
			//cout<<"s[i]:"<<s[i]<<endl;
			//cout<<i<<endl;
			i++;
			break;
		}
		if(c==' ')
		{
			s[i] = str;
			len[i] = s[i].length();
			str = "";
			//cout<<"len:"<<len[i]<<endl;
			//cout<<"s[i]:"<<s[i]<<endl;
			i++;
			continue;
		}
		str = str + c;
		//cout<<"str:"<<str<<endl;
	}
	int num=0,head,tail;
	//cout<<i<<endl;

	for(j=0; j<i; j++)
	{
		cout<<j<<endl;
		if(num==0)
			head = j;
		num +=len[j];
		if(num==20)
		{
			tail = j;
			print(head, tail);
			num = -1;
		}
		if(num>20)
		{

			tail = j;
			print(head, tail-1);
			j--;
			num = -1;
		}
		num++;
	}
	system("pause");
	return 0;
}
*/
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char word[128][21]={'\0'},ch;
	int words = 0,i;	
	int startPos,spaces;
	ch = getchar();
	while(ch!='\n')
	{
		while(ch==' ')
			ch=getchar();
		i=0;
		while((ch!=' ')&&(ch!='\n'))
		{
			word[words][i++] = ch;
			ch=getchar();
		}
		word[words][i] = '\0';
		words++;
	}
	startPos = 0;
	for(i=0; i<words; i++)
	{
		int length=0,curwords=0;
		while(length<20&&i<words)
		{
			length+=strlen(word[i]);
			if(length>20 || length+curwords>20)
			{
				length -=strlen(word[i]);
				break;
			}
			i++,curwords++;
		}
		i--;
		if(curwords>=1)
			spaces=20-length;
		int j=startPos;
		do{
			printf("%s",word[j]);
			putchar(' ');
			spaces--;
		}while(++j<startPos+curwords-1);
		if(curwords>1)
		{
			for(int k=0;k<spaces;k++)
				putchar(' ');
			printf("%s",word[startPos+curwords-1]);
		}
		if(curwords==1)
		{
			for(int k=0;k<spaces;k++)
				putchar(' ');
		}
		putchar('\n');

		startPos += curwords;
	}
	system("pause");
	return 0;
}
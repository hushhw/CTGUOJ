// 17.���¸�ʽ (15��)
	// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
	// 	��Ŀ���ݣ�
	// 	��д����ʵ�ֽ�һ�����¸�ʽ����ӡ��������ӡʱÿ�еĳ���Ϊ20���ַ���
	// 	���һ�е����һ�����ʳ����˱��е�20���ַ��ķ�Χ����Ӧ�����Ƶ���һ�С�
	// 	������ÿ������֮������һ���ո����һ������ǰ�������Ҫ���Ӷ���ո�
	// 	ʹÿ�е�ĩβ׼ȷ�ش��ڵ�20��λ�ô���
	// 	��������
	// 	����n�����ʣ��������룬ÿ�����ʲ��ܳ���20����ĸ�����ʼ��ÿո����������
	// 	Ҫ��Ϊת�У�Ҳ����˵�������ĵ��ʳ���һ��Ҳ��Ҫ��Enter��
	// 
	// 	�������
	// 	������n�����ʷ��д�ӡ��ÿ��20���ַ������һ��ֻ�ܷ�һ�������򵥴ʺ��ÿո���䣬
	// 	��һ�пɷŶ�����ʣ���ĩβ����Ϊ���ʣ���һ�����ʲ��ܿ��������
	// 
	// 	��������
	// 	The relationship between XML functional dependencies and XML keys are also discussed
	// 
	// 	�������
	// 	The     relationship
	// 	between          XML
	// 	functional          
	// 	dependencies and XML
	// 	keys are        also
	// 	discussed
/*
��ʱ������һ���û�����ƵĴ��롣����
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
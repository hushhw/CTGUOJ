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
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	string s[101];
	int len[101];
	char c;
	getchar();
	int i=0;
	while(c = getchar())
	{
		
		if(c=='\n')
		{
			s[i++] = str;
			len[i] = str.length();
			str = "";
			cout<<s[i]<<endl;
			break;
		}
		if(c==' ')
		{
			s[i++] = str;
			len[i] = str.length();
			str = "";
			cout<<s[i]<<endl;
			continue;
		}
		str += c;
	}
	s[i++] = str;
	len[i] = str.length();

	int num = 0;
	for(int j=0; i<i; j++)
	{
		num+=len[i];
		if(num==20)
		{
			int sum = 0;
			for(int m=0; m<=j; m++)
			{
				if(m!=j)
				{
					cout<<"sss"<<endl;
					printf("%s",s[i]);
					sum += len[i]+1;
				}
				else
				{
					int sum = 20 - sum;
					while(sum)
					{
						cout<<" ";
						sum--;
					}
					printf("%s\n",s[i]);
				}
			}
		}
		else if(num>20)
		{
			int sum = 0;
			for(int m=0; m<j; m++)
			{
				if(m!=j-1)
				{
					cout<<"sss"<<endl;
					printf("%s",s[i]);
					sum += len[i]+1;
				}
				else
				{
					int sum = 20 - sum;
					while(sum)
					{
						cout<<" ";
						sum--;
					}
					printf("%s\n",s[i]);
				}
			}
		}	
	}
	system("pause");
	return 0;
}
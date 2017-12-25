// 19.错误票据 (15分)
	// 	C时间限制：1 毫秒 |  C内存限制：3000 Kb
	// 	题目内容：
	// 	某涉密单位下发了某种票据，并要在年终全部收回。
	// 
	// 	每张票据有唯一的ID号。全年所有票据的ID号是连续的，
	// 
	// 	但ID的开始数码是随机选定的。
	// 
	// 	因为工作人员疏忽，在录入ID号的时候发生了一处错误，
	// 
	// 	造成了某个ID断号，另外一个ID重号。
	// 
	// 	你的任务是通过编程，找出断号的ID和重号的ID。
	// 
	// 	假设断号不可能发生在最大和最小号。
	// 
	// 	要求程序首先输入一个整数N(N<100)表示后面数据行数。
	// 	接着读入N行数据。
	// 	每行数据长度不等，是用空格分开的若干个（不大于100个）正整数（不大于100000）
	// 	每个整数代表一个ID号。
	// 
	// 	要求程序输出1行，含两个整数m n，用空格分隔。
	// 	其中，m表示断号ID，n表示重号ID
	// 
	// 	例如：
	// 	用户输入：
	// 	2
	// 	5 6 8 11 9 
	// 	10 12 9
	// 
	// 	则程序输出：
	// 	7 9
	// 
	// 
	// 	再例如：
	// 	用户输入：
	// 	6
	// 	164 178 108 109 180 155 141 159 104 182 179 118 137 184 115 124 125 129 168 196
	// 	172 189 127 107 112 192 103 131 133 169 158 
	// 	128 102 110 148 139 157 140 195 197
	// 	185 152 135 106 123 173 122 136 174 191 145 116 151 143 175 120 161 134 162 190
	// 	149 138 142 146 199 126 165 156 153 193 144 166 170 121 171 132 101 194 187 188
	// 	113 130 176 154 177 120 117 150 114 183 186 181 100 163 160 167 147 198 111 119
	// 
	// 	则程序输出：
	// 	105 120
	// 	输入描述
	// 	要求程序首先输入一个整数N(N<100)表示后面数据行数。
	// 	接着读入N行数据。
	// 	每行数据长度不等，是用空格分开的若干个（不大于100个）正整数（不大于100000）
	// 	每个整数代表一个ID号。
	// 
	// 	输出描述
	// 	要求程序输出1行，含两个整数m n，用空格分隔。
	// 	其中，m表示断号ID，n表示重号ID
	// 
	// 	输入样例
	// 	2
	// 	5 6 8 11 9 
	// 	10 12 9
	// 
	// 	输出样例
	// 	7 9

//此题最重要的是对数据的处理，怎么输入和合理存储
/*
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char ch[1010][10100];
int num[101000];

int main()
{
	int n,k;
	while(scanf("%d",&n)!=EOF)
	{
		k=0;
		getchar();
		for(int i=0; i<n; i++)
		{
			gets(ch[i]);
			int len=0;
			while(ch[i][len]!='\0') len++;
			cout<<len<<endl;
			int a=0;
			while(ch[i][len-1]==' ') len--;
			
			for(int j=0; j<len; j++)
			{
				if(ch[i][j]>='0' && ch[i][j]<='9')
				{
					a=a*10+ch[i][j]-'0';
				}
				if(ch[i][j]==' ' && ch[i][j-1]!=' ')
				{
					num[k++]=a;
					a=0;
				}
			}
			num[k++]=a;
		}
		sort(num,num+k);
		int flag = 0;
		for(int i=1; i<k; i++)
		{
			if(num[i]>num[i-1]+1)
			{
				cout<<num[i]-1<<" ";
			}
		}
		for(int i=1; i<k; i++)
		{
			if(num[i]==num[i-1])
			{
				cout<<num[i]<<endl;
			}
		}
	}
	return 0;
}
*/

//解法二：

// atoi()函数
// 	atoi():int atoi(const char *str );
// 功能：把字符串转换成整型数。
// 	str：要进行转换的字符串
// 	返回值：每个函数返回 int 值，此值由将输入字符作为数字解析而生成。 如果该输入无法转换为该类型的值，则atoi的返回值为 0。
// 	说明：当第一个字符不能识别为数字时，函数将停止读入输入字符串。

//解题思路：
// 因为每行数据都不一样，所以需要根据输入的字符来判断是否输入完毕（当然，也可每行作为一个string，然后进行分割），所以需要使用getchar函数；
// 	这就出现了一个问题，当我们输入123等多个数字组成的数的时候，分3次输入的，所以我们还需要自己想办法合并；
// 	我这里使用的是string来实现的，str一开始是空，当遇到空格之前的数字都是连在一块的，所以我们将他们通过string的+运算符连接到一块；
// 	然后在将这一string通过c_str函数转换为char型，然后通过atoi函数（在cstdlib类库中定义）将这一字符串转化为整数，并插入链表；
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
	list<int> l;
	int row;
	int c;
	int num;
	string str = "";
	cin>>row;
	getchar(); //防止输入行数的回车被识别
	for(int i=0; i<row; i++)
	{
		while(c=getchar())
		{
			if(c==32) //32是空格的ascii码
			{
				num = atoi(str.c_str());	//注意atoi()函数内只能为char型，所以要用到c_str()来转换类型
				l.push_back(num);
				str = "";
				continue; //防止空格被记录在str中
			}
			if(c==10) //10是回车的acsii码
			{
				num = atoi(str.c_str());
				l.push_back(num);
				str = "";
				break;
			}
			str += c;	//用来记录输入的连续的数如：123
		}
	}
	l.sort();
	list<int>::iterator p;
	int m;	//表示断号
	int n;	//表示重号
	for(p=l.begin(); p!=--l.end();)
	{
		int t1 = *p;
		int t2 = *(++p);
		int t3 = t2-t1;
		if(t3==0) n=t1;
		if(t3==2) m=t2-1;
	}
	cout<<m<<" "<<n<<endl;
	return 0;
}
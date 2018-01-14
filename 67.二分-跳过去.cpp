/*
��Ŀ���ݣ�
  ������ȥ����������һ�����н��У����зֲ���һЩ��ʯͷ����ί��ѡ��������ʯͷ��Ϊ���������յ㡣
�������յ�֮�䣬�� N ��ʯͷ������������ �����ʯ��������ʱѡ���ǽ�����������ÿһ������
��һ��ʯͷ��ֱ���յ㡣
Ϊ����߱����Ѷȣ���ί��ƻ�����һЩʯͷ��ʹ��ѡ�����ڱ��������е������Ծ���뾡���ܳ�������
Ԥ�����ƣ���ί������������յ�֮������ M ��ʯͷ���������������յ��ʯͷ����
����������
�����һ�а���3������ L,N��M����ʾ�����յ�ľ��룬֮�����ʯ�����Լ���ί���������ߵ���ʯ����
������ N �У�ÿ��һ���������� i �е�����0<d?[i]<L, ��ʾ�м����ε�ÿ��ʯͷ�����ľ��룬��֤
d[i]<d[i+1]
����L<=10^9, M<N-2<=10^5
���������
�����Ծ��������ֵ
����������
25 5 2
2
11
14
17
21
�������
4
*/ 

/*
����˼·:(��������) 
 ����ȷ�����½�: Low=0, High=L;
 ����ÿһ��mid = Low + (High-Low)/2; ���Խ��䵱����ȷ��,ͳ�������ߵ�ʯͷ����Sum. 
 	���Sum>M,  ˵��midֵ����,��������Ϊ��ȷ��,��Ҫ���Ը�С��midֵ
 	���sum<=M, ˵���϶��и����midֵ������Ϊ��ȷ��,��Ҫ���Ը����midֵ
ʱ�临�Ӷ�: NLog(L)
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#define NMAX 50005
typedef long long LL;
using namespace std;

LL L,N,M;
LL a[NMAX];

bool judge(LL d)
{
	LL sum=0, last=0;
	for(int i=1; i<=N; i++)
	{
		if(a[i] - last <= d)
			sum++;
		else
			last = a[i];
	}
	return sum>M;
}

LL bsearch()
{
	LL low=0, high=L;
	LL mid;
	while(low<high)
	{
		mid = low + (high-low)/2;
		if(judge(mid)) high = mid;
		else low = mid+1;
	}
	return high;
}

int main()
{
	while(cin>>L>>N>>M)
	{
		for(int i=1; i<=N; i++) cin>>a[i];
		a[N+1] = L;
		sort(a+1, a+1+N);
		cout<<bsearch()<<endl;
	}
	return 0;
}
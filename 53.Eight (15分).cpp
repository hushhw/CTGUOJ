// 6.Eight (15��)
	// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
	// 	��Ŀ���ݣ�
	// 	��3*3��������,���а˸�����,ÿ�������ϱ���1��8��ĳһ����.����������һ���ո�,�ո���0����ʾ.�ո���Χ�����ӿ����Ƶ��ո���.Ҫ���������ǣ�����һ�ֳ�ʼ���ֺ�Ŀ�겼��,Ϊ��ʹ��Ŀ��,��Ŀ��״̬Ϊ:
	// 1 2 3
	// 	8 0 4
	// 	7 6 5
	// 	�ҵ�һ�����ٲ�����ƶ�����,ʵ�ִӳ�ʼ���ֵ�Ŀ�겼�ֵ�ת��.
	// 	��������
	// 	�������״̬,3*3�ľŸ�����,�ո���0��ʾ.
	// 
	// 	�������
	// 	ֻ��һ��,����ֻ��һ������,��ʾ�ӳ�ʼ״̬��Ŀ��״̬��Ҫ�������ƶ���
	// 	(���޷�����Ŀ��״̬�����-1).
	// 
	// 	��������
	// 	2 8 3
	// 	1 0 4
	// 	7 6 5
	// 
	// 	�������
	// 	4
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int count=1;

struct node 
{
	int xy[3][3];
	int dir;
};
struct node sh[102];


void init()
{
	printf("������ʼ�ڵ��λ��:\n");
	int i,j;
	for(i=0; i<3; i++)
		for(j=0; j<3; j++)
			scanf("%d", &sh[0].xy[i][j]);
	sh[0].dir = -1;
	printf("����Ŀ��ڵ�λ��:\n");
	for(i=0; i<3; i++)
		for(j=0; j<3; j++)
			scanf("%d", &sh[101].xy[i][j]);
	sh[101].dir = -1;
}

//�ҳ�0��λ��
int loction(int num)
{
	int i;
	for (i = 0; i < 9; i++)
		if (sh[num].xy[i / 3][i % 3] == 0) return i;
}

//���б��
long long sign(int num)
{
	long long  sum;
	sum = sh[num].xy[0][0]*100000000 + sh[num].xy[0][1]*10000000 + sh[num].xy[0][2]*1000000 + sh[num].xy[1][0]*100000 + sh[num].xy[1][1]*10000 + sh[num].xy[1][2]*1000 + sh[num].xy[2][0]*100 + sh[num].xy[2][1]*10 + sh[num].xy[2][2];
	return sum;
}

void mobile(int num)
{
	int temp;
	int loc;
	int up=1,down=1,left=1,right=1;
	loc = loction(num);
	int stand = sh[num].dir;
	//dir��0 1 2 3�ֱ������ �� �� ��
	if (loc / 3 != 0 && stand != 1)
	{
		sh[count] = sh[num];
		temp = sh[count].xy[loc / 3][loc % 3];
		sh[count].xy[loc / 3][loc % 3] = sh[count].xy[loc / 3 - 1][loc % 3];
		sh[count].xy[loc / 3 - 1][loc % 3] = temp;
		sh[count].dir = 3;
		count++;
	};
	if (loc / 3 != 2 && stand != 3)
	{
		sh[count] = sh[num];
		temp = sh[count].xy[loc / 3][loc % 3];
		sh[count].xy[loc / 3][loc % 3] = sh[count].xy[loc / 3 + 1][loc % 3];
		sh[count].xy[loc / 3 + 1][loc % 3] = temp;
		sh[count].dir = 1;
		count++;
	}
	if (loc % 3 != 0 && stand != 0)
	{
		sh[count] = sh[num];
		temp = sh[count].xy[loc / 3][loc % 3];
		sh[count].xy[loc / 3][loc % 3] = sh[count].xy[loc / 3][loc % 3 - 1];
		sh[count].xy[loc / 3][loc % 3 - 1] = temp;
		sh[count].dir = 2;
		count++;
	}
	if (loc % 3 != 2 && stand != 2)
	{
		sh[count] = sh[num];
		temp = sh[count].xy[loc / 3][loc % 3];
		sh[count].xy[loc / 3][loc % 3] = sh[count].xy[loc / 3][loc % 3 + 1];
		sh[count].xy[loc / 3][loc % 3 + 1] = temp;
		sh[count].dir = 0;
		count++;
	}
}

void display(int num)
{
	int i,j;
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
			printf("%d", sh[num].xy[i][j]);
		printf("\n");
	}
}

int search()
{
	int i=0;
	while(1)
	{
		printf("\n");
		display(i);
		printf("\n");
		if(i==100)
		{
			printf("�������޴���\n");
			return 0;
		}
		if(sign(i) == sign(101))
		{
			printf("�ڵ�%d���ҵ���", i);
			display(i);
			return i;
		}
		mobile(i);
		i++;
	}
}

int main()
{
	init();
	search();
	return 0;
}
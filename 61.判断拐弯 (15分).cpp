// 14.�жϹ��� (15��)
	// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
	// 	��Ŀ���ݣ�
	// 	С�����ֻ������������Ⱥ󾭹��������ص�A, B, C������,�������ж�С����B��������䣬�����ҹ���
	// 	��������
	// 	A, B, C������
	// 
	// 	�������
	// 	left  ���� right
	// 
	// 	��������
	// 	0,0
	// 	1,1
	// 	2,1
	// 
	// 	�������
	// 	right

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
	int a1,a2,b1,b2,c1,c2;
	while(~scanf("%d,%d%d,%d%d,%d",&a1,&a2,&b1,&b2,&c1,&c2)){
		double k1 = abs(b2-a2)/abs(b1-a1);
		double k2 = abs(c2-b2)/abs(c1-b1);
		if(k2>k1)
			cout<<"left"<<endl;
		else if(k2<k1)
			cout<<"right"<<endl;
	}
	return 0;
}
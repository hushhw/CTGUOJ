// 4.��ʮ�ĵ� (15��)
	// 	Cʱ�����ƣ�1 ���� |  C�ڴ����ƣ�3000 Kb
	// 	��Ŀ���ݣ�
	// 	��������������4������ͨ�� �ӡ������ˡ������㿴�ܷ�õ� ��� 24��ÿ����ֻ��һ�Ρ�
	// 	��������
	// 	�����ĸ�������
	// 
	// 	�������
	// 	��ͨ��ĳ�ַ�ʽ�õ�24�����1�����������0
	// 
	// 	��������
	// 	6 6 6 6
	// 
	// 	�������
	// 	1

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int w[4] = {0,1,2,3};

int main()
{
	int a[4];
	int i,j,k;
	scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
	sort(a,a+4);
	do{
		for(i=0; i<4; i++)
		{
			for(j=0; j<4; j++)
			{
				for(k=0; k<4; k++)
				{
					int sum=0; 
					switch(w[i])
					{
					case 0:sum = a[0] + a[1];break;
					case 1:sum = a[0] - a[1];break;
					case 2:sum = a[0] * a[1];break;    
					case 3:sum = a[0] / a[1];break;    
					default:break;    
					}
					switch (w[j])
					{
					case 0:sum = sum + a[2];break;    
					case 1:sum = sum - a[2];break;    
					case 2:sum = sum * a[2];break;    
					case 3:sum = sum / a[2];break; 
					default:
						break;
					}
					switch (w[k])
					{
					case 0:sum = sum + a[3];break;    
					case 1:sum = sum - a[3];break;    
					case 2:sum = sum * a[3];break;    
					case 3:sum = sum / a[3];break;
					default:
						break;
					}
					if(sum==24)
					{
						cout<<"1"<<endl;
						//system("pause");
						return 0;
					}
				}
			}
		}
	}while(next_permutation(a,a+4));
	cout<<"0"<<endl;
	//system("pause");
	return 0;
}
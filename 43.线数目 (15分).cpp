// 4.����Ŀ (15��)
	// 	Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
	// 	��Ŀ���ݣ�
	// 	���л��к��ߣ�ֱ�߻����ߣ��İ׵�ͼƬһ�ţ�������ж��������ߡ����������ÿ��������ռ�ĵ�����ͼƬ������0��1ͼ��ʾ��1����ڵ� 0 ����׵㣬ĳ����Χ8����������ͨ������ͼ��ʾ������3�����ߣ����ȷֱ���5��3��5��
	// 	1 0 0 0 0 0 0
	// 	0 1 1 1 1 0 0
	// 	0 0 0 0 0 0 0
	// 	1 1 0 0 0 1 1
	// 	1 0 0 1 1 1 0
	// 	��������
	// 	ͼ�Ŀ�w����h����������ͼ�����ص�.(�������ݽ��Ψһȷ��)
	// 
	// 	�������
	// 	�����������������ÿ���߳���.��������ÿ�����ȸ�ռһ�У�.
	// 
	// 	��������
	// 	7 5 
	// 	1 0 0 0 0 0 0
	// 	0 1 1 1 1 0 0
	// 	0 0 0 0 0 0 0
	// 	1 1 0 0 0 1 1
	// 	1 0 0 1 1 1 0
	// 
	// 	�������
	// 	3
	// 	5
	// 	3
	// 	5

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int map[100][100];
int value[20];
int w,h;
int find(int i,int j){
	if(map[i][j]==1){
		map[i][j]=0;
		return find(i-1,j-1)+find(i-1,j)+
			find(i-1,j+1)+find(i,j-1)+
			find(i,j+1)+find(i+1,j-1)+
			find(i+1,j)+find(i+1,j+1)+1;
	}else{
		return 0;
	}
}

int main(){
	int count=0;
	memset(map,0,sizeof(map));//ȫ����ֵΪ��
	memset(value,0,sizeof(value));
	cin>>w>>h;
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			cin>>map[i][j];
	int k=0;
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
		{

			int sum=find(i,j);
			if(sum!=0){
				count++;
				value[k++]=sum;
			}
		}

		cout<<count<<endl;
		for(int i=0;i<count;i++)
			cout<<value[i]<<endl;        
		return 0;
}
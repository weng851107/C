#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INDEXBOX 10    /*�����̤j����*/
#define MAXNUM 7       /*�̤j��ƭӼ�*/

int main()
{  
	int i,index[INDEXBOX],data[MAXNUM];
	srand((unsigned)time(NULL));     /*�̮ɶ���l�ü�*/
	printf("��l�}�C�ȡG\n");
	for(i=0;i<MAXNUM;i++)       /*�_�l��ƭ�*/
		data[i]=rand()%20+1;
	for(i=0;i<INDEXBOX;i++)     /*�M�������*/
		index[i]=-1;
	print_data(data,MAXNUM);    /*�C�L�_�l���*/
	printf("������e�G\n");
	for(i=0;i<MAXNUM;i++)       /*�إ������*/
	{  
		creat_table(data[i],index);
		printf("  %2d =>",data[i]);  /*�C�L��@������������m*/
		print_data(index,INDEXBOX);
	}
	printf("���������G\n");     
	print_data(index,INDEXBOX);  /*�C�L�̫᧹�����G*/
	system("pause");
	return 0;
}
int print_data(int *data,int max)  /*�C�L�}�C�Ƶ{��*/
{  
	int i;
	printf("\t");
	for(i=0;i<max;i++)
		printf("[%2d] ",data[i]);
	printf("\n");
}
int creat_table(int num,int *index)  /*�إ������Ƶ{��*/
{  
	int tmp;
	tmp=num%INDEXBOX;    /*������=���%INDEXBOX*/
	while(1)
	{  
		if(index[tmp]==-1)      /*�p�G��ƹ�������m�O�Ū�*/
		{  
			index[tmp]=num;     /*�h�����s�J���*/
			break;
		}
		else
			tmp=(tmp+1)%INDEXBOX;    /*�_�h������m�s��*/
	}
}

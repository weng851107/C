#include <stdio.h>
#include <stdlib.h>

void Btree_create(int *btree,int *data,int length)
{
	int i,level;
	
    for(i=1;i<length;i++) /*���l�}�C�����ȳv�@���*/
	{  
		for(level=1;btree[level]!=0;)/*�����ڤΰ}�C������*/
		{  
			if(data[i]>btree[level]) /*�p�G�}�C�����Ȥj���ڡA�h���k�l����*/
				level=level*2+1;
			else /*�p�G�}�C�����Ȥp��ε����ڡA�h�����l����*/
				level=level*2;
		}        /*�p�G�l��`�I���Ȥ���0�A�h�A�P�}�C�����Ȥ���@��*/
		btree[level]=data[i]; /*��}�C�ȩ�J�G����*/
	}
}
int main()
{  
	int i,length=9;
	int data[]={0,6,3,5,4,7,8,9,2};/*��l�}�C*/
	int btree[16]={0}; /*�s��G����}�C*/
	printf("��l�}�C���e�G\n");	
	for(i=0;i<length;i++)
		printf("[%2d] ",data[i]);
	printf("\n");
	Btree_create(btree,data,9);
	printf("�G���𤺮e�G\n");
	for (i=1;i<16;i++)
		printf("[%2d] ",btree[i]);
	printf("\n");
	system("pause");
	return 0;
}

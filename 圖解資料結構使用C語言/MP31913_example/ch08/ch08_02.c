/*
[�W��]:ch08_02.c
[�ܽd]:��}��w�ƧǪk
*/
#include <stdio.h>
void bubble (int *);   /*�ŧi��w�ƧǰƵ{��*/
void showdata (int *); /*�ŧi�C�L�}�C�Ƶ{��*/
int main(void)
{
	int data[6]={4,6,2,7,8,9};	  /*��l���*/
	printf("��}��w�ƧǪk\n��l��Ƭ��G");
	showdata (data);
	bubble (data);
	system("pause");
	return 0;
}
void showdata (int data[])     /*�Q�ΰj��C�L���*/
{
	int i;
	for (i=0;i<6;i++)
		printf("%3d",data[i]);
	printf("\n");
}
void bubble (int data[])
{
	int i,j,tmp,flag;
	for(i=5;i>=0;i--)
	{
		flag=0;           /*flag�ΨӧP�_�O�_������洫���ʧ@*/
		for (j=0;j<i;j++)
		{
			if (data[j+1]<data[j])
			{
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
				flag++;    /*�p�G������L�洫�A�hflag����0*/
			}
		}
		if (flag==0)
			break;
		/*
		����槹�@�����y�N�P�_�O�_���L�洫�ʧ@�A�p�G�S���洫�L���
		�A��ܦ��ɰ}�C�w�����ƧǡA�G�i�������X�j��
		*/
		printf("�� %d ���ƧǡG",6-i);
		for (j=0;j<6;j++)
			printf("%3d",data[j]);
		printf("\n");		    
	}
	printf("�Ƨǫᵲ�G���G");
	showdata (data);
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j,tmp;
	int data[8]={16,25,39,27,12,8,45,63};	/* ��l��� */
	printf("��w�ƧǪk�G\n��l��Ƭ��G");
	for (i=0;i<8;i++)
		printf("%3d",data[i]);
	printf("\n");

	for (i=7;i>=0;i--)		/* ���˦��� */
	{
		for (j=0;j<i;j++)/*����B�洫����*/
		{
			if (data[j]>data[j+1])	/* ����۾F��ơA�p�Ĥ@�Ƹ��j�h�洫 */
			{
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
			}
		}
		printf("�� %d ���Ƨǫ᪺���G�O�G",8-i); /*��U�����y�᪺���G�L�X*/
		for (j=0;j<8;j++)
			printf("%3d",data[j]);
		printf("\n");
	}
	printf("�Ƨǫᵲ�G���G");
	for (i=0;i<8;i++)
		printf("%3d",data[i]);
	printf("\n");
	
    system("pause");
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#define SIZE 8        /*�w�q�}�C�j�p*/
void inser (int *);     /*�ŧi���J�ƧǪk�Ƶ{��*/
void showdata (int *);  /*�ŧi�C�L�}�C�Ƶ{��*/

int main()
{ 
	int data[SIZE]={16,25,39,27,12,8,45,63};
	
	printf("��l�}�C�O�G");
	showdata(data);
	printf("\n");
	inser(data);
	printf("�Ƨǫ�}�C�O�G");
	showdata(data);
	
	
    system("pause");
	return 0;
}

void showdata(int data[])
{  
	int i;
	for (i=0;i<SIZE;i++)
		printf("%3d",data[i]);   /*�C�L�}�C���*/
	printf("\n");
}
void inser(int data[])
{  
	int i;     /*i�����y����*/
	int no;     /*�Hj�өw����������*/
	int tmp;   /*tmp�ΨӼȦs���*/
	for (i=1;i<SIZE;i++)  /*���y�j�馸�Ƭ�SIZE-1*/
	{  
	 tmp=data[i];
     no=i-1;
     while (no>=0 && tmp<data[no]) /*�p�G�ĤG�����p��Ĥ@����*/
	{							 
			data[no+1]=data[no];		/*�N��Ҧ�����������@�Ӧ�m*/		
			no--;
	} 
	 data[no+1]=tmp;              /*�̤p���������Ĥ@�Ӥ���*/	
	}
}

#include <stdio.h>
#include <stdlib.h>
#define SIZE 8           

void shell (int *,int);   /*�ŧi�ƧǪk�Ƶ{��*/
void showdata (int *);   /*�ŧi�C�L�}�C�Ƶ{��*/

int main(void)
{ 
	int data[SIZE]={16,25,39,27,12,8,45,63};
	printf("��l�}�C�O�G     ");	
	showdata (data);
	printf("-----------------------------------------\n");
	shell(data,SIZE);
	
    system("pause");
	return 0;
}

void showdata(int data[])
{  
	int i;
	for (i=0;i<SIZE;i++)
		printf("%3d",data[i]);
	printf("\n");
}
void shell(int data[],int size)
{  
	int i;        /*i�����y����*/
	int j;        /*�Hj�өw����������*/
	int k=1;      /*k�C�L�p��*/
	int tmp;      /*tmp�ΨӼȦs���*/
	int jmp;      /*�]�w���Z�첾�q*/
	jmp=size/2;
	while (jmp != 0)
	{  
		for (i=jmp ;i<size ;i++)
		{  
			tmp=data[i];
			j=i-jmp;
			while(tmp<data[j] && j>=0)  /*���J�ƧǪk*/
			{  
				data[j+jmp] = data[j];
				j=j-jmp;
			}	
			data[jmp+j]=tmp;
		}
		printf("�� %d ���ƧǹL�{�G",k++);
		showdata (data);
		printf("-----------------------------------------\n");
		jmp=jmp/2;    /*����j���*/
	}
}

/* ��ƱƧǪk �Ѥp��j�Ƨ� */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void radix (int *,int);/* ��ƱƧǪk�Ƶ{�� */
void showdata (int *,int);
void inputarr (int *,int);
int main(void)
{ 
	int size,data[100]={0};
	printf("�п�J�}�C�j�p(100�H�U)�G");
	scanf("%d",&size);
	printf("�z��J����l��ƬO�G\n");
	inputarr (data,size);
	showdata (data,size);
	radix (data,size);
	system("pause");
	return 0;
}
void inputarr(int data[],int size)
{
	int i;
	srand((unsigned)time(NULL));
	for (i=0;i<size;i++)
		data[i]=(rand()%999)+1;/*�]�wdata�ȳ̤j��3���*/
}
void showdata(int data[],int size)
{  
	int i;
	for (i=0;i<size;i++)
		printf("%5d",data[i]);
	printf("\n");
}
void radix(int data[],int size)
{  
	int i,j,k,n,m;
	for (n=1;n<=100;n=n*10)/*n����ơA�ѭӦ�ƶ}�l�Ƨ� */
	{  
		int tmp[10][100]={0};/* �]�w�Ȧs�}�C�A[0~9���][��ƭӼ�]�A�Ҧ����e����0 */
		for (i=0;i<size;i++)/* ���Ҧ���� */
		{  
			m=(data[i]/n)%10;/* m��n��ƪ��ȡA�p 36���Q��� (36/10)%10=3 */
			tmp[m][i]=data[i];/* ��data[i]���ȼȦs��tmp �� */
		}
		k=0;
		for (i=0;i<10;i++)
		{  
			for(j=0;j<size;j++)
			{  
				if(tmp[i][j] != 0)	/* �]�@�}�l�]�w tmp ={0}�A�G����0�̧Y�� */
				{  
					data[k]=tmp[i][j];/* data�Ȧs�b tmp �̪��ȡA��tmp �̪��ȩ� */
					k++;		      /* �^data[ ]�� */
				}
			}
		}
		printf("�g�L%3d��ƱƧǫ�G",n);
		showdata(data,size);
	}
  
}

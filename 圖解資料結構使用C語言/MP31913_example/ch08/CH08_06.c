#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inputarr(int*,int);
void showdata(int*,int);
void quick(int*,int,int,int);
int process = 0;
int main(void)
{
	int size,data[100]={0};
	srand((unsigned)time(NULL));
	printf("�п�J�}�C�j�p(100�H�U)�G");
	scanf("%d",&size);
	printf("�z��J����l��ƬO�G");
	inputarr (data,size);
	showdata (data,size);
	quick(data,size,0,9);
	printf("\n�Ƨǵ��G�G");
	showdata(data,size);
	system("pause");
	return 0;
}
void inputarr(int data[],int size)
{
	int i;
	for (i=0;i<size;i++)
		data[i]=(rand()%99)+1;
}
void showdata(int data[],int size)
{  
	int i;
	for (i=0;i<size;i++)
		printf("%3d",data[i]);
	printf("\n");

}
void quick(int d[],int size,int lf,int rg)
{
	int i,j,tmp;
	int lf_idx;
	int rg_idx;
	int t;
                                         /*1:�Ĥ@����Ȭ�d[lf]*/
	if(lf<rg)
	{
		lf_idx=lf+1;
		rg_idx=rg;
step2:
		printf("[�B�z�L�{%d]=> ",process++);
		for(t=0;t<size;t++)
			printf("[%2d] ",d[t]);
		printf("\n");
		for(i=lf+1;i<=rg;i++)          /*2:�ѥ��V�k��X�@����Ȥj��d[lf]��*/
		{
			
			
			if(d[i]>=d[lf])
			{
				lf_idx=i;
				break;
			}
			lf_idx++;
		}
		for(j=rg;j>=lf+1;j--)          /*3:�ѥk�V����X�@����Ȥp��d[lf]��*/
		{
			
			
			if(d[j]<=d[lf]) 
			{
				rg_idx=j;
				break;
			}
			rg_idx--;
		}
		if(lf_idx<rg_idx)                 /*4-1:�Ylf_idx<rg_idx*/
		{								  /*�hd[lf_idx]�Md[rg_idx]����*/
			tmp = d[lf_idx];
			d[lf_idx] = d[rg_idx];
			d[rg_idx] = tmp;
			goto step2;                   /*4-2:���~�����B�J2*/
		}
		if(lf_idx>=rg_idx)                 /*5-1:�Ylf_idx�j�󵥩�rg_idx*/
		{                                  /*�h�Nd[lf]�Md[rg_idx]����*/
			tmp = d[lf];
			d[lf] = d[rg_idx];
			d[rg_idx] = tmp;
			                               /*5-2:�åHrg_idx������I�������k��b*/
			quick(d,size,lf,rg_idx-1);	   /*�H���j�覡���O�����k��b�i��Ƨ�*/
			quick(d,size,rg_idx+1,rg);     /*���ܧ����Ƨ�*/
		}
	}
}

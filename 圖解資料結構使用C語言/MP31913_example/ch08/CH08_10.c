#include <stdio.h>
#include <stdlib.h>

void merge (FILE *,FILE *,FILE *);/*�ŧi�X�ֱƧǰƵ{��*/
void me (FILE *,FILE *,FILE *,FILE *);/*�ŧi�����ɮװƵ{��*/
void bubble(FILE *,int);/*�w�����ɮפ��A�H��w�ƧǪk�i�椺���Ƨ�*/
void showdata(FILE *); /*�L�X�ɮפ��e*/
int main(void)
{  
	char n;
	FILE *fp=fopen("datafile.txt","r");/*�ŧi�ɮ׫���*/
	FILE *fp1=fopen("sortdata.txt","w+");
	FILE *ff1=fopen("sort1.txt","w+");
	FILE *ff2=fopen("sort2.txt","w+");

	if(fp==NULL)/*�ɮ׬O�_�}�Ҧ��\*/
		printf("�}�ҭ����ɥ���\n");
	else if(fp1==NULL)
       	printf("�}�ҦX�֫��ɮץ���\n");
	else if(ff1==NULL)
        printf("�}�Ҥ����� 1 ����\n");
	else if(ff2==NULL)
        printf("�}�Ҥ��ή� 2 ����\n");
	else
	{  
		printf("�ɮפ��Τ�......\n");
        me(fp,fp1,ff1,ff2);
		printf("�ɮױƧǤ�......\n");
		printf("��ƳB�z����!!\n");
	}

	rewind(fp); /*���]�U�ɮ׫���*/
	rewind(fp1);
	rewind(ff1);
	rewind(ff2);
    /*�C�L�ɮפ��e*/
	printf("��l��datafile.txt��Ƥ��e���G\n");
	showdata(fp);
	printf("\n������sort1.txt��Ƥ��e���G\n");
	showdata(ff1);
	printf("\n������sort2.txt��Ƥ��e���G\n");
	showdata(ff2);
	printf("\n�Ƨǫ�sortdata.txt��Ƥ��e���G\n");

	showdata(fp1);

	fclose(fp);/*�����ɮ�*/
	fclose(fp1);
	fclose(ff1);
	fclose(ff2);
	system("pause");
	return 0;
}
void me(FILE *fp,FILE *fp1,FILE *ff1,FILE *ff2)
{  
	int n1=0,n2=0;
	char da1,da2;
	while(1)
	{                          
		da1=getc(fp);
		if(feof(fp)) break;
		n1++;/*�p�ơAn1��datafile���`����*/
	}

	rewind(fp);
	for(n2=0;n2<(n1/2);n2++)
	{  
		da2=getc(fp);/*��@�b���ɮ�*/
	    putc(da2,ff1);/*���Ψ�ff1�h*/
	}
	rewind(ff1);
    bubble(ff1,n2);/*���Χ���I�sbubble�Ƶ{���i��Ƨ�*/

	while(1)
	{  
		da2=getc(fp);/*���L��datafile�ɮ�*/
	    if(feof(fp)) break;
			putc(da2,ff2);/*���e���Ψ�ff2�h*/
	}
	rewind(ff2);
	bubble(ff2,(n1/2));/*���Χ���I�sbubble�Ƶ{���i��Ƨ�*/

	rewind(ff1);
	rewind(ff2);
	merge(fp1,ff1,ff2);/*�I�s�X�ֱƧǰƵ{��*/
}
void merge(FILE *fp, FILE *fp1, FILE *fp2)
{  
	char n1,n2;	/*�ŧi�ܼ�n1�An2�Ȧs�����data1��data2����������*/
	n1=getc(fp1);/*�qfp1�����@�Ӥ����i�ӡA�s�bn1*/
	n2=getc(fp2);
	while(feof(fp1)==0 && feof(fp2)==0)	/*�P�_�O�_�w���ɧ�*/
	{  
		if (n1 <= n2)
		{  
			putc(n1,fp);/*�p�Gn1����p�A�h��n1�s��fp��*/
			n1=getc(fp1);/*����Ū�U�@�� n1 �����*/
		}
		else
		{  
			putc(n2,fp);/*�p�Gn2����p�A�h��n2�s��fp��*/
			n2=getc(fp2);/*����Ū�U�@�� n2�����*/
		}
	}
	if(feof(fp1))/*�p�G�䤤�@�Ӹ���ɤwŪ�������A�g�P�_��*/
	{ 
		putc(n2,fp);/*��t�@�Ӹ���ɤ�����ƥ������ fp ��*/
		while (1)
		{  
			n2=getc(fp2);
			if(feof(fp2)) break;
			putc(n2,fp);
		}
	}
	else if (feof(fp2))
	{ 
		putc(n1,fp);
		while (feof(fp1))
		{  
			n1=getc(fp1);
			putc(n1,fp);
		}
	}	 
}
void bubble (FILE *ff,int size)
{
	int ii=0,j,i,tmp,flag;
	char n;
	char data[100]={0};
	for(i=0;i<size;i++)
	{  
		n=getc(ff);
		if(feof(ff)) break;
		data[i]=n;
		ii++;
	}
	for(i=size;i>0;i--)
	{  
		flag=0;/*flag�ΨӧP�_�O�_������洫���ʧ@*/
		for (j=0;j<i;j++)
		{  
			if(data[j+1]<data[j])
			{  
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
				flag++;
			}/*�p�G������L�洫�A�hflag����0*/
		}
		if(flag==0)break;
	}
	rewind(ff);
	for(i=1;i<=size;i++)
		putc(data[i],ff);
}
void showdata (FILE *ff)
{   
	char n;
	while(1)
	{  
		n=getc(ff);
		if(feof(ff)) break;
			printf("[%c]",n);
	}
	printf("\n");
}

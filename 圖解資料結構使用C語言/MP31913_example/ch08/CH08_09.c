#include <stdio.h>
#include <stdlib.h>

void merge(FILE *fp, FILE *fp1, FILE *fp2)
{  
	int n1,n2;/*�ŧi�ܼ�n1�An2�Ȧs�����data1��data2����������*/
	n1=getc(fp1);/*�qfp1�����@�Ӥ����i�ӡA�s�bn1*/
	n2=getc(fp2);
	while(feof(fp1)==0 && feof(fp2)==0)/*�P�_�O�_�w���ɧ�*/
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
		putc(n2,fp);/*��t�@�Ӹ���ɤ�����ƥ������fp��*/
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
		while(feof(fp1))
		{  
			n1=getc(fp1);
			putc(n1,fp);
		}
	}	 
}

int main(void)
{  
	char n;
	FILE *fp=fopen("data.txt","w+");/*�ŧi�B�ö}�ҫإ߷s�ɥD�ɫ��� fp*/
	FILE *fp1=fopen("data1.txt","r");/*�ŧi�����1���� fp1*/
	FILE *fp2=fopen("data2.txt","r");/*�ŧi�����2���� fp2*/
	FILE *f,*f1,*f2;
	if(fp==NULL)
		printf("�}�ҥD�ɥ���\n");
	else if(fp1==NULL)
		printf("�}�Ҹ���� 1 ����\n");/*�}���ɮצ��\�ɡA���з|�Ǧ^FILE�ɮ�*/
	else if(fp2==NULL)/*���СA�}�ҥ��ѫh�Ǧ^NULL��*/
		printf("�}�Ҹ���� 2 ����\n");
	else
	{  
		printf("��ƱƧǤ�......\n");
        merge(fp,fp1,fp2);
		printf("��ƳB�z����!!\n");
	}
	fclose(fp);	/*�����ɮ�*/
	fclose(fp1);
	fclose(fp2);

	printf("data1.txt��Ƥ��e���G\n");
	f1=fopen("data1.txt","r");
	while(1)
	{  
		n=getc(f1);
		if(feof(f1)) break;
			printf("[%c] ",n);
	}
	printf("\n");
	printf("data2.txt��Ƥ��e���G\n");
	f2=fopen("data2.txt","r");
	while(1)
	{  
		n=getc(f2);
		if(feof(f2)) break;
			printf("[%c] ",n);
	}
	printf("\n");
	printf("�Ƨǫ�data.txt��Ƥ��e���G\n");
	f=fopen("data.txt","r");
	while(1)
	{  
		n=getc(f);
		if(feof(f)) break;
		printf("[%c] ",n);
	}
	printf("\n");
	printf("\n");
	fclose(f);	/*�����ɮ�*/
	fclose(f1);
	fclose(f2);
	system("pause");
	return 0;
}

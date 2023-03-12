#include <stdio.h>
#include <stdlib.h>

struct list              /*�ŧi��C���c*/
{  
	int coef,exp;
	struct list *next;
};
typedef struct list node;
typedef node *link;

link creat_link(int data[4]);
void print_link(link head);
link sum_link(link a,link b);

int main()
{  
	link a,b,c;
	int data1[4]={3,0,4,2};         /*�h����A���Y��*/
	int data2[4]={6,8,6,9};         /*�h����B���Y��*/
	printf("��l�h�����G\nA=");
	a=creat_link(data1);            /*�إߦh����A*/
	b=creat_link(data2);            /*�إߦh����B*/
	print_link(a);                  /*�C�L�h����A*/
	printf("B=");
	print_link(b);                  /*�C�L�h����B*/
	printf("�h�����ۥ[���G�G\nC=");
	c=sum_link(a,b);                /*C��A�BB�h�����ۥ[���G*/
	print_link(c);                  /*�C�L�h����C*/
	system("pause");
	return 0;
}
link creat_link(int data[4]) /*�إߦh�����Ƶ{��*/
{  
	int i;
	link head,newnode,ptr;
	for(i=0;i<4;i++)
	{  
		newnode=(link)malloc(sizeof(node));
		if(!newnode)
		{  
			printf("Error!! �O����t�m����!!\n");
			exit(i);
		}
		if(i==0)
		{  
			newnode->coef=data[i];
			newnode->exp=3-i;
			newnode->next=NULL;
			head=newnode;
			ptr=head;
		}
		else if(data[i]!=0)
		{  
			newnode->coef=data[i];
			newnode->exp=3-i;
			newnode->next=NULL;
			ptr->next=newnode;
			ptr=newnode;
		}
	}
	return head;
}
void print_link(link head)     /*�C�L�h�����Ƶ{��*/
{  
	while(head!=NULL) 
	{  
		if(head->exp==1 && head->coef!=0)  /*X^1�ɤ���ܫ���*/
			printf("%dX + ",head->coef);
		else if(head->exp!=0 && head->coef!=0)
			printf("%dX^%d + ",head->coef,head->exp);
		else if(head->coef!=0) /*X^0�ɤ�����ܼ�*/
			printf("%d",head->coef);
		head=head->next;
	}
	printf("\n");
}
link sum_link(link a,link b)  /*�h�����ۥ[�Ƶ{��*/
{  
	int sum[4],i=0;
	link ptr;
	ptr=b;
	while(a!=NULL)   /*�P�_�h����1*/
	{  
		b=ptr;       /*���Ƥ��A��B������*/
		while(b!=NULL)
		{  
			if(a->exp==b->exp)  /*���Ƭ۵��A�Y�Ƭۥ[*/
			{  
				sum[i]=a->coef+b->coef;
				a=a->next;
				b=b->next;
				i++;
			}
			else if(b->exp > a->exp) /*B���Ƹ��j�A���w�Y�Ƶ�C*/
			{  
				sum[i]=b->coef;
				b=b->next;
				i++;
			}
			else if(a->exp > b->exp) /*A���Ƹ��j�A���w�Y�Ƶ�C*/
			{  
				sum[i]=a->coef;
				a=a->next;
				i++;
			}
		}
	}
	return creat_link(sum);     /*�إ߬ۥ[���G��CC*/
}

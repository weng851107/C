#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct list   /*�ŧi��C���c*/
{  
	int num,score;
	struct list *next;
};
typedef struct list node;
typedef node *link;
link creat_link(int data[10][2],int num);
void print_link(link head);
link concat(link ptr1,link ptr2);
int main()
{  
	link ptr1,ptr2,ptr;
	int i,data1[6][2],data2[6][2];
	srand((unsigned)time(NULL));
	for (i=1;i<=6;i++)
	{  
		data1[i-1][0]=i*2-1;
		data1[i-1][1]=rand()%49+52;
		data2[i-1][0]=i*2;
		data2[i-1][1]=rand()%49+52;
	}
	ptr1=creat_link(data1,6);   /*�إߦ�C1*/
	ptr2=creat_link(data2,6);   /*�إߦ�C2*/
	i=0;
	printf("\t\t    �� �l �� �C �� �ơG\n");
	printf("\t     �y�� ���Z   �y�� ���Z   �y�� ���Z\n");
	printf("\t    ==================================\n");
	printf("   ��C 1 �G");
	print_link(ptr1);
	printf("   ��C 2 �G");
	print_link(ptr2);
	printf("\t    ==================================\n");
	printf("�s�����C�G");
	ptr=concat(ptr1,ptr2);    /*�s����C*/
	print_link(ptr);
	system("pause");
	return 0;
}
link creat_link(int data[10][2],int num) /*�إߦ�C�Ƶ{��*/
{  
	int i;
	link head,ptr,newnode;
	for(i=0;i<num;i++)
	{  
		newnode=(link)malloc(sizeof(node));
		if(!newnode)
		{  
			printf("Error!! �O����t�m����!!\n");
			exit(i);
		}
		if(i==0)  /*�إߦ�C��*/
		{  
			newnode->num=data[i][0];
			newnode->score=data[i][1];
			newnode->next=NULL;
			head=newnode;
			ptr=head;
		}
		else       /*�إߦ�C��L�`�I*/
		{  
			newnode->num=data[i][0];
			newnode->score=data[i][1];
			newnode->next=NULL;
			ptr->next=newnode;
			ptr=newnode;
		}
		newnode->next=head;
	}
	return ptr;    /*�^�Ǧ�C*/
}
void print_link(link head) /*�C�L��C�Ƶ{��*/
{  
	link ptr;
	int i=0;
	ptr=head->next;
	do 
	{  
		printf("[%2d-%3d] -> ",ptr->num,ptr->score);
		i++;
		if(i>=3)            /*�C��C�L�T�Ӥ���*/
		{  
			printf("\n\t    ");
			i=0;
		}
		ptr=ptr->next;
	}while(ptr!=head->next);
	printf("\n");
}
link concat(link ptr1,link ptr2) /*�s����C�Ƶ{��*/
{  
	link head;
	head=ptr1->next;   /*�bptr1��ptr2���A�U����N�@�Ӹ`�I*/
	ptr1->next=ptr2->next;  /*���Ӹ`�I��next��էY�i*/
	ptr2->next=head;
	return ptr2;
}

#include <stdio.h>
#include <stdlib.h>

struct list
{  int val;
   struct list *next;
};
typedef struct list node;
typedef node *link;
struct list head[6];       /*�ŧi�@�Ӹ`�I���A�}�C*/
int main()
{  
	link ptr,newnode;
	char data[14][2]={{1,2},{2,1},{2,5},{5,2},     /*�ϧΰ}�C�ŧi*/
					{2,3},{3,2},{2,4},{4,2},
					{3,4},{4,3},{3,5},{5,3},
					{4,5},{5,4}};
	int i,j;
	printf("�ϧΪ��F����C���e�G\n");
	printf("----------------------------------\n");
	for (i=1;i<6;i++)
	{  
		head[i].val=i;         /*��C��head*/
		head[i].next=NULL;
		printf("���I %d =>",i);  /*�⳻�I�ȦC�L�X��*/
		ptr=&(head[i]);          /*�Ȧs�`�Iptr*/
		for (j=0;j<14;j++)       /*���X�ϧΰ}�C*/
		{  
			if (data[j][0]==i)    /*�p�G�`�I��=i�A�[�J�`�I���C��*/
			{  
				newnode=(link)malloc(sizeof(node));
				newnode->val=data[j][1];        /*�ŧi�s�`�I�A�Ȭ����I��*/
				newnode->next=NULL;
				while(ptr!=NULL)                /*�P�_�O�_����C������*/
					ptr=ptr->next;
				ptr=newnode;                   /*�[�J�s�`�I*/
				printf("[%c] ",64+newnode->val);  /*�C�L�۾F���I*/
			}
		}   
		printf("\n");
	}
	system("pause");
	return 0;
}

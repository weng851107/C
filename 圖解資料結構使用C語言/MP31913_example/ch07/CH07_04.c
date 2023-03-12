#include <stdio.h>
#include <stdlib.h>

struct list
{  
	int val;
    struct list *next;
};
typedef struct list node;
typedef node *link;
struct list* head[9];
int run[9];

void dfs(int current)                  /*�`���u�����*/
{  
	link ptr;
	run[current]=1;
	printf("[%d] ",current);
	ptr=head[current]->next;
	while(ptr!=NULL)
	{		
		if (run[ptr->val]==0)        /*�p�G���I�|�����X�A*/
			dfs(ptr->val);           /*�N�i��dfs�����j�I�s*/
		ptr=ptr->next;
	}
}
int main()
{  
	link ptr,newnode;
	int data[20][2]={{1,2},{2,1},{1,3},{3,1},   /*�ϧ���u�}�C�ŧi*/
					{2,4},{4,2},{2,5},{5,2},
					{3,6},{6,3},{3,7},{7,3},
					{4,8},{8,4},{5,8},{8,5},{6,8},{8,6},{8,7},{7,8}};
	int i,j;

	for (i=1;i<=8;i++)                        /*�@���K�ӳ��I*/
	{  
		run[i]=0;                             /*�]�w�Ҧ����I���|�����X�L*/
		head[i]=(link)malloc(sizeof(node));   
		head[i]->val=i;                       /*�]�w�U�Ӧ�C�������*/
		head[i]->next=NULL;
		ptr=head[i];                          /*�]�w���Ь���C��*/
		for(j=0;j<20;j++)                     /*�G�Q����u*/
		{  
			if(data[j][0]==i)                 /*�p�G�_�I�M��C���۵��A�h�⳻�I�[�J��C*/
			{  
				newnode=(link)malloc(sizeof(node));
				newnode->val=data[j][1];
				newnode->next=NULL;
				do
				{
					ptr->next=newnode;        /*�[�J�s�`�I*/
					ptr=ptr->next;
				}while(ptr->next!=NULL);
			}
		} 
	}
	printf("�ϧΪ��F����C���e�G\n");      /*�C�L�ϧΪ��F����C���e*/
	for(i=1;i<=8;i++)
	{
		ptr=head[i];
		printf("���I %d=> ",i);
		ptr = ptr->next;
		while(ptr!=NULL)
		{
			printf("[%d] ",ptr->val);
			ptr=ptr->next;
		}
		printf("\n");
	}

	printf("�`���u�����X���I�G\n");      /*�C�L�`���u�����X�����I*/
	dfs(1);
	printf("\n");
	system("pause");
	return 0;
}


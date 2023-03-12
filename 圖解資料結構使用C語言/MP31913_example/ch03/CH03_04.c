#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct employee
{  
	int num,score;
	char name[10];
	struct employee *next;
};
typedef struct employee node;
typedef node *link;
link del_ptr(link head,link ptr);
int main()
{  
	link head,ptr,newnode;
	int i,j,find;
	int findword=0;
	char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"},{"John"},{"Mark"},{"Ricky"},{"Lisa"},{"Jasica"},{"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
	int data[12][2]={ 1001,32367,1002,24388,1003,27556,1007,31299,
    1012,42660,1014,25676,1018,44145,1043,52182,1031,32769,1037,21100,1041,32196,1046,25776};
    printf("���u�s�� �~�� ���u�s�� �~�� ���u�s�� �~�� ���u�s�� �~��\n");
	printf("-------------------------------------------------------\n");

	for(i=0;i<3;i++)
	{  
		for (j=0;j<4;j++)
			printf("%2d  [%3d]  ",data[j*3+i][0],data[j*3+i][1]);
		printf("\n");
	}
	head=(link)malloc(sizeof(node));     /*�إߦ�C��*/
	if(!head)
	{  
		printf("Error!! �O����t�m����!!\n");
		exit(1);
	}
	head->num=data[0][0];
	strcpy(head->name,namedata[0]);
	head->score=data[0][1];
	head->next=NULL;
	
    ptr=head;
	for(i=1;i<12;i++)                   /*�إߦ�C*/
	{  
		newnode=(link)malloc(sizeof(node));
		newnode->num=data[i][0];
		strcpy(newnode->name,namedata[i]);
		newnode->score=data[i][1];
		newnode->num=data[i][0];
		newnode->next=NULL;
		ptr->next=newnode;
		ptr=ptr->next;
	}
	while(1)
	{  
		printf("\n�п�J�n�R�������u�s��,�n�����R���L�{,�п�J-1�G");
		scanf("%d",&findword);
		if(findword==-1)             /*�j�餤�_����*/
			break;
		else
		{  
			ptr=head;
			find=0;
			while (ptr!=NULL)
			{  
				if(ptr->num==findword)     
				{                       
					ptr=del_ptr(head,ptr);    
					find++;
					head=ptr;
					break;
				}
				ptr=ptr->next;
			}
			if(find==0)
			printf("######�S�����######\n");
		}
	}
	ptr=head;
	printf("\n\t�y��\t    �m�W\t���Z\n");          /*�C�L�Ѿl��C���*/
	printf("\t==============================\n");
	while(ptr!=NULL)
	{  
		printf("\t[%2d]\t[ %-10s]\t[%3d]\n",ptr->num,ptr->name,ptr->score);
		ptr=ptr->next;
	}
	system("pause");
	return 0;
}
link del_ptr(link head,link ptr)       /*�R���`�I�Ƶ{��*/
{  
	link top;
	top=head;
	if(ptr->num==head->num)                     /*[����1]:�R���I�b��C��*/
	{  
		head=head->next;
			printf("�w�R���� %d �����u �m�W�G%s �~��:%d\n",ptr->num,ptr->name,ptr->score);
	}
	else
	{  
		while(top->next!=ptr)          /*���R���I���e�@�Ӧ�m*/
			top=top->next;
		if(ptr->next==NULL)            /*�R���b��C�����`�I*/
		{  
			top->next=NULL;
	 		printf("�w�R���� %d �����u �m�W�G%s �~��:%d\n",ptr->num,ptr->name,ptr->score);
		}
		else                           /*�R���b��C�������@�`�I*/
		{  
			top->next=ptr->next;
				printf("�w�R���� %d �����u �m�W�G%s �~��:%d\n",ptr->num,ptr->name,ptr->score);
		}
	}
	free(ptr);                        /*����O����Ŷ�*/
	return head;                      /*�^�Ǧ�C*/
}

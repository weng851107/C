#include <stdio.h>
#include <stdlib.h>

struct employee
{  
	int num,score;
	char name[10];
	struct employee *next;
};
typedef struct employee node;
typedef node *link;

link findnode(link head,int num)
{
     link ptr;
     ptr=head;
     while(ptr->next!=head)
     {
        if(ptr->num==num)
           return ptr;
        ptr=ptr->next;
     }
     ptr=NULL;   
     return ptr;
}

link deletenode(link head,link del)   
{
     link CurNode=NULL;  
     link PreNode=NULL;
     link TailNode=NULL;
     if(head==NULL)
     {
        printf("[������C�w�g�ŤF]");
        return NULL;
     }
     else
     {
         if(del==head) /*�n�R�����`�I�O��C��*/
         {
            CurNode=head;
            while(CurNode->next!=head)
               CurNode=CurNode->next;
               /*���̫�@�Ӹ`�I�ðO���U��*/
               TailNode=CurNode;
               /*(1)�N��C������U�@�Ӹ`�I*/
               head=head->next;
               /*(2)�N��C�̫�@�Ӹ`�I�����Ы��V�s����C��*/
               TailNode->next=head;
               return head;
         } 
         else /*�n�R�����`�I���O��C��*/
         {
              CurNode=head;
              while(CurNode->next!=del)
                 CurNode=CurNode->next;
              /*(1)���n�R���`�I���e�@�Ӹ`�I�ðO���U��*/
              PreNode=CurNode;
              /*�n�R�����`�I*/
              CurNode=CurNode->next;
              /*(2)�N�n�R���`�I���e�@�ӫ��Ы��V�n�R���`�I���U�@�Ӹ`�I*/
              PreNode->next=CurNode->next;
              return head;
         }
     }
}


int main()
{  
	link head,ptr,newnode;
	int new_num, new_score;
	char new_name[10];
	int i,j,position=0,find;
	char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"},{"John"},{"Mark"},{"Ricky"},{"Lisa"},{"Jasica"},{"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
	int data[12][2]={ 1001,32367,1002,24388,1003,27556,1007,31299,
    1012,42660,1014,25676,1018,44145,1043,52182,1031,32769,1037,21100,1041,32196,1046,25776};
	printf("���u�s�� �~�� ���u�s�� �~�� ���u�s�� �~�� ���u�s�� �~��\n");
	printf("-------------------------------------------------------\n");
	
	for(i=0;i<3;i++)
	{  
		for (j=0;j<4;j++)
			printf("[%2d] [%3d]  ",data[j*3+i][0],data[j*3+i][1]);
		printf("\n");
	}
	head=(link)malloc(sizeof(node));     /*�إߦ�C��*/
	if(!head)
	{  
		printf("Error!! �O����t�m����!!\n");
		exit(1);
	}
	head->num=data[0][0];
	for (j=0;j<10;j++)
		head->name[j]=namedata[0][j];
	head->score=data[0][1];
	head->num=data[0][0];
	head->next=NULL;
	ptr=head;
	for(i=1;i<12;i++)                   /*�إߦ�C*/
	{  
		newnode=(link)malloc(sizeof(node));
		newnode->num=data[i][0];
		for (j=0;j<10;j++)
			newnode->name[j]=namedata[i][j];
		newnode->score=data[i][1];
		newnode->num=data[i][0];
		newnode->next=NULL;
		ptr->next=newnode;/*�N�e�@�Ӹ`�I���V�s�إߪ��`�I*/ 
		ptr=newnode; /*�s�`�I�����e�@�Ӹ`�I*/ 
	}
	newnode->next=head;/*�N�̫�@�Ӹ`�I���V�Y�`�I�N���F�����쵲*/ 
	while(1)
	{  
		printf("\n�п�J�n�R�������u�s��,�n�������J�L�{,�п�J-1�G");
		scanf("%d",&position);
		if(position==-1)    /*�j�餤�_����*/
			break;
		else
		{  
	
            ptr=findnode(head,position);
            if(ptr==NULL)
             {
              printf("-----------------------\n");
              printf("��C���S�o�Ӹ`�I....\n");
              break;
              } 
            else
			 {
             head=deletenode(head,ptr);
			 printf("�w�R���� %d �����u �m�W�G%s �~��:%d\n",ptr->num,ptr->name,ptr->score);
             }
		}
	}
	 ptr=head;/*���V��C���}�Y*/
     printf("\n\t���u�s��    �m�W\t�~��\n");         
     printf("\t==============================\n");

	do
	{
	    printf("\t[%2d]\t[ %-10s]\t[%3d]\n",ptr->num,ptr->name,ptr->score);
		ptr=ptr->next;/*���V�U�@�Ӹ`�I*/
    } while(head!=ptr && head!=head->next);
	system("pause");
	return 0;
}

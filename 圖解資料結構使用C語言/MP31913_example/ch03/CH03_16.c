#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{  
	int num,score;
	char name[10];
	struct employee *llink;
	struct employee *rlink;
};
typedef struct employee node;
typedef node *link;

link findnode(link head,int num)
{
     link ptr;
     ptr=head;
     while(ptr!=NULL)
     {
        if(ptr->num==num)
           return ptr;
        ptr=ptr->rlink;
     }
     return ptr;
}

link deletenode(link head,link del)   
{  
    if(head==NULL) /*���V��C�O�Ū�*/
    {
       printf("[��C�O�Ū�]\n");
       return NULL;
    }
   if(del==NULL)
   {
      printf("[���~:���O��C�����`�I]\n");
      return NULL;
   }
   if(del==head)
   {
      head=head->rlink;          
      head->llink=NULL;
   }
   else
   {
       if(del->rlink==NULL) /*�R����C��*/
       {
          del->llink->rlink=NULL;
       }
       else /*�R�������`�I*/
       {
           del->llink->rlink=del->rlink;
           del->rlink->llink=del->llink;
       }
    }
    free(del);
    return head;
}


int main()
{  
	link head,ptr;
	link llinknode=NULL;
	link newnode=NULL;
	int new_num, new_score;
	char new_name[10];
	int i,j,position=0,find;
	int data[12][2]={ 1001,32367,1002,24388,1003,27556,1007,31299,
    1012,42660,1014,25676,1018,44145,1043,52182,1031,32769,1037,21100,1041,32196,1046,25776};
	char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"},{"John"},
    {"Mark"},{"Ricky"},{"Lisa"},{"Jasica"},{"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
	printf("���u�s�� �~�� ���u�s�� �~�� ���u�s�� �~�� ���u�s�� �~��\n");
	printf("-------------------------------------------------------\n");

	for(i=0;i<3;i++)
	{  
		for (j=0;j<4;j++)
			printf("[%2d] [%3d]  ",data[j*3+i][0],data[j*3+i][1]);
		printf("\n");
	}
	head=(link)malloc(sizeof(node)); /*�إߦ�C��*/
	if(head==NULL)
	{  
		printf("Error!! �O����t�m����!!\n");
		exit(1);
	}
	else
	{
        memset(head,0,sizeof(node));
	    head->num=data[0][0];
	    for (j=0;j<10;j++)
		   head->name[j]=namedata[0][j];
	    head->score=data[0][1];
	    llinknode=head;
	    for(i=1;i<12;i++) /*�إߦ�C*/
	    {  
		   newnode=(link)malloc(sizeof(node));
		   memset(newnode,0,sizeof(node));
		   newnode->num=data[i][0];
		   for (j=0;j<10;j++)
			   newnode->name[j]=namedata[i][j];
		   newnode->score=data[i][1];
		   llinknode->rlink=newnode;
		   newnode->llink=llinknode;
		   llinknode=newnode;
	   }
    }
	
	while(1)
	{  
		printf("\n�п�J�n�R�������u�s��,�n�������J�L�{,�п�J-1�G");
		scanf("%d",&position);
		if(position==-1)    /*�j�餤�_����*/
			break;
		else
		{  
			ptr=findnode(head,position);
		  	head=deletenode(head,ptr);
		}
	}
	printf("\n\t���u�s��    �m�W\t�~��\n");         
    printf("\t==============================\n");
	ptr=head;
	while(ptr!=NULL)
	{
       printf("\t[%2d]\t[ %-10s]\t[%3d]\n",ptr->num,ptr->name,ptr->score);
       ptr=ptr->rlink;   
    }
	system("pause");
	return 0;
}

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

int main()
{  
	link head,ptr,newnode,last,before;
	int i,j,findword=0;
	char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"},
    {"Jon"},{"Mark"},{"Ricky"},{"Lisa"},{"Jasica"},
    {"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
	int data[12][2]={ 1001,32367,1002,24388,1003,27556,1007,31299,
    1012,42660,1014,25676,1018,44145,1043,52182,1031,32769,1037,21100,1041,32196,1046,25776};
	head=(link)malloc(sizeof(node)); /*�إߦ�C��*/
	if(!head)
	{  
		printf("Error!! �O����t�m����!!\n");
		exit(1);
	}
	head->num=data[0][0];
	for (j=0;j<10;j++)
		head->name[j]=namedata[0][j];
	head->score=data[0][1];
	head->next=NULL;
	ptr=head;
	for(i=1;i<12;i++)  /*�إ��쵲��C*/
	{  
		newnode=(link)malloc(sizeof(node));
		newnode->num=data[i][0];
		for (j=0;j<10;j++)
			newnode->name[j]=namedata[i][j];
		newnode->score=data[i][1];
		newnode->next=NULL;
		ptr->next=newnode;
		ptr=ptr->next;
	}
	ptr=head;
	i=0;
	printf("��l���u��C�`�I��ơG\n");               
	while (ptr!=NULL)                       
	{    /*�C�L��C���*/
		printf("[%2d %6s %3d] -> ",ptr->num,ptr->name,ptr->score);
		i++;
		if(i>=3)   /*�T�Ӥ������@�C*/
		{  
			printf("\n");
			i=0;
		}
		ptr=ptr->next;
	}
	ptr=head;
	before=NULL;
	printf("\n������C�`�I��ơG\n");          
	while(ptr!=NULL)  /*��C����,�Q�ΤT�ӫ���*/
	{  
		last=before;
		before=ptr;
		ptr=ptr->next;
		before->next=last;
	}
	ptr=before;
	while(ptr!=NULL)
	{  
		printf("[%2d %6s %3d] -> ",ptr->num,ptr->name,ptr->score);
		i++;
		if(i>=3)
		{  
			printf("\n");
			i=0;
		}
		ptr=ptr->next;
	}
	system("pause");
	return 0;
}

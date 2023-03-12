#include <stdio.h>
#include <stdlib.h>

struct student
{ 
	int num;
	char name[10];
	int score;
	struct student *next;
};
typedef struct student node;
typedef node *link;

int main()
{  
	link newnode,ptr,delptr;             /*�ŧi�T�Ӧ�C���c����*/
	int i;
	printf("�п�J 5 ���ǥ͸�ơG\n");
	delptr=(link)malloc(sizeof(node));   /*delptr�ȷ��C��*/
	if (!delptr)
	{  
		printf("[Error!!�O����t�m����!]\n");
		exit(1);
	}
	printf("�п�J�y���G");
	scanf("%d",&delptr->num);
	printf("�п�J�m�W�G");
	scanf("%s",delptr->name);
	printf("�п�J���Z�G");
	scanf("%d",&delptr->score);
	ptr=delptr;                          /*�O�d��C���A�Hptr���ثe�`�I����*/
	for (i=1;i<5;i++)
	{  
		newnode=(link)malloc(sizeof(node));  /*�إ߷s�`�I*/
		if(!newnode)
		{  
			printf("[Error!!�O����t�m����!\n");
			exit(1);
		}
		printf("�п�J�y���G");
		scanf("%d",&newnode->num);
		printf("�п�J�m�W�G");
		scanf("%s",newnode->name);
		printf("�п�J���Z�G");
		scanf("%d",&newnode->score);
		newnode->next=NULL;
		ptr->next=newnode;          /*��s�`�I�[�b��C�᭱*/
		ptr=ptr->next;              /*��ptr�O���b��C���̫᭱*/
	}
    printf("\n  ��  ��  ��  �Z\n");
    printf(" �y��\t�m�W\t���Z\n=====================\n");
	ptr=delptr;                     /*��ptr�^���C��*/
	while(ptr!=NULL)
	{  
		printf("%3d\t%-s\t%3d\n",ptr->num,ptr->name,ptr->score);
	    delptr=ptr;
		ptr=ptr->next;              /*ptr�̧ǩ��ᨫ�X��C*/
        free(delptr);               /*���^�O����Ŷ�*/
	}
	system("pause");
	return 0;
}

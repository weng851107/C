#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 10			/*�w�q��C���j�p*/

int main()
{
	int front,rear,val,queue[MAX]={0};
	char choice;
	front=rear=-1;
	while(rear<MAX-1 && choice!='e')
	{  
		printf("[a]��ܦs�J�@�Ӽƭ�[d]��ܨ��X�@�Ӽƭ�[e]��ܸ��X���{��: ");
		choice=getche();
		switch(choice)
		{
			case 'a':
				printf("\n[�п�J�ƭ�]: ");
				scanf("%d",&val);
				rear++;
				queue[rear]=val;
				break;
			case 'd':
				if(rear>front)
				{  
					front++;
					printf("\n[���X�ƭȬ�]: [%d]\n",queue[front]);
					queue[front]=0;
				}
				else
				{  
					printf("\n[��C�w�g�ŤF]\n");
					exit(0);
				}
				break;
			default:
				printf("\n");
				break;
		}
	}
	printf("\n------------------------------------------\n");
	printf("[��X��C�����Ҧ�����]:");
	
    if(rear==MAX-1) 
     printf("[��C�w��]\n");
	else if (front>=rear)
	{
		printf("�S��\n");
		printf("[��C�w��]\n");
	}
	else
	{
        while (rear>front)
		{  
			front++;
			printf("[%d] ",queue[front]);
		}
		printf("\n");
		printf("------------------------------------------\n");
	}
	printf("\n");
	system("pause");
	return 0;
}

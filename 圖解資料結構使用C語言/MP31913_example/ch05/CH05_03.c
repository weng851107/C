#include <stdio.h>
#include <stdlib.h>

int main(void)
{  
	int front,rear,val,queue[5]={0};
	front=rear=-1;
	while(rear<5&&val!=-1)
	{  
		printf("�п�J�@�ӭȥH�s�J��C�A�����X�Ƚп�J0�C(������J-1)�G");
		scanf("%d",&val);
		if(val==0)
		{  
			if(front==rear)
			{  
				printf("[��C�w�g�ŤF]\n");
				break;
			}
			front++;
			if (front==5)
				front=0;
			printf("���X��C�� [%d]\n",queue[front]);
			queue[front]=0;
		}
		else if(val!=-1&&rear<5)
		{  
			if(rear+1==front||rear==4&&front<=0)
			{  
				printf("[��C�w�g���F]\n");
				break;
			}
			rear++;
			if(rear==5)
				rear=0;
			queue[rear]=val;
		}
	}
	printf("\n��C�Ѿl��ơG\n");
	if (front==rear)
		printf("��C�w��!!\n");
	else 
	{ 
		while(front!=rear)
		{  
			front++;
			if (front==5)
				front=0;
			printf("[%d]",queue[front]);
			queue[front]=0;
		}
	}
	printf("\n");
	system("pause");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int top=-1;
void push(int stack[],int MAX,int val)
{
	if(top>=MAX-1)
		printf("[���|�w�g���F]\n");
	else
	{
		top++;
		stack[top]=val;
	}
}
int pop(int stack[])
{
	if(top<0)
		printf("[���|�w�g�ŤF]\n");
	else
		top--;
	return stack[top];
}
void Swap(int* a,int* b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}


int main()
{  
	int card[52],stack[52]={0};
	int i,j,k=0;
	char ascVal;
	int style;
	srand((unsigned)time(NULL));
	for (i=0;i<52;i++)
		card[i]=i+1;
	printf("[�~�P��...�еy��!]\n");
	while(k<30)
	{
		for(i=0;i<51;i++)
			for(j=i+1;j<52;j++)
				if(rand()%52==2)
					Swap(&card[i],&card[j]);  /*�~�P*/
		k++;
	}
	i=0;
	while(i!=52)
	{
		push(stack,52,card[i]);		/*�N52�i�P���J���|*/
		i++;
	}
	printf("[�f�ɰw�o�P]\n");
	printf("[��ܦU�a�P�l]\n �F�a\t  �_�a\t   ��a\t    �n�a\n");
	printf("=================================\n");
	while (top >=0)
	{  
		style = stack[top]/13;	/*�p��P�l���*/
		switch(style)			/*�P�l���ϥܹ���*/
		{
			case 0:				/*����*/
				ascVal=5;
				break;
			case 1:				/*���*/
				ascVal=4;
				break;
			case 2:				/*����*/
				ascVal=3;
				break;
			case 3:				/*�®�*/
				ascVal=6;
				break;
		}
		printf("[%c%3d]\t",ascVal,stack[top]%13+1);
		if(top%4==0)
			printf("\n");
		top--;
	}
	system("pause");
	return 0;
}

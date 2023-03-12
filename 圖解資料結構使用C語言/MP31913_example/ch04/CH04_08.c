#include <stdio.h>
#include <stdlib.h>
#define EAST  MAZE[x][y+1]  /*�w�q�F�誺�۹��m*/
#define WEST  MAZE[x][y-1]  /*�w�q��誺�۹��m*/
#define SOUTH MAZE[x+1][y]	/*�w�q�n�誺�۹��m*/
#define NORTH MAZE[x-1][y]	/*�w�q�_�誺�۹��m*/
#define ExitX 8			/*�w�q�X�f��X�y�Цb�ĤK�C*/
#define ExitY 10			/*�w�q�X�f��Y�y�Цb�ĤQ��*/
struct list
{
	int x,y;
	struct list* next;
};
typedef struct list node;
typedef node* link;
int MAZE[10][12] = {2,1,1,1,1,0,0,0,1,1,1,1,	/*�ŧi�g�c�}�C*/
		            1,0,0,0,1,1,1,1,1,1,1,1,
				    1,1,1,0,1,1,0,0,0,0,1,1,
					1,1,1,0,1,1,0,1,1,0,1,1,
					1,1,1,0,0,0,0,1,1,0,1,1,
					1,1,1,0,1,1,0,1,1,0,1,1,
					1,1,1,0,1,1,0,1,1,0,1,1,
					1,1,1,0,1,1,0,0,1,0,1,1,
					1,1,0,0,0,0,0,0,1,0,0,1,
					1,1,1,1,1,1,1,1,1,1,1,3};
link push(link stack,int x,int y)
{
	link newnode;
	newnode = (link)malloc(sizeof(node));
	if(!newnode)
	{
		printf("Error!�O����t�m����!\n");
		return NULL;
	}
	newnode->x=x;
	newnode->y=y;
	newnode->next=stack;
	stack=newnode;
    return stack;
}
link pop(link stack,int* x,int* y)
{
	link top;
	if(stack!=NULL)
	{
		top=stack;
		stack=stack->next;
		*x=top->x;
		*y=top->y;
		free(top);
		return stack;
	}
	else
		*x=-1;
	return stack;
}
int chkExit(int x,int y,int ex,int ey)
{
	if(x==ex&&y==ey)
	{
		if(NORTH==1||SOUTH==1||WEST==1||EAST==2)
			return 1;
		if(NORTH==1||SOUTH==1||WEST==2||EAST==1)
			return 1;
		if(NORTH==1||SOUTH==2||WEST==1||EAST==1)
			return 1;
		if(NORTH==2||SOUTH==1||WEST==1||EAST==1)
			return 1;
    }
	return 0;
}

int main()
{
	int i,j,x,y;
	link path = NULL;
	x=1;	/*�J�f��X�y��*/
	y=1;    /*�J�f��Y�y��*/
	printf("[�g�c���a������(0�����,2��ܤJ�f,3��ܥX�f]\n"); /*�L�X�g�c�����|��*/
	for(i=0;i<10;i++)
	{
		for(j=0;j<12;j++)
			printf("%2d",MAZE[i][j]);
		printf("\n");
	}
	while(x<=ExitX&&y<=ExitY)
	{
		MAZE[x][y]=6;
		if(NORTH==0)
		{
			x -= 1;
			path=push(path,x,y);
		}
		else if(SOUTH==0)
		{
			x+=1;
			path=push(path,x,y);
		}
		else if(WEST==0)
		{
			y-=1;
			path=push(path,x,y);
		}
		else if(EAST==0)
		{
			y+=1;
			path=push(path,x,y);
		}
		else if(chkExit(x,y,ExitX,ExitY)==1) /*�ˬd�O�_����X�f�F*/
			break;
		else
		{
			MAZE[x][y]=2;
			path=pop(path,&x,&y);
		}
	}
	printf("---------------------------\n");
	printf("[6��ܦѹ����L�����u]\n"); /*�L�X�ѹ������g�c�᪺���|��*/
	printf("---------------------------\n");
	for(i=0;i<10;i++)
	{
		for(j=0;j<12;j++)
			printf("%2d",MAZE[i][j]);
		printf("\n");
	}
	system("pause");
	return 0;
}

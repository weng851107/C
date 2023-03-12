#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10/*�w�q��C���̤j�e�q	*/

int front=-1;/*���V��C���e��*/
int rear=-1;/*���V��C�����*/

struct list/*�ϧγ��I���c�ŧi*/
{
   int x;/*���I���*/
   struct list *next;/*���V�U�@�ӳ��I������*/
};
typedef struct list node;
typedef node *link;
struct GraphLink
{
   link first;
   link last;       
};

int run[9];/*�ΨӰO���U���I�O�_���X�L*/
int queue[MAXSIZE];
struct GraphLink Head[9];


void insert(struct GraphLink *temp,int x)
{
   link newNode;
   newNode=(link)malloc(sizeof(node));
   newNode->x=x;
   newNode->next=NULL;  
   if(temp->first==NULL)
   { 
      temp->first=newNode;
      temp->last=newNode;
   }
   else 
   {
	 temp->last->next=newNode;
	 temp->last=newNode;
   }
}
/*��C��ƪ��s�J*/
void enqueue(int value)
{
   if(rear>=MAXSIZE) return;
   rear++;
   queue[rear]=value;
}
/*��C��ƪ����X*/
int dequeue() 
{
   if(front==rear) return -1;
   front++;
   return queue[front];
}
/*�s���u���j�M�k*/
void bfs(int current)
{
   link tempnode; /*�{�ɪ��`�I����*/
   enqueue(current); /*�N�Ĥ@�ӳ��I�s�J��C*/
   run[current]=1; /*�N���X�L�����I�]�w��1*/
   printf("[%d]",current); /*�L�X�Ө��X�L�����I*/
   while(front!=rear) { /*�P�_�ثe�O�_���Ŧ�C*/
      current=dequeue(); /*�N���I�q��C�����X*/
      tempnode=Head[current].first; /*���O���ثe���I����m*/
      while(tempnode!=NULL)
      {
         if(run[tempnode->x]==0)
         {
            enqueue(tempnode->x);
            run[tempnode->x]=1; /*�O���w���X�L*/
            printf("[%d]",tempnode->x);
         }
         tempnode=tempnode->next;
      }
   }
} 
void print(struct GraphLink temp)
{
   link current=temp.first;
   while(current!=NULL)
   {
      printf("[%d]",current->x);
      current=current->next;
   }
   printf("\n");
}

int main()
{
/*�ϧ���u�}�C�ŧi*/
   int Data[20][2] =  
   { {1,2},{2,1},{1,5},{5,1},{2,4},{4,2},{2,3},{3,2},{3,4},{4,3},
   {5,3},{3,5},{4,5},{5,4}};
   int DataNum;			
   int i,j;				
   printf("�ϧΪ��F����C���e�G\n"); /*�C�L�ϧΪ��F����C���e*/
   for( i=1 ; i<6 ; i++ )
   { /*�@���K�ӳ��I*/
      run[i]=0; /*�]�w�Ҧ����I���|�����X�L*/
      printf("���I%d=>",i);
      Head[i].first=NULL;
      Head[i].last=NULL;                 
	  for( j=0 ; j<20 ;j++)
      {
	     if(Data[j][0]==i)
         { /*�p�G�_�I�M��C���۵��A�h�⳻�I�[�J��C*/
	        DataNum = Data[j][1];          
	        insert(&Head[i],DataNum);
	     }
	   }
	      print(Head[i]);/*�C�L�ϧΪ��F����C���e*/
    } 	
    printf("�s���u�����X���I�G\n");/*�C�L�s���u�����X�����I*/
    bfs(1);
    printf("\n");
	system("pause");
	return 0;
}

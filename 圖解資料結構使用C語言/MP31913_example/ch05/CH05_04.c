#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node *next;
};
typedef struct Node QueueNode;
typedef QueueNode *QueueByLinkedList;
QueueByLinkedList front=NULL;
QueueByLinkedList rear=NULL;
/*��kenqueue:��C��ƪ��s�J*/
void enqueue(int value) 
{
   QueueByLinkedList node; /*�إ߸`�I*/
   node=(QueueByLinkedList)malloc(sizeof(QueueNode));
   node->data=value;
   node->next=NULL;
   /*�ˬd�O�_���Ŧ�C*/
   if (rear==NULL)
      front=node;/*�s�إߪ��`�I������1�Ӹ`�I*/
   else
      rear->next=node;/*�N�`�I�[�J���C������*/
   rear=node;/*�N��C�����ݫ��Ы��V�s�[�J���`�I*/
}
int dequeue(int action)/*��kdequeue:��C��ƪ����X*/
{
   int value;
   QueueByLinkedList tempNode,startNode;
   /*�q�e�ݨ��X���*/
   if (!(front==NULL) && action==1) 
   {
     if(front==rear) rear=NULL;
     value=front->data;/*�N��C��Ʊq�e�ݨ��X*/
     front=front->next;/*�N��C���e�ݫ��Ы��V�U�@��*/
     return value;
   }
   /*�q���ݨ��X���*/
   else if(!(rear==NULL) && action==2) 
   {
     startNode=front;/*���O�U�e�ݪ����Э�*/
     value=rear->data;/*���X�ثe���ݪ����*/
     /*��M�̧��ݸ`�I���e�@�Ӹ`�I*/
     tempNode=front;
     while (front->next!=rear && front->next!=NULL) 
     { 
           front=front->next;
           tempNode=front;
     }
     front=startNode;/*�O���q���ݨ��X��ƫ᪺��C�e�ݫ���*/
     rear=tempNode;/*�O���q���ݨ��X��ƫ᪺��C���ݫ���*/
     /*�U�@��{���O�����C���ȳѤU�̸`�I��,
     ���X��ƫ�K�Nfront��rear���Vnull*/
     if ((front->next==NULL) || (rear->next==NULL)) 
     { 
         front=NULL;
         rear=NULL;
     }
     return value; 
   }
   else return -1;
}

int main()
{
   int temp,item;
   char ch;
   printf("�H�쵲��C�ӹ�@���V��C\n");
   printf("====================================\n");
   
   do
     {
      printf("�[�J�Ы� a,���X�Ы� d,�����Ы� e:");
      ch=getche();
      printf("\n");
      if(ch=='a')
      {
       printf("�[�J��������:"); 
       scanf("%d",&item);
       enqueue(item);
       }
       else if(ch=='d')
       {
       temp=dequeue(1);
       printf("�q���V��C�e�ݨ̧Ǩ��X��������ƭȬ��G%d\n",temp);
       temp=dequeue(2);
       printf("�q���V��C���ݨ̧Ǩ��X��������ƭȬ��G%d\n",temp);
       }
       else 
         break;
        } while(ch!='e');
       
  system("pause");      
  return 0; 
}

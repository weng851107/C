#include <stdio.h>
#include <stdlib.h>

struct Node /*���|�쵲�`�I���ŧi*/
{
   int data; /*���|��ƪ��ŧi*/
   struct Node *next;/*���|���Ψӫ��V�U�@�Ӹ`�I*/
};
typedef struct Node Stack_Node;/*�w�q���|���`�I���s���A*/
typedef Stack_Node *Linked_Stack;/*�w�q��C���|���s���A*/
Linked_Stack top=NULL;/*���V���|���ݪ�����*/
int isEmpty();
int pop();
void push(int data);
/*�P�_�O�_���Ű��|*/

/*�D�{��*/
int main()
{
    int value;
    int i;
    
    do
     {
       printf("�n���J���|,�п�J1,�u�X�h��J0,����ާ@�h��J-1: ");
       scanf("%d",&i);
       if(i==-1)
         break;
       else if (i==1)
       { 
        printf("�п�J������:"); 
        scanf("%d",&value);
        push(value);
       }
       else if(i==0)
        printf("�u�X��������%d\n",pop());
       } while(i!=-1);

    printf("============================\n");
    while(!isEmpty()) /*�N��Ƴ���q���ݼu�X*/
       printf("���|�u�X�����Ǭ�:%d\n",pop()); 
    printf("==========================\n");
    
    system("pause");      
    return 0; 
}
int isEmpty() 
{
    if(top==NULL) return 1;
    else return 0;
}
/*�N���w����Ʀs�J���|*/
void push(int data)
{
    Linked_Stack new_add_node; /*�s�[�J�`�I������*/
    /*�t�m�s�`�I���O����*/
    new_add_node=(Linked_Stack)malloc(sizeof(Stack_Node));
    new_add_node->data=data;/*�N�ǤJ���ȫ��w���`�I�����e*/
    new_add_node->next=top;/*�N�s�`�I���V���|������*/
    top=new_add_node;/*�s�`�I�������|������*/
}
/*�q���|���X���*/
int pop()
{
    Linked_Stack ptr; /*���V���|���ݪ�����*/
    int temp;
    if(isEmpty()) /*�P�_���|�O�_����,�p�G�O�h�Ǧ^-1*/
    {
       printf("===�ثe���Ű��|===\n");
       return -1;
    }
    else
    {
        ptr=top;/*���V���|������*/
        top=top->next;/*�N���|���ݪ����Ы��V�U�@�Ӹ`�I*/
        temp=ptr->data;/*���X���|�����*/
        free(ptr);/*�N�`�I���Ϊ��O��������*/
        return temp;/*�N�q���|���X����Ʀ^�ǵ��D�{��*/
    }
}

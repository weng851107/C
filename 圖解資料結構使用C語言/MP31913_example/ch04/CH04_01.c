#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 100 /*�w�q�̤j���|�e�q*/

int stack[MAXSTACK];/*���|���}�C�ŧi*/
int top=-1;/*���|������*/
/*�P�_�O�_���Ű��|*/
int isEmpty() 
{
    if(top==-1) return 1;
    else return 0;
}
/*�N���w����Ʀs�J���|*/
int push(int data)
{
    if(top>=MAXSTACK)
    {
       printf("���|�w��,�L�k�A�[�J\n");
       return 0; 
    }
    else
    {
       stack[++top]=data; /*�N��Ʀs�J���|*/
       return 1;
        
    }
}
/*�q���|���X���*/
int pop()
{
    if(isEmpty()) /*�P�_���|�O�_����,�p�G�O�h�Ǧ^-1*/
       return -1;
    else
       return stack[top--]; /*�N��ƨ��X��,�A�N���|���Щ��U��*/
}
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

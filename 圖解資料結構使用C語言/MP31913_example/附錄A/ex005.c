#include<stdio.h>
int main(void)
{
    char ch;
    printf("1.80�H�W,\n2.60~79,\n3.59�H�U\n");
    printf("�п�J���Ƹs��: ");
    scanf("%c",&ch);
    /*switch ����ԭz�}�l*/
    switch(ch)
    {
        /* ���B���[�j�A��*/
        case '1':
          printf("�~��O��!\n");
          break;
        case '2':
          printf("�٦��i�B�Ŷ�!!\n");
          break;
        case '3':
          printf("�Цh�h�V�O!!!\n");
          break;
        default:
          printf("error\n");
          break;
    }
    system("pause");
    return 0; 
} 

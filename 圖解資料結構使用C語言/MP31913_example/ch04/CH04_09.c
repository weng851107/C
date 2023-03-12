#include <stdio.h>
#define EIGHT 8 /*�w�q�̤j���|�e�q*/
#define TRUE 1
#define FALSE 0
int queen[EIGHT];/*�s��8�ӬӦZ���C��m*/
int number=0;/*�p���`�@���X�ոѪ��`��*/
/*�M�w�ӦZ�s�񪺦�m*/
/*��X�һݭn�����G*/
void print_table()
{
     int x=0,y=0;
     number+=1;
     printf("\n");
     printf("�K�ӦZ���D����%d�ո�\n\t",number);
     for(x=0;x<EIGHT;x++)
     {
        for(y=0;y<EIGHT;y++)
           if(x==queen[y])
              printf("<q>");
           else
              printf("<->");
        printf("\n\t");
     } 
     system("pause");    
}
void decide_position(int value) 
{
   int i=0;
   while(i<EIGHT)
   {
   /*�O�_����������P�_��*/
      if(attack(i,value)!=1)
      {
         queen[value]=i;
         if(value==7)
            print_table();
         else
            decide_position(value+1);
      }
      i++;
   }    
}
/*���զb(row,col)�W���ӦZ�O�_�D������
  �Y�D�������h�Ǧ^�Ȭ�1,�_�h�Ǧ^0*/
int attack(int row,int col)
{
    int i=0,atk=FALSE;
    int offset_row=0,offset_col=0;
    while((atk!=1)&&i<col)
    {
       offset_col=abs(i-col);
       offset_row=abs(queen[i]-row);
       /*�P�_��ӦZ�O�_�b�P�@�C�b�P�@�﨤�u�W*/
       if((queen[i]==row)||(offset_row==offset_col))
          atk=TRUE;
       i++;
    }
    return atk;
}

/*�D�{��*/
int main(void)
{
    decide_position(0);      
    return 0; 
}

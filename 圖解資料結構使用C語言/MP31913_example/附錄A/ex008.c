#include<stdio.h>
int main(void)
{
  int number;
  int sum=0;
  /*do while�j��}�l*/ 
  do
  {
    printf("�Ʀr0�������{��,�п�J�Ʀr: ");
    scanf("%d",&number);
    sum+=number;
    printf("�ثe�֥[�����G��: %d\n",sum);
  }while(number!=0);/*do while�j�鵲��*/
  system("pause");
  return 0;
} 

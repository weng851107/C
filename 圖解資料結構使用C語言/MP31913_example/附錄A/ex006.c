#include<stdio.h>
int main(void)
{
  int sum=0;
  int number;
  int i; /*�ŧi�j�鱱���ܼ�i*/
  printf("�п�J���: ");
  scanf("%d",&number);
  /*���Wfor�j��,�Ѥp��j�L�X�Ʀr */
  printf("\n�Ѥp��j�ƦC��X�Ʀr:\n");  
  for(i=1;i<=number; i++)
  {
    sum+=i; //�]�wsum��i���M 
    printf("%d",i);
    /*�]�w��X�s�[���⦡ */
    if(i<number)printf("+");
    else printf("=");
  }
  printf("%d\n",sum);
  sum=0;
  /*����for�j��,�Ѥj��p�L�X�Ʀr */
  printf("\n�Ѥj��p�ƦC��X�Ʀr:\n");
  for(i=number;i>=1; i--)
  {
    sum+=i; 
    printf("%d",i);
    if(i<=1)printf("=");
    else printf("+");
  }
  printf("%d\n",sum);
  system("pause");
  return 0;
} 

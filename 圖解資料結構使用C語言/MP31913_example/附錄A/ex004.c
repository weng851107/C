#include<stdio.h>
int main(void)
{  
  int month;    
  printf("�п�J���: ");    
  scanf("%d",&month);    
  if(2<=month & month<=4) 
    printf("�R���;����K��\n");    

  else if(5<=month & month<=7)         
    printf("���O�|�g���L�u\n");        
     
  else if(month>=8 & month <=10)
    printf("�����}�ɪ���u\n");    
    
  else if(month==1 |month>=11 & month <=12 )        
    printf("�H���방���V�u\n");        
      
  else        
    printf("�ܩ�p�S���o�Ӥ��!!!");  
  system("pause");          
  return 0; 
}

#include <stdio.h>
#include <stdlib.h>

void hanoi(int, int, int, int);	/* ��ƭ쫬 */

int main()
{  
    int j;
    printf("�п�J�Ҳ��ʮM���ƶq�G");
    scanf("%d", &j);
    hanoi(j,1, 2, 3);
    
    system("pause");
    return 0;
 }
 
 void hanoi(int n, int p1, int p2, int p3)
 {  
   if (n==1) /* ���j�X�f */ 
    printf("�M���q %d ���� %d\n", p1, p3);
     else
     {  
         hanoi(n-1, p1, p3, p2);
         printf("�M���q %d ���� %d\n", p1, p3);
         hanoi(n-1, p2, p1, p3);
   	  }
 }

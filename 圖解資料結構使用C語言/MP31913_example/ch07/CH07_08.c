#include <stdio.h>
#include <stdlib.h>
#define SIZE   7  
#define INFINITE  99999 
#define NUMBER 6

int Graph_Matrix[SIZE][SIZE];/* �ϧΰ}�C */
int distance[SIZE][SIZE];/* ���|���װ}�C */

/* �إ߹ϧ� */
void BuildGraph_Matrix(int *Path_Cost)
{
   int Start_Point;/* ��u���_�I */
   int End_Point; /* ��u�����I */
   int i, j;
   for ( i = 1; i < SIZE; i++ )
      for ( j = 1; j < SIZE; j++ )
         if (i==j)
            Graph_Matrix[i][j] = 0; /* �﨤�u�]��0 */
         else
            Graph_Matrix[i][j] = INFINITE;  
   /* �s�J�ϧΪ���u */  
   i=0;
   while(i<SIZE)
   {
      Start_Point = Path_Cost[i*3]; 
      End_Point = Path_Cost[i*3+1]; 
      Graph_Matrix[Start_Point][End_Point]=Path_Cost[i*3+2];
      i++;
   }
}
/* �L�X�ϧ� */
 
void shortestPath(int vertex_total)
{       
   int i,j,k;
   /* �ϧΪ��װ}�C��l��  */
   for (i=1;i<=vertex_total;i++ )
      for (j=i;j<=vertex_total;j++ )
         {
            distance[i][j]=Graph_Matrix[i][j]; 
            distance[j][i]=Graph_Matrix[i][j];        
         }
     /* �Q��Floyd�t��k��X�Ҧ����I��⤧�����̵u�Z�� */       
   for (k=1;k<=vertex_total;k++ ) 
      for (i=1;i<=vertex_total;i++ )
         for (j=1;j<=vertex_total;j++ )
            if (distance[i][k]+distance[k][j]<distance[i][j])
                distance[i][j] = distance[i][k] + distance[k][j];   
}
/* �D�{�� */
int main() 
{
   int Path_Cost[7][3] = { {1, 2,20}, 
                      {2, 3, 30},
                      {2, 4, 25},
                      {3, 5, 28},
                      {4, 5, 32},
                      {4, 6, 95},
                      {5, 6, 67} }; 
   int i,j;
   BuildGraph_Matrix(&Path_Cost[0][0]);
   printf("===========================================\n");
   printf("      �Ҧ����I��⤧�����̵u�Z��: \n");
   printf("===========================================\n");
   shortestPath(NUMBER); /* �p��Ҧ����I�����̵u���| */
   /*�D�o��⳻�I�����̵u���|���װ}�C��A�N��L�X*/
   printf("       ���I1 ���I2 ���I3 ���I4 ���I5 ���I6\n");
      for ( i = 1; i <= NUMBER; i++ )
      {
         printf("���I%d",i);
         for ( j = 1; j <= NUMBER; j++ )
         {
            printf("%5d ",distance[i][j]);
         }
         printf("\n");
      }
   printf("===========================================\n");
   printf("\n");
   system("PAUSE");
   return 0; 
}

/*�λ��j��ƨD n��������*/
#include <stdio.h>
#include <stdlib.h>

int factorial(int);  /*��ƭ쫬*/
int main()
{  
    int i,n;
    
    printf("�п�J������:"); 
    scanf("%d",&n);
    
    for (i=0;i<=n;i++)
     printf("%d !�Ȭ� %3d\n", i,factorial(i));
    
    system("pause");
    return 0;
}

int factorial(int i)
{  
    int sum;
     if(i == 0)/* ���j�פ���� */
      return(1);
     else
     sum = i * factorial(i-1); /* sum=n*(n-1)!�ҥH�����I�s���� */
     return sum;
}

#include <stdio.h>
int main(void)
{
    int iVal;
    printf("�п�J8�i��ƭ�:");
    scanf("%o",&iVal);
    printf("�z�ҿ�J8�i��ƭȡA�N��10�i��:%d\n",iVal);
    printf("\n");

    printf("�п�J10�i��ƭ�:");
    scanf("%d",&iVal);
    printf("�z�ҿ�J10�i��ƭȡA�N��8�i��:%o\n",iVal);
    printf("\n");

    printf("�п�J16�i��ƭ�:");
    scanf("%x",&iVal);
    printf("�z�ҿ�J16�i��ƭȡA�N��10�i��:%d\n",iVal);
    printf("\n");

    printf("�п�J10�i��ƭ�:");
    scanf("%d",&iVal);
    printf("�z�ҿ�J10�i��ƭȡA�N��16�i��:%x\n",iVal);
    printf("\n");    
    system("pause");
    return 0;
}

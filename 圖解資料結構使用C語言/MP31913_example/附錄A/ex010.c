#include<stdio.h>
/*�禡�쫬�ŧi*/
void fun(int, int);
int main(void)
{	
	int a,b;
 	a=10;
    b=15;
    /*��X�D�{������a,b�ȻP��}*/
    printf("�禡�~:\na=%d,\tb=%d\n",a,b);
    printf("a����}:%d, b����}:%d\n",&a,&b);	
	/*�I�s�禡*/
    fun(a,b);
    /*���j��*/
	printf("==========================\n");
 	/*��X�I�s�禡�᪺a,b��*/
  	printf("�I�s�禡��: \na=%d,\tb=%d\n",a,b);
  	system("pause");
 	return 0;	
}
void fun(int a, int b)
{
	printf("==========================\n");
 	printf("�禡��:\n");
 	printf("�����޼�:a=%d, b=%d\n",a,b);
 	printf("a����}:%d, b����}:%d\n",&a,&b);
 	/*���]�禡����a,b��*/
	a=20;
	b=30;
	printf("�ܧ�ƭȫ�:a=%d, b=%d\n",a,b);
}

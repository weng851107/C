#include<stdio.h>
/*�[�W���ȹB��l���禡�쫬�ŧi*/
void fun(int*, int*);
int main(void)
{	
	int a,b;
 	a=10;
    b=15;
    printf("�禡�~:\na=%d,\tb=%d\n",a,b);
    printf("a����}:%d, b����}:%d\n",&a,&b);
    /*�޼ƻݥ[�W&���}�B��l*/	
	fun(&a,&b);
	printf("==========================\n");
	printf("�I�s�禡��: \na=%d,\tb=%d\n",a,b);
	system("pause");
	return 0;	
}
void fun(int *a, int *b)
{
	printf("==========================\n");
 	printf("�禡��:\n");
 	/*���ɪ�*a�P*b�N���O��}�W���ƭ�*/
	printf("�����޼�:a=%d,\tb=%d\n",*a,*b);
	/*��X�禡��a�Pb����}*/
	printf("a����}:%d, b����}:%d\n",a,b);
	*a=20;
	*b=30;	
	printf("�ܧ�ƭȫ�:a=%d, b=%d\n",*a,*b);
}

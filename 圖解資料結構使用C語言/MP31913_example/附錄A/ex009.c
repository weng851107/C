#include<stdio.h>
#include<string.h>
int main(void)
{
	int i;
	char choice;
	/*�ŧi�r��}�C�ê�l��*/
 	char newspaper[5][20]={{"1.���G���"},
 							{"2.�p�X���"},
        					{"3.�ۥѳ�"},
             				{"4.������"},
                 			{"5.���ݭn"}};
	/*�r��}�C����X*/
	for(i=0; i<5; i++)
	{
		printf("%s  ",newspaper[i]);
	}
 	printf("�п�J���:");
 	choice=getche();
 	printf("\n");
 	choice=choice-'0';
 	/*��J���P�_*/
 	if(choice>=0 && choice<4)
 	{
  		printf("%s",newspaper[choice-1]);
    	printf("\n���±z���q��!!!\n");
    }	
    else if(choice==5)
  		printf("\n�P�±z���Ѧ�!!!\n");
  	else
  		printf("��J���~\n");
	system("pause");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main( )
{
	int i,j,find,val=0,data[80]={0};
	for (i=0;i<80;i++)
		data[i]=(rand()%150+1);
	while (val!=-1)
	{  
		find=0;
		printf("�п�J�j�M���(1-150)�A��J-1���}�G");
		scanf("%d",&val);
		for (i=0;i<80;i++)
		{  
			if(data[i]==val)
			{  
				printf("�b�� %3d�Ӧ�m������ [%3d]\n",i+1,data[i]);
				find++;
			}
		}
		if(find==0 && val !=-1)
			printf("######�S����� [%3d]######\n",val);
	}
	printf("��Ƥ��e�G\n");
	for(i=0;i<10;i++)
	{ 
		for(j=0;j<8;j++)
			printf("%2d[%3d]  ",i*8+j+1,data[i*8+j]);
		printf("\n");
	}	
	system("pause");
	return 0;
}

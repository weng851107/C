#include <stdio.h>
#include <stdlib.h>

int main()
{  
	int arr[6][6]={0};
    int i,j,k,tmpi,tmpj;     /*�ŧi�x�}arr*/
	int data[7][2]={{1,2},{2,1},{2,3},{2,4},{4,3},{4,1}};  /*�ϧΦU�䪺�_�I�Ȥβ��I��*/
	
	for (i=0;i<6;i++)       /*Ū���ϧθ��*/
		for (j=0;j<6;j++)   /*��Jarr�x�}*/
		{  
			tmpi=data[i][0];     /*tmpi���_�l���I*/
			tmpj=data[i][1];     /*tmpj���פ�I*/
			arr[tmpi][tmpj]=1;   /*���䪺�I��J1*/
		}
	printf("���V�ϧίx�}�G\n");
	for (i=1;i<6;i++)
	{  
		for (j=1;j<6;j++)
	    printf("[%d] ",arr[i][j]);   /*�C�L�x�}���e*/
		printf("\n");
	}
	system("pause");
	return 0;
}

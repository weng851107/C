#include <stdio.h>
#include <stdlib.h>

int main()
{  
	int arr[6][6]={0},i,j,k,tmpi,tmpj;            /*�ŧi�x�}arr*/
	int data[14][2]={{1,2},{2,1},{1,5},{5,1}, /*�ϧΦU�䪺�_�I�Ȥβ��I��*/
					{2,3},{3,2},{2,4},{4,2},
					{3,4},{4,3}};
	for (i=0;i<14;i++)         /*Ū���ϧθ��*/
		for (j=0;j<6;j++)      /*��Jarr�x�}*/
			for (k=0;k<6;k++)
			{  
				tmpi=data[i][0];    /*tmpi���_�l���I*/
				tmpj=data[i][1];    /*tmpj���פ�I*/
				arr[tmpi][tmpj]=1;  /*���䪺�I��J1*/
			}
	printf("�L�V�ϧίx�}�G\n");
	for (i=1;i<6;i++)
	{  
		for (j=1;j<6;j++)
	    printf("[%d] ",arr[i][j]);  /*�C�L�x�}���e*/
		printf("\n");
	}
	system("pause");
	return 0;
}

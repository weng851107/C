#include <stdio.h>
#include <stdlib.h>

int main()
{
    float* piF=(float*)malloc(sizeof(float));
    /* �N���Ы��V�B�I�ưʺA�t�m�O�ЪŶ� */
    
    printf("�п�JpiF���� =");
    scanf("%f",piF);/* ��JpiF���� */ 
    printf("\n");
    printf("piF�ҫ��V����}���e�� %f\n",*piF);
    printf("piF�ҫ��V����}�� %p\n", piF);
    
    free(piF);/* �N����piF���Ŷ����� */ 
    
    system("pause");  
    return 0;
}


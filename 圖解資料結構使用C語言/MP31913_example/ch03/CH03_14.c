#include <stdio.h>
#include <stdlib.h>

int main()
{
    int select;
    
    struct student
    {
        char name[20];
        int Math;
        int Eng;
        char no[10];
        struct student *rlink;
        struct student *llink;
    };
    typedef struct student s_data;
    s_data *ptr;        /* �s������ */
    s_data *head;       /* ��C�}�Y���� */
    s_data *new_data;   /* �s�W�����Ҧb��m���� */

    head = (s_data*) malloc(sizeof(s_data)); 
    head->llink=NULL;
    head->rlink=NULL;
    ptr = head;   /* �]�w�s�����ж}�l��m  */
    do
    {
        printf("(1)�s�W (2)���} =>");
        scanf("%d", &select);
        if (select != 2)
        {
            printf("�m�W �Ǹ� �ƾǦ��Z �^�妨�Z:");
            new_data = (s_data*) malloc(sizeof(s_data));    /* �s�W�U�@���� */
            scanf("%s %s %d %d",new_data->name,new_data->no,&new_data->Math,&new_data->Eng); 
            /*��J�`�I���c������� */
            ptr->rlink=new_data;
            new_data->rlink = NULL;   /* �U�@������next���]�w��null */
            new_data->llink=ptr;   /* �s�����г]�w���s�����Ҧb��m */
            ptr=new_data;
        }
    } while (select != 2);

    printf("-----�V�k���X�Ҧ��`�I-----\n"); 
    ptr = head->rlink;    /* �]�w�s�����бq��C�����k������ҫ��`�I�}�l */ 
    while (ptr!= NULL)
    {
     printf("�m�W�G%s\t�Ǹ�:%s\t�ƾǦ��Z:%d\t�^�妨�Z:%d\n", ptr->name,ptr->no,ptr->Math,ptr->Eng);    
     if(ptr->rlink==NULL)
        break;
     ptr = ptr ->rlink;    /* �Nptr�����k��U�@���� */   
     }
    printf("-----�V�����X�Ҧ��`�I-----\n");
    while (ptr != NULL)
    {
        printf("�m�W�G%s\t�Ǹ�:%s\t�ƾǦ��Z:%d\t�^�妨�Z:%d\n", 
              ptr->name,ptr->no,ptr->Math,ptr->Eng);
        if(ptr->llink==head)
         break;
        ptr = ptr ->llink;    
    }
    
    system("pause");
    return 0;
}


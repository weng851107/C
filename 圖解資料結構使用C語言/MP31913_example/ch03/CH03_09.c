#include <stdio.h>
#include <stdlib.h>

int main()
{
    int select,student_no=0;
    float Msum=0,Esum=0;
    
    struct student
    {
        char name[20];
        char no[10];
        struct student *next;
    };
    typedef struct student s_data;
    s_data *ptr;        /* �s������ */
    s_data *head;       /* ��C�}�Y���� */
    s_data *new_data;   /* �s�W�����Ҧb��m���� */

    head = (s_data*) malloc(sizeof(s_data));   /* �s�W��C�}�Y���� */
    ptr = head;    /* �]�w�s�����Ц�m */
    ptr->next = NULL;    /* �ثe�L�U�Ӥ��� */
    do
    {
        printf("(1)�s�W (2)���} =>");
        scanf("%d", &select);
        if (select != 2)
        {
            printf("�m�W �Ǹ� :");
            scanf("%s %s",ptr->name,ptr->no);
            new_data = (s_data*) malloc(sizeof(s_data));    /* �s�W�U�@���� */
            ptr->next = new_data;    /* �s���U�@���� */
            new_data->next = NULL;   /* �U�@������next���]�w��null */
            ptr = new_data;    /* �s�����г]�w���s�����Ҧb��m */
        }
    } while (select != 2);
    
    ptr->next = head;    /* �]�w�s�����бq�Y�}�l */

    putchar('\n');
    ptr=head;
    do
    {
        printf("�m�W�G%s\t�Ǹ�:%s\n", 
        ptr->name,ptr->no);
        ptr = ptr ->next;    /* �Nhead�����U�@���� */
    } while(ptr->next!= head);
    printf("---------------------------------------------------------\n");
    
    system("pause");
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int enqueue(char*, int);    /* �m�J��C��� */
int dequeue();           /* ���X��C��� */
int show();          /* ��ܦ�C��� */

struct student
{
    char name[20];
    int score;
    struct student *next;
};
typedef struct student s_data;

s_data *front =NULL;
s_data *rear = NULL;

int main()
{
    int select, score;
    char name[20];

    do
    {
        printf("(1)�s�J (2)���X (3)��� (4)���} => ");
        scanf("%d", &select);
        switch (select)
        {
            case 1:
                printf("�m�W ���Z�G");
                scanf("%s %d", name, &score);
                enqueue(name, score);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                show();
                break;
        }
    } while (select != 4);

    system("pause");
    return 0;
}


int enqueue(char* name, int score)
{
    s_data *new_data;

    new_data = (s_data*) malloc(sizeof(s_data));  /* �t�m�O���鵹�s���� */
    strcpy(new_data->name, name);   /* �]�w�s��������� */
    new_data->score = score;
    if (rear == NULL)      /* �p�Grear��NULL�A��ܳo�O�Ĥ@�Ӥ��� */
        front = new_data;
    else
        rear->next = new_data;    /* �N�s�����s���ܦ�C���� */

    rear = new_data;    /* �Nrear���V�s�����A�o�O�s����C���� */
    new_data->next = NULL;    /* �s��������L�䥦���� */
}


int dequeue()
{
    s_data *freeme;
    if (front == NULL)
        puts("��C�w�šI");
    else
    {
        printf("�m�W�G%s\t���Z�G%d ....���X\n", front->name, front->score);
        freeme = front;    /* �]�w�N�n���񪺤������� */
        front = front->next;    /* �N��C�e�ݲ��ܤU�@�Ӥ��� */
        free(freeme);    /* ����Ҩ��X���������O���� */
    }
}

int show()
{
    s_data *ptr;
    ptr = front;
    if (ptr == NULL)
        puts("��C�w�šI");
    else
    {
    puts("front -> rear");
        while (ptr != NULL)    /* ��front��rear���X��C */
        {
            printf("�m�W�G%s\t���Z�G%d\n", ptr->name, ptr->score);
            ptr = ptr->next;
        }
    }
}

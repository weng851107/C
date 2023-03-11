#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Node, * ListNode;

typedef struct queue
{
    struct node* head;
    struct node* tail;
} Queue, * QueueList;

Queue* create();
int isEmpty(Queue* QList);
int enqueue(Queue* QList, int value);
int dequeue(Queue* QList);
int peek(Queue* QList);
void list(Queue* QList);
void delete(Queue* QList);

Queue* create()
{
    Queue* QList = (Queue*)malloc(sizeof(Queue));
    QList->head = NULL;
    QList->tail = NULL;
    return QList;
}

int isEmpty(Queue* QList)
{
    assert(QList);
    return (QList->head == NULL)?1:0;
}

int enqueue(Queue* QList, int value)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (QList->head == NULL) {
        QList->head = newnode;
        QList->tail = newnode;
        return 0;
    }

    QList->tail->next = newnode;
    newnode->prev = QList->tail;
    QList->tail = newnode;

    return 0;
}

int dequeue(Queue* QList)
{
    assert(!isEmpty(QList));

    int popdata = QList->head->data;

    if (QList->head == QList->tail) {
        QList->head = NULL;
        QList->tail = NULL;
    }
    else {
        Node* current = QList->head;
        QList->head = current->next;
        free(current);
    }
    return popdata;
}

int peek(Queue* QList)
{
    assert(!isEmpty(QList));
    return QList->head->data;
}

void list(Queue* QList)
{
    Node* current = QList->head;
    while (current != QList->tail) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("%d\n", current->data);
}

void delete(Queue* QList)
{
    if (QList == NULL) {
        return;
    }

    Node* tmpnode = NULL;
    while (QList->head != NULL)
    {
        tmpnode = QList->head;
        QList->head = QList->head->next;
        free(tmpnode);
    }
    QList->head = NULL;
    QList->tail = NULL;
    free(QList);
    QList = NULL;
}

int main(int argc, char *argv[])
{
    int ret = 0;
    int data = 0;
    Queue *qlist = create();

    ret = enqueue(qlist, 50);
    ret = enqueue(qlist, 7);
    ret = enqueue(qlist, -41);
    ret = enqueue(qlist, 10);
    ret = enqueue(qlist, -5);

    list(qlist);
    data = peek(qlist);
    printf("peek: %d\n", data);

    ret = dequeue(qlist);
    ret = dequeue(qlist);

    list(qlist);
    data = peek(qlist);
    printf("peek: %d\n", data);

    ret = dequeue(qlist);
    
    list(qlist);  
    data = peek(qlist);
    printf("peek: %d\n", data);  

    delete(qlist);

    return 0;
}

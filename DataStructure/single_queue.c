#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct queue {
    Node *front;
    Node *rear;
} Queue;

Queue *create()
{
    Queue *QList = (Queue *)malloc(sizeof(Queue));
    QList->front = NULL;
    QList->rear = NULL;
    return QList;
}

int isEmpty(Queue *QList)
{
    return (QList->front == NULL)?(1):(0);
}

void enqueue(Queue *QList, int value)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = value;
    newnode->next = NULL;

    if (QList->front == NULL) {
        QList->front = newnode;
        QList->rear = newnode;
        return;
    }
    else {
        QList->rear->next = newnode;
        QList->rear = newnode;
        return;
    }
}

int dequeue(Queue *QList)
{
    assert(!isEmpty(QList));
    int data = QList->front->data;
    Node *tmpnode = QList->front;
    if (QList->front == QList->rear) {
        QList->front = NULL;
        QList->rear = NULL;
    }
    else {
        QList->front = QList->front->next;
    }
    free(tmpnode);
    return data;
}

void print_qlist(Queue *QList)
{
    Node *current = QList->front;
    while (current != QList->rear) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("%d\n", current->data);
    return;
}

void free_node(Queue *QList)
{
    Node *tmpnode = NULL;
    while (QList->front != QList->rear) {
        tmpnode = QList->front;
        QList->front = QList->front->next;
        free(tmpnode);
    }
    free(QList->front);
    free(QList);
    return;
}

int main(int argc, char *argv[])
{
    int ret = 0;
    int data = 0;
    Queue *qlist = create();

    enqueue(qlist, 50);
    enqueue(qlist, 7);
    enqueue(qlist, -41);
    enqueue(qlist, 10);
    enqueue(qlist, -5);

    print_qlist(qlist);

    ret = dequeue(qlist);
    ret = dequeue(qlist);

    print_qlist(qlist);

    ret = dequeue(qlist);
    
    print_qlist(qlist);  

    free_node(qlist);

    return 0;
}
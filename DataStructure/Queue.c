#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}Node, *ListNode;

typedef struct queue
{
    Node *head;
    Node *tail;
}Queue;

Queue *queue_new(void);
void queue_delete(Queue *qlist);
bool queue_is_empty(const Queue *qlist);
int queue_peek(const Queue *qlist);
bool queue_enqueue(Queue *qlist, int data);
int queue_dequeue(Queue *qlist);

Queue *queue_new(void)
{
    Queue *qlist = (Queue *)malloc(sizeof(Queue));

    qlist->head = NULL;
    qlist->tail = NULL;

    return qlist;
}

void queue_delete(Queue *qlist)
{
    if (qlist == NULL) {
        return;
    }

    Node *current = qlist->head;
    while (current != NULL) {
        Node * tmpnode = current;
        current = current->next;
        free(tmpnode);
    }

    free(qlist);
}

bool queue_is_empty(const Queue *qlist)
{
    assert(qlist);

    return !(qlist->head) ? true : false;
}

int queue_peek(const Queue *qlist)
{
    assert(!queue_is_empty(qlist));

    return qlist->head->data;
}

bool queue_enqueue(Queue *qlist, int data)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (qlist->head == NULL) {
        qlist->head = newnode;
        qlist->tail = newnode;
        return true;
    }

    qlist->tail->next = newnode;
    newnode->prev = qlist->tail;
    qlist->tail = newnode;
    return true;
}

int queue_dequeue(Queue *qlist)
{
    assert(!queue_is_empty(qlist));

    int popdata = qlist->head->data;

    if (qlist->head == qlist->tail) {
        free(qlist->head);
        qlist->head = NULL;
        qlist->tail = NULL;
    }
    else {
        Node *current = qlist->head;
        qlist->head = current->next;
        free(current);
    }

    return popdata;
}

void list(Queue *qlist)
{
    printf("list: ");
    Node *current = qlist->head;
    while (current != qlist->tail) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("%d\n", current->data);
}

int main(int argc, char *argv[])
{
    int ret = 0;
    int data = 0;
    Queue *qlist = queue_new();

    ret = queue_enqueue(qlist, 50);
    ret = queue_enqueue(qlist, 7);
    ret = queue_enqueue(qlist, -41);
    ret = queue_enqueue(qlist, 10);
    ret = queue_enqueue(qlist, -5);

    list(qlist);
    data = queue_peek(qlist);
    printf("peek: %d\n", data);

    ret = queue_dequeue(qlist);
    ret = queue_dequeue(qlist);

    list(qlist);
    data = queue_peek(qlist);
    printf("peek: %d\n", data);

    ret = queue_dequeue(qlist);
    
    list(qlist);  
    data = queue_peek(qlist);
    printf("peek: %d\n", data);  

    queue_delete(qlist);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *create()
{
    return NULL;
}

int isEmpty(Node *sTop)
{
    return (sTop == NULL)?(1):(0);
}

int peek(Node *sTop)
{
    assert(!isEmpty(sTop));

    return (sTop->data);
}

void push(Node **sTop, int value)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = value;
    newnode->next = (*sTop);
    (*sTop) = newnode;
    return;
}

int pop(Node **sTop)
{
    assert(!isEmpty(*sTop));

    int popdata = (*sTop)->data;
    Node *tmpnode = (*sTop);
    (*sTop) = (*sTop)->next;
    return popdata;
}

void print_stack(Node *sTop)
{
    while (sTop != NULL) {
        printf("%d ", sTop->data);
        sTop = sTop->next;
    }
    printf("\n");
    return;
}

void free_node(Node *sTop)
{
    Node *tmpnode = NULL;
    while (sTop != NULL) {
        tmpnode = sTop;
        sTop = sTop->next;
        free(tmpnode);
    }
    return;
}

int main(int argc, char *argv[])
{
    Node* sTop; 
    int input, select; 

    sTop = create(); 

    while(1) { 
        printf("\n\n請輸入選項(-1結束)："); 
        printf("\n(1)插入值至堆疊"); 
        printf("\n(2)顯示堆疊頂端"); 
        printf("\n(3)刪除頂端值"); 
        printf("\n(4)顯示所有內容"); 
        printf("\n"); 
        scanf("%d", &select); 
        
        if(select == -1) 
            break; 

        switch(select) { 
            case 1: 
                printf("\n輸入值："); 
                scanf("%d", &input); 
                push(&sTop, input); 
                break; 
            case 2: 
                printf("\n頂端值：%d", peek(sTop)); 
                break; 
            case 3: 
                pop(&sTop); 
                break; 
            case 4: 
                print_stack(sTop); 
                break; 
            default: 
                printf("\n選項錯誤！"); 
        } 
    } 

    printf("\n"); 

    return 0; 
}

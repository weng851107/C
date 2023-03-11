#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
    int data;
    struct node* next;
} Node, * ListNode;

Node* creates() {
    return NULL;
}

int isEmpty(Node* sTop);
int stacktop(Node* sTop);
Node* add(Node* sTop, int value);
Node* delete(Node* sTop);
void list(Node* sTop);

int isEmpty(Node* sTop)
{
    return (sTop == NULL);
}

int stacktop(Node* sTop)
{
    return sTop->data;
}

Node* add(Node* sTop, int value)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = value;
    newnode->next = sTop;
    sTop = newnode;
    return sTop;
}

Node* delete(Node* sTop)
{
    Node* tmpnode = sTop;
    if (tmpnode == NULL) {
        printf("Stack is NULL\n");
        return NULL;
    }
    sTop = sTop->next;
    free(tmpnode);
    return sTop;
}

void list(Node* sTop)
{
    while (sTop != NULL) {
        printf("%d ", sTop->data);
        sTop = sTop->next;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    Node* sTop; 
    int input, select; 

    sTop = creates(); 

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
                sTop = add(sTop, input); 
                break; 
            case 2: 
                printf("\n頂端值：%d", stacktop(sTop)); 
                break; 
            case 3: 
                sTop = delete(sTop); 
                break; 
            case 4: 
                list(sTop); 
                break; 
            default: 
                printf("\n選項錯誤！"); 
        } 
    } 

    printf("\n"); 

    return 0; 
}
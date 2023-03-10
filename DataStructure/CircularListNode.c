#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node, * ListNode;

void add_node(Node** start, int value) {
    Node* header = *start;
    Node* current = *start;
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = value;
    newnode->next = NULL;

    if (*start == NULL) {
        (*start) = newnode;
        (*start)->next = (*start);
        return;
    }

    while (current->next != header) {
        current = current->next;
    }
    newnode->next = header;
    current->next = newnode;
    return;
}

void insert_node(Node** start, int insert_after_value, int value)
{
    Node* header = *start;
    Node* current = *start;
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = value;
    newnode->next = NULL;

    if ((*start)->data == insert_after_value) {
        newnode->next = (*start)->next;
        (*start)->next = newnode;
        return;
    }

    current = current->next;
    while (current != header) {
        if (current->data == insert_after_value) {
            newnode->next = current->next;
            current->next = newnode;
            return;
        }
        current = current->next;
    }
    return;
}

void delete_node(Node** start, int value)
{
    Node* header = *start;
    Node* current = *start;
    Node* tmpnode = NULL;

    if ((*start)->data == value) {
        tmpnode = (*start);
        (*start) = (*start)->next;
        while (current->next != header) {
            current = current->next;
        }
        current->next = (*start);
        free(tmpnode);
        return;
    }

    current = current->next;
    while (current->next != header) {
        if (current->next->data == value) {
            tmpnode = current->next;
            current->next = current->next->next;
            free(tmpnode);
            return;
        }
        current = current->next;
    }
    return;
}

void print_list(Node* node) {
   
    if (node != NULL) {
        Node* header = node;
        printf("%d ", node->data);
        node = node->next;
        while (node != header) {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
    return;
}

void free_list(Node* node) {
    Node* header = node;
    Node* tmpnode = NULL;
    node = node->next;
    while (node != header) {
        tmpnode = node;
        node = node->next;
        free(tmpnode);
    }
    free(header);
    return;
}

int main()
{
    // create first node "head"
    Node *head = NULL;
    add_node(&head, 5);
    add_node(&head, 128);
    add_node(&head, 41);

    // insert non-exist node, linked list would not have changed
    insert_node(&head, 77, 92);
    // insert after node of data 128
    insert_node(&head, 128, 84); 
    // insert after the last node
    insert_node(&head, 41, 97);

    // delete the first node
    delete_node(&head, 5);
    // delete the node of data 41
    delete_node(&head, 41);
    // delete the last node
    delete_node(&head, 97);

    print_list(head);
    free_list(head);

    return 0;
}



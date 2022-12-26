#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}Node, *ListNode;

void add_node(Node **start, int value);
void insert_node(Node **start, int insert_after_value, int value);
void delete_node(Node **start, int value);
void print_list(Node *node);
void inverse_print_list(Node *node);
void free_list(Node *node);

void add_node(Node **start, int value)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;
    Node *current = *start;

    if (*start == NULL) {
        *start = newnode;
        return;
    }

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newnode;
    newnode->prev = current;
    
    return;
}

void insert_node(Node **start, int insert_after_value, int value)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;
    Node *current = *start;

    while (current != NULL)
    {
        if (current->data == insert_after_value) {
            if (current->next == NULL) {
                current->next = newnode;
                newnode->prev = current;
                return;
            }
            else {
                newnode->next = current->next;
                current->next->prev = newnode;
                newnode->prev = current;
                current->next = newnode;
                return;
            }
        }
        current = current->next;
    }
    
    return;
}

void delete_node(Node **start, int value)
{
    Node *current = *start;
    Node *tmpnode = NULL;

    if (current->data == value) {
        *start = current->next;
        (*start)->prev = NULL;
        free(current);
        return;
    }

    while (current != NULL) {
        if (current->next->data == value) {
            tmpnode = current->next;
            current->next = current->next->next;
            if (current->next != NULL)
                current->next->prev = current;
            free(tmpnode);
            return;
        }
        current = current->next;
    }
    
    return;
}

void print_list(Node *node)
{
    printf("list: ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");

    return;
}

void inverse_print_list(Node *node)
{
    printf("inverse list: ");

    while (node->next != NULL) {
        node = node->next;
    }
    
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->prev;
    }

    printf("\n");

    return;
}

void free_list(Node *node)
{
    while (node != NULL) {
        Node *tmpnode = node;
        node = node->next;
        free(tmpnode);
    }

    return;
}

int main(int argc, char *argv[])
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

    inverse_print_list(head);

    free_list(head);

    return 0;
}

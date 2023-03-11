#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} Node, * ListNode;

typedef int (*cmp_fn)(int a, int b);

typedef struct tree
{
    Node* root;
    cmp_fn cmp;
} Tree;

static int cmp(int a, int b)
{
    if (a > b) {
        return 1;
    }
    else if (a == b) {
        return 0;
    }
    else {
        return -1;
    }
}

Tree* tree_create(cmp_fn cmp);
void tree_delete(Tree* TList);
int tree_isEmpty(Tree* TList);
int tree_height(Tree* TList);
int tree_contain(Tree* TList, int value);
int tree_min(Tree* TList);
int tree_max(Tree* TList);
int tree_insert(Tree* TList, int value);
int tree_remove(Tree* TList, int value);
void preorder(Node* node);
void inorder(Node* node);
void postorder(Node* node);

Tree* tree_create(cmp_fn cmp)
{
    Tree* TList = (Tree*)malloc(sizeof(Tree));
    TList->root = NULL;
    TList->cmp = cmp;
    return TList;
}

static void _tree_delete(Node* node)
{
    if (node == NULL) {
        return;
    }

    _tree_delete(node->left);
    _tree_delete(node->right);
    free(node);

    return;
}

void tree_delete(Tree* TList)
{
    if (TList == NULL) {
        return;
    }
    _tree_delete(TList->root);
    free(TList);
    return;
}

int tree_isEmpty(Tree* TList)
{
    assert(TList);
    return (TList->root == NULL)?(1):(0);
}

static int _tree_height(Node* node)
{
    if (node == NULL) {
        return 0;
    }

    int l = (node->left != NULL)?_tree_height(node->left):0;
    int r = (node->right != NULL)?_tree_height(node->right):0;
    int h = (l>r)?(l):(r);

    return h+1;
}

int tree_height(Tree* TList)
{
    assert(TList);
    return _tree_height(TList->root);
}

static int _tree_contain(Node* node, cmp_fn cmp, int value)
{
    if (node == NULL) {
        return 0;
    }

    if (cmp(node->data, value) > 0) {
        return _tree_contain(node->left, cmp, value);
    }
    else if (cmp(node->data, value) < 0) {
        return _tree_contain(node->right, cmp, value);
    }
    else {
        return 1;
    }
}

int tree_contain(Tree* TList, int value)
{
    assert(TList);
    return _tree_contain(TList->root, TList->cmp, value);
}

static int _tree_min(Node* node)
{
    Node* minnode = node;
    while (minnode->left != NULL)
    {
        minnode = minnode->left;
    }
    return minnode->data;
}

int tree_min(Tree* TList)
{
    assert(TList);
    return _tree_min(TList->root);
}

static int _tree_max(Node* node)
{
    Node* maxnode = node;
    while (maxnode->right != NULL)
    {
        maxnode = maxnode->right;
    }
    return maxnode->data;
}

int tree_max(Tree* TList)
{
    assert(TList);
    return _tree_max(TList->root);
}

static int _tree_insert(Node** node, int value, cmp_fn cmp)
{
    if (*node == NULL) {
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;
        *node = newnode;
        return 1;
    }
    else if (cmp((*node)->data, value) >= 0) {
        _tree_insert(&(*node)->left, value, cmp);
    }
    else if (cmp((*node)->data, value) < 0) {
        _tree_insert(&(*node)->right, value, cmp);
    }
}

int tree_insert(Tree* TList, int value)
{
    assert(TList);
    return _tree_insert(&TList->root, value, TList->cmp);
}

static int _tree_remove(Node** node, int value, cmp_fn cmp)
{
    if (*node == NULL) {
        return 0;
    }

    if (cmp((*node)->data, value) == 0) {
        if ((*node)->left == NULL) {
            Node* tmpnode = *node;
            *node = (*node)->right;
            free(tmpnode);
        }
        else if ((*node)->right == NULL) {
            Node* tmpnode = *node;
            *node = (*node)->left;
            free(tmpnode);
        }
        else {
            Node* tmpnode = *node;
            *node = (*node)->right;
            free(tmpnode);
            _tree_remove(node, _tree_min(*node), cmp);
        }
        return 1;
    }
    else if (cmp((*node)->data, value) > 0) {
        return _tree_remove(&(*node)->left, value, cmp);
    }
    else {
        return _tree_remove(&(*node)->right, value, cmp);
    }
}

int tree_remove(Tree* TList, int value)
{
    if (tree_isEmpty(TList)) {
        return 0;
    }
    return _tree_remove(&TList->root, value, TList->cmp);
}

void preorder(Node* node)
{
    if (node != NULL) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
        return;
    }
}

void inorder(Node* node)
{
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
        return;
    }
}

void postorder(Node* node)
{
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
        return;
    }
}

int main(int argc, char *argv[])
{
    int ret = 0;

    Tree *binarytree = tree_create(cmp);
    
    ret = tree_insert(binarytree, 50);
    ret = tree_insert(binarytree, 23);
    ret = tree_insert(binarytree, 10);
    ret = tree_insert(binarytree, -5);
    ret = tree_insert(binarytree, 7);
    ret = tree_insert(binarytree, 20);
    ret = tree_insert(binarytree, 75);
    ret = tree_insert(binarytree, 67);
    ret = tree_insert(binarytree, 88);
    ret = tree_insert(binarytree, 91);
    ret = tree_insert(binarytree, 62);
    ret = tree_insert(binarytree, 1);
    ret = tree_insert(binarytree, -8);
    ret = tree_insert(binarytree, -45);

    printf("inorder: ");
    inorder(binarytree->root);
    printf("\n");

    int height = tree_height(binarytree);
    printf("Tree height = %d\n", height);

    int min = tree_min(binarytree);
    printf("Tree min = %d\n", min);

    int max = tree_max(binarytree);
    printf("Tree max = %d\n", max);

    printf("88 is in the tree: %d\n", tree_contain(binarytree, 88));
    printf("0 is in the tree: %d\n", tree_contain(binarytree, 0));

    printf("remove 91, \n");
    ret = tree_remove(binarytree, 91);
    printf("inorder: ");
    inorder(binarytree->root);
    printf("\n");

    printf("remove 70, \n");
    ret = tree_remove(binarytree, 70);
    printf("inorder: ");
    inorder(binarytree->root);
    printf("\n");

    printf("delete tree\n");
    tree_delete(binarytree);

    return 0;
}



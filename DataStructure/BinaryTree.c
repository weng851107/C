#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}Node;

typedef int (*cmp_fn)(int a, int b);

typedef struct tree
{
    Node *root;
    cmp_fn cmp;
}Tree;

static int cmp(int a, int b)
{
    if (a == b) {
        return 0;
    }
    else if (a < b) {
        return -1;
    }
    else if (a > b) {
        return 1;
    }
}

Tree *tree_new(cmp_fn cmp);
void tree_delete(Tree *Tlist);

bool tree_is_empty(const Tree *Tlist);
int tree_height(const Tree *Tlist);
bool tree_contain(Tree *Tlist, int value);
int tree_min(const Tree *Tlist);
int tree_max(const Tree *Tlist);
bool tree_insert(Tree *Tlist, int value);
bool tree_remove(Tree *Tlist, int value);

void preorder(Node *node);
void inorder(Node *node);
void postorder(Node *node);

Tree *tree_new(cmp_fn cmp)
{
    Tree *Tlist = (Tree *)malloc(sizeof(Tree));

    Tlist->root = NULL;
    Tlist->cmp = cmp;

    return Tlist;
}

static void _tree_delete(Node *node)
{
    if (node == NULL) {
        return;
    }

    _tree_delete(node->left);
    _tree_delete(node->right);
    free(node);

    return;
}

void tree_delete(Tree *Tlist)
{
    if (Tlist == NULL) {
        return;
    }

    _tree_delete(Tlist->root);
    free(Tlist);

    return;
}

bool tree_is_empty(const Tree *Tlist)
{
    assert(Tlist);

    return !(Tlist->root) ? true : false;
}

static int _tree_height(const Node *node)
{
    if (node == NULL) {
        return 0;
    }

    int l = (node->left) ? _tree_height(node->left) : 0;
    int r = (node->right) ? _tree_height(node->right) : 0;

    int h = (l > r) ? l : r;

    return h + 1;
}

int tree_height(const Tree *Tlist)
{
    assert(Tlist);

    return _tree_height(Tlist->root);
}

static bool _tree_contain(Node *node, int value, cmp_fn cmp)
{
    if (node == NULL) {
        return false;
    }

    if (cmp(value, node->data) == 0) {
        return true;
    }
    else if (cmp(value, node->data) < 0) {
        return _tree_contain(node->left, value, cmp);
    }
    else if (cmp(value, node->data) > 0) {
        return _tree_contain(node->right, value, cmp);
    }

    return false;
}

bool tree_contain(Tree *Tlist, int value)
{
    assert(Tlist);

    return _tree_contain(Tlist->root, value, Tlist->cmp);
}

int tree_min(const Tree *Tlist)
{
    assert(Tlist);

    Node *minnode = Tlist->root;
    while (minnode->left != NULL) {
        minnode = minnode->left;
    }

    return minnode->data;
}

int tree_max(const Tree *Tlist)
{
    assert(Tlist);

    Node *maxnode = Tlist->root;
    while (maxnode->right != NULL) {
        maxnode = maxnode->right;
    }

    return maxnode->data;
}

static bool _tree_insert(Node **node, int value, cmp_fn cmp)
{
    if (*node == NULL) {
        Node *newnode = (Node *)malloc(sizeof(Node));
        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;
        *node = newnode;
        return true;
    }

    if (cmp(value, (*node)->data) <= 0) {
        return _tree_insert(&(*node)->left, value, cmp);
    }
    else if (cmp(value, (*node)->data) > 0) {
        return _tree_insert(&(*node)->right, value, cmp);
    }

    return true;
}

bool tree_insert(Tree *Tlist, int value)
{
    assert(Tlist);

    return _tree_insert(&(Tlist->root), value, Tlist->cmp);
}

static int _node_min(Node *node)
{
    assert(node);

    if (node->left != NULL) {
        return _node_min(node->left);
    }

    return node->data;
}

static bool _tree_remove(Node **node, int value, cmp_fn cmp)
{
    if (*node == NULL) {
        return false;
    }

    if (cmp(value, (*node)->data) == 0) {
        if ((*node)->left == NULL) {
            Node *tmpnode = (*node)->right;
            free(*node);
            *node = tmpnode;
            return true;
        }
        else if ((*node)->right == NULL) {
            Node *tmpnode = (*node)->left;
            free(*node);
            *node = tmpnode;
            return true;
        }
        else {
            int min = _node_min((*node)->right);
            (*node)->data = min;
            return _tree_remove(&(*node)->right, min, cmp);
        }
    }
    else if (cmp(value, (*node)->data) < 0) {
        return _tree_remove(&(*node)->left, value, cmp);
    }
    else if (cmp(value, (*node)->data) > 0) {
        return _tree_remove(&(*node)->right, value, cmp);
    }

    return false;
}

bool tree_remove(Tree *Tlist, int value)
{
    if (tree_is_empty(Tlist)) {
        return false;
    }

    return _tree_remove(&(Tlist->root), value, Tlist->cmp);
}

void preorder(Node *node)
{
    if (node != NULL) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(Node *node)
{
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void postorder(Node *node)
{
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

int main(int argc, char *argv[])
{
    int ret = 0;

    Tree *binarytree = tree_new(cmp);
    
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


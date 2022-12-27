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
            int min = tree_min((*node)->right);
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

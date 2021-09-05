/*************************************************************************
	> File Name: 6.binary_tree.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Thu 19 Nov 2020 07:26:24 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//节点
typedef struct Node {
    int data;
    struct Node *lchild, *rchild;//二叉 指针域 左孩子 右孩子
} Node;

typedef struct tree {
    Node *root;//根
    int n;//节点个数
} Tree;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}

Tree *getNewTree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

void clearNode(Node *node) {
    if (node == NULL) return ;
    clearNode(node->lchild);
    clearNode(node->rchild);
    free(node);
    return ;
}

void clear(Tree *tree) {
    if (tree == NULL) return ;
    clearNode(tree->root);
    free(tree);
    return ;
}

Node *insert_node(Node *root, int val, int *flag) {
    if (root == NULL){
        *flag = 1;
        return getNewNode(val);
    }
    if (root->data == val) return root;
    if (val < root->data) root->lchild = insert_node(root->lchild, val, flag);
    else root->rchild = insert_node(root->rchild, val, flag);
    return root;
}

//二叉查找树 左孩子小于根节点 右孩子大于根节点
void insert(Tree *tree, int val) {
    int flag = 0;//传出参数
    tree->root = insert_node(tree->root, val, &flag);
    tree->n += flag;
    return ;
}

void pre_order_node(Node *node) {
    if (node == NULL) return ;
    printf("%d ", node->data);
    pre_order_node(node->lchild);
    pre_order_node(node->rchild);
    return ;
}

//前序遍历
void pre_order(Tree *tree) {
    if (tree == NULL) return ;
    printf("pre_order :");
    pre_order_node(tree->root);
    printf("\n");
    return;
}

void in_order_node(Node *node) {
    if (node == NULL) return ;
    in_order_node(node->lchild);
    printf("%d ", node->data);
    in_order_node(node->rchild);
    return ;
}

//中序遍历
void in_order(Tree *tree) {
    if (tree == NULL) return ;
    printf("in_order :");
    in_order_node(tree->root);
    printf("\n");
    return;
}

void post_order_node(Node *node) {
    if (node == NULL) return ;
    post_order_node(node->lchild);
    post_order_node(node->rchild);
    printf("%d ", node->data);
    return ;
}

//后序遍历
void post_order(Tree *tree) {
    if (tree == NULL) return ;
    printf("post_order :");
    post_order_node(tree->root);
    printf("\n");
    return;
}


//打印广义表
void output_node(Node *root) {
    if (root == NULL) return ;
    printf("%d", root->data);
    if (root->lchild == NULL && root->rchild == NULL) return;
    printf("(");
    output_node(root->lchild);
    printf(", ");
    output_node(root->rchild);
    printf(")");
    return ;
}

void output(Tree *tree) {
    if (tree == NULL) return ;
    printf("tree(%d) : ", tree->n);
    output_node(tree->root);
    printf("\n");
    return ;
}

int main() {
    srand(time(0));
    Tree *tree =getNewTree();
    #define max_op 10
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        insert(tree, val);
        output(tree);
    }
    pre_order(tree);
    in_order(tree);
    post_order(tree);
    #undef max_op
    clear(tree);
    return 0;
}

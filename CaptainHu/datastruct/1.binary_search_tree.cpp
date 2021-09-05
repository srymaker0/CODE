/*************************************************************************
	> File Name: binary_search_tree.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 19 Dec 2020 05:53:43 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define KEY(n) (n ? n->key : 0)
#define SIZE(n) (n ? n->size : 0)
#define L(n) (n ? n->lchild : NULL)

typedef struct Node {
    int key, size;     //size用于记录节点数量 为了解决找到排名第k位元素问题
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->size = 1;
    p->lchild = p->rchild = NULL;
    return p;
}

void update_size(Node *root) {
    root->size = SIZE(root->lchild) + SIZE(root->rchild) + 1;    //左子树节点数量+右子树节点数量+根节点
    return ;
}

int search(Node *root, int val) {
    if (root == NULL) return 0;
    if (root->key == val) return 1;
    if (val < root->key) return search(root->lchild, val);
    return search(root->rchild, val);
}

int search_k(Node *root, int k) {
    if (root == NULL) return -1;
    if (SIZE(L(root)) == k - 1) return root->key;   //SIZE(L(root)) 表示root左子树的大小 节点数量
    if (k <= SIZE(L(root))) {
        return search_k(root->lchild, k);
    }
    return search_k(root->rchild, k - SIZE(L(root)) - 1);
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (root->key == key) return root;
    //插入操作有可能改变当前节点左子树的地址 因此要将返回值传给lchild
    if (key < root->key) root->lchild = insert(root->lchild,key);
    else root->rchild = insert(root->rchild, key);   
    update_size(root);        //更新节点数量 
    return root;
}

//找root节点的前驱值  
//为左子树中的最大值 有bug   
//度为1的节点也有前驱  要改的话判断一下是否是度为1的节点再去找前驱
//但是对于整体来说并没有bug 因为度为0和度为1的节点都会被先处理掉
Node *predecessor(Node *root) {  //假设root是度为2的节点  前驱一定是root左子树中最大的值
    Node *temp = root->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}


Node *erase(Node *root, int val) {
    if (root == NULL) return NULL;
    if (val < root->key) {
        root->lchild = erase(root->lchild, val);
    } else if (val > root->key) {
        root->rchild = erase(root->rchild, val);
    } else {
        /*删除度为0的节点
        if (root->lchild == NULL && root->rchild == NULL) {
            free(root);
            return NULL;
        } else 
        */
        //可以将删除度为0的节点合并到这段代码中 因为逻辑都一样
        if (root->lchild == NULL || root->rchild == NULL) {  //删除度为1的节点 
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);   //删除父节点 让孤儿子树挂到父节点上去
            return temp;
        } else {
            //删除度为2的节点  这部分可以查阅笔记 
            Node *temp = predecessor(root);  //先找到前驱的值
            root->key = temp->key;  //把前驱的值覆盖到root的键值
            root->lchild = erase(root->lchild, temp->key);  //接着删除左子树上的前驱的值
        }
    }
    update_size(root);
    return root;
}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void print(Node *root) {
    printf("(%d[%d], %d, %d)\n", 
            KEY(root),SIZE(root),
            KEY(root->lchild), KEY(root->rchild)
    );
    return ;
}

void output(Node *root) {
    if (root == NULL) return ;
    output(root->lchild);
    print(root);
    output(root->rchild);
    return ;
}

void output_k(Node *root, int k) {
    if (k == 0 || root == NULL) return ;
    if (k <= SIZE(L(root))) {
        output_k(root->lchild, k);
    } else {
        output(root->lchild);
        print(root);
        output_k(root->rchild, k - SIZE(L(root)) - 1);
    }
    return ;
}

int main() {
    int op, val;
    Node *root = NULL;
    while (~scanf("%d%d", &op, &val)) {
        switch(op) {
            case 0: printf("search %d, result : %d\n", val, search(root, val)); break;
            case 1: root = insert(root, val); break;
            case 2: root = erase(root, val); break;
            case 3: printf("search k = %d, result : %d\n", val, search_k(root, val)); break;
            case 4: {
                printf("output top-%d element\n", val);
                output_k(root, val);
                printf("----------------\n");
                } break;
        }
        if (op == 1 || op == 2) {
            output(root);
            printf("----------------\n");
        }
    }

    return 0;
}

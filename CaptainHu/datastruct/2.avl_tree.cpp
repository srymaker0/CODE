/************************************************************************
	> File Name: avl_tree.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 19 Dec 2020 06:02:38 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define L(n) (n->lchild)
#define R(n) (n->rchild)
#define H(n) (n->h)


typedef struct Node {
    int key, h; //h 表示树高
    struct Node *lchild, *rchild;
} Node;

Node __NIL; //虚拟节点 方便我们操作  正常情况下我们不能访问NULL->lchild 这样不合法   但是访问一个假的空节点是合法的
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL() {
    NIL->key = 0, NIL->h = 0;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->h = 1;
    p->lchild = p->rchild = NIL;
    return p;
}

void update_height(Node *root) {
    root->h = (H(L(root)) > H(R(root)) ? H(L(root)): H(R(root))) + 1;
    return ;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;  //temp指向旋转完以后的根节点地址 左旋以后的根节点是原根节点的右孩子
    root->rchild = temp->lchild; //这部分只能细品了 
    temp->lchild = root;
    update_height(root);  //要先更新原根节点的树高
    update_height(temp);  //然后再更新新节点的树高
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    update_height(root);
    update_height(temp);
    return temp;
}


//维护函数
Node *maintain(Node *root) {
    if (abs(H(L(root)) - H(R(root))) <= 1) return root;
    if (root->lchild->h > root->rchild->h) { //第一个字母是L
        if (root->lchild->lchild->h < root->lchild->rchild->h) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root); //最后一次操作都是右旋
    } else {  // 第一个字母是R
        if (root->rchild->rchild->h < root->rchild->lchild->h) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
    return root;
}


Node *insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;  //不插入重复元素
    if (key < root->key) {
        root->lchild = insert(root->lchild, key);
    } else {
        root->rchild = insert(root->rchild, key);
    }
    update_height(root);
    return maintain(root);      //此乃回溯过程  在这里维护  因为要维护回溯过程中第一个d发生失衡的点  返回的是经过平衡调整以后的根节点地址
}

//此处有问题 前驱的终止条件应该为！= NIL
Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    //while (temp->rchild) temp = temp->rchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key) {
    if (root == NIL) return NIL;
    if (key < root->key) {
        root->lchild = erase(root->lchild, key);
    } else if (key > root->key) {
        root->rchild = erase(root->rchild, key);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild != NIL ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    update_height(root);
    return maintain(root);
}

void clear(Node *root) {
    if (root == NIL); return ;
    clear(root->lchild);
    clear(root->rchild);
    clear(root);
    return ;
}

void print(Node *root) {
    printf("(%d[%d], %d, %d)\n",
        root->key, root->h,
        root->lchild->key,
        root->rchild->key 
    );
    return ;
}


//先序遍历
void output(Node *root) {
    if (root == NIL) return ;
    print(root);
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 0: root = erase(root, val); break;
            case 1: root = insert(root, val); break;
        }
        output(root);
        printf("-------------\n");
    }
    return 0;
}

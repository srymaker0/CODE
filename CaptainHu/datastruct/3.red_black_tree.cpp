/*************************************************************************
	> File Name: red_black_tree_insert.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 20 Dec 2020 03:56:45 PM CST
 ************************************************************************/


#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int key;
    int color;//0 red, 1 black, 2 double black
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL() {
    NIL->key = 0;
    NIL->color = 1;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->color = 0;
    p->lchild = p->rchild = NIL;
    return p;
}

//判断根节点下有没有红色子孩子
int has_red_child(Node *root) {
    return root->lchild->color == 0 || root->rchild->color == 0;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

Node *insert_maintain(Node *root) {
    if (!has_red_child(root)) return root;
    int flag = 0;
    // 只要当前节点的两个子孩子是红色 就把这个三元组改成红-黑-黑 注意goto语句
    // 就算不发生冲突  这样改也没关系  船长偷懒了 没有判断究竟有没有发生双红的冲突
    if (root->lchild->color == 0 && root->rchild->color == 0) goto insert_end;
    // 情况2
    if (root->lchild->color == 0 && has_red_child(root->lchild)) flag = 1;  // LL 和 LR
    if (root->rchild->color == 0 && has_red_child(root->rchild)) flag = 2;  // RR 和 RL
    if (flag == 0) return root;                                             // 没有发生冲突
    if (flag == 1) {
        if (root->lchild->rchild->color == 0) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
        /*
        root->color = 0;
        root->lchild->color = root->rchild->color = 1; 
        return root;
        */
    } else {
        if (root->rchild->lchild->color == 0) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
        /*
        root->color = 0;
        root->lchild->color = root->rchild->color = 1;
        return root; 
        */
    }    
insert_end:
    root->color = 0;
    root->lchild->color = root->rchild->color = 1;
    return root;
}

Node *__insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (key < root->key) {
        root->lchild = __insert(root->lchild, key);
    } else {
        root->rchild = __insert(root->rchild, key);
    }
    return insert_maintain(root);
}

Node *insert(Node *root, int key) {
    root = __insert(root, key);
    root->color = 1;
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase_maintain(Node *root) {
    // 站在父节点向下看 看有没有双重黑
    if (root->lchild->color != 2 && root->rchild->color != 2) return root;
    // 代码到这里说明有双重黑节点 
    // 一、判断双重黑兄弟节点是否为红色的情况 (特殊情况)
    if (has_red_child(root)) {                      // 若是红色
        int flag = 0;                               // 用于标记旋转方向 
        root->color = 0;                            // 原根节点改为红色
        if (root->lchild->color == 0) {             // 若左子树是红色 则右旋
            root = right_rotate(root); flag = 1;
        } else {
            root = left_rotate(root); flag = 2;
        }
        root->color = 1;                            //新根节点改为黑色
        // 把兄弟节点是红色的情况转化成兄弟节点是黑色的情况  递归向下调整
        if (flag == 1) root->rchild = erase_maintain(root->rchild);
        else root->lchild = erase_maintain(root->lchild);
        return root;
    }
    // 二、双重黑兄弟节点为黑色
    // 情况1
    // 双重黑在左侧且右侧的兄弟节点的子孩子没有红色节点 或者 双重黑在右侧且左侧的兄弟节点的子孩子没有红色节点
    if ((root->lchild->color == 2 && !has_red_child(root->rchild)) ||
        (root->rchild->color == 2 && !has_red_child(root->lchild))) {
            root->lchild->color -= 1;
            root->rchild->color -= 1;
            root->color += 1;
            return root;
        }
    // 情况2 3
    if (root->lchild->color == 2) {
        root->lchild->color -= 1;                           // 解决双黑
        // 必须这么判断  不能写成root->rchild->rchild->color == 1 因为节点在程序实现过程中变量有可能是双重黑 需要考虑NIL节点
        if (root->rchild->rchild->color != 0) {             // 双黑兄弟节点的右子树不是红色  严格的RL类型
            root->rchild->color = 0;                        // 原根的颜色变为红色
            root->rchild = right_rotate(root->rchild);      // 小右旋
            root->rchild->color = 1;                        // 新根的颜色变为黑色
        }
        // RR
        root = left_rotate(root);                           // 左子树是双重黑 最后一定会大左旋
        root->color = root->lchild->color;                  // 新根节点变成原根节点颜色  原根节点下沉到左子树中了
    } else {
        root->rchild->color -=1;
        // LR
        if (root->lchild->lchild->color != 0) {
            root->lchild->color = 0;
            root->lchild = left_rotate(root->lchild);
            root->lchild->color = 1;
        }
        // LL
        root = right_rotate(root);
        root->color = root->rchild->color;
    }
    root->lchild->color = root->rchild->color = 1;          // 两个子节点强制变成黑色
    return root;
}

Node *__erase(Node *root, int key) {
    if (root == NIL) return NIL;
    if (key < root->key) {
        root->lchild = __erase(root->lchild, key);
    } else if (key > root->key) {
        root->rchild = __erase(root->rchild, key);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            // !注意，这里对应着4种情况
            Node *temp = root->lchild != NIL ? root->lchild : root->rchild;
            temp->color += root->color;     // 把当前节点的颜色加到唯一子孩子h身上去
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);
        }
    }
    return erase_maintain(root);
}

Node *erase(Node *root, int key) {
    root = __erase(root, key);
    root->color = 1;                        // 强制把root颜色改为黑色
    return root;
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void print(Node *root) {
    printf("(%d| %d, %d, %d)\n",
        root->color, root->key,
        root->lchild->key,
        root->rchild->key         
    );
    return ;
}


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
    while(~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 1: root = insert(root, val); break;
            case 2: root = erase(root, val); break;
        }
        output(root);
        printf("------------\n");
    }
    return 0;
}

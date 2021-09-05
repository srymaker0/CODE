/*************************************************************************
	> File Name: 4.haffman.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 26 Dec 2020 04:47:32 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

typedef struct Node {
    char ch;  //当前节点代表字符
    double p; //当前节点概率值  因为两个节点合成一个节点  两个节点的概率合到一个节点 
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(char ch, double per) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = ch;
    p->p = per;
    p->lchild = p->rchild = NULL;
    return p;
}

//合并两个节点
Node *CombinNode(Node *a, Node *b) {
    Node *p= getNewNode(0, a->p + b->p);
    p->lchild = a;
    p->rchild = b;
    return p;
}

void pick_min(Node **arr, int n) {
    for (int j = n - 1; j >= 0; --j) {
        if (arr[n]->p > arr[j]->p) {
            swap(arr[n], arr[j]);
        }
    }
    return ;
}

Node *getHaffmanTree(Node **arr, int n) {
    // n个节点 合并n - 1 次  48 49 50 可以优化 可以用堆去存储 
    for (int i = 1; i < n; i++) {
        pick_min(arr, n - i); //选出最小值放到数组的最后一位 
        pick_min(arr, n - i - 1); //选出次小值放到数组的倒数第二位
        //倒数第二位上的节点被覆盖为概率最小的两个节点之和
        arr[n - i - 1] = CombinNode(arr[n - i], arr[n - i - 1]); 
    }
    return arr[0];
} 


// 参数 结点 编码数组 树高
void __output_encode(Node *root, char *str, int k) {
    str[k] = 0;
    //当前节点是叶子节点 直接输出
    if (root->lchild == NULL && root->rchild == NULL) {
        printf("%c %s\n", root->ch, str);
        return ;
    }
    str[k] = '0';
    __output_encode(root->lchild, str, k + 1);
    str[k] = '1';
    __output_encode(root->rchild, str, k + 1);
    return ;
}

void output_encode(Node *root) {
    char str[100];
    __output_encode(root, str, 0);
    return ;
}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
}

int main() {
    int n; //表示有n个字符
    Node **arr; //二维数组第i位存储的是相关的节点
    scanf("%d", &n);
    arr = (Node **)malloc(sizeof(Node *) * n);
    for (int i = 0; i < n; i++) {
        char ch[10]; //读入字符 减少读入字符时出错的可能性
        double p;
        scanf("%s%lf", ch, &p);
        arr[i] = getNewNode(ch[0], p);
    }
    Node *root = getHaffmanTree(arr, n);
    output_encode(root);
    clear(root);
    free(arr);
    return 0;
}

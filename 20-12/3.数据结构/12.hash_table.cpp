/*************************************************************************
	> File Name: 12.hash_table.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Fri 27 Nov 2020 10:47:22 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    char *str;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node **data;//哈希表(也是顺序表)里面存储的是一个地址 地址所指向的类型是Node*类型
    int size;
} HashTable;

Node *init_node(char *str, Node *head) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str);
    p->next = head;
    return p;
}

HashTable *init_hashtable(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    //利用率和哈希函数冲突概率有关 我们把n扩大一倍 使其只有50%利用率
    h->size = n << 1;//哈希表的空间利用率不可能达到100% 一般的空间利用率为50%——90% 工业上达到70%才可以使用
    h->data = (Node **)calloc(h->size,sizeof(Node *));//数据的每一位都为0值 都是空地址
    return h;
}

int BKDRHash(char *str) {
    //seed是一个素数就行
    int seed = 31, hash = 0;
    for (int i = 0; str[i]; i++) hash = hash * seed + str[i];
    //hash有可能超出整型范围 变成一个负数 
    //这里的0x7fffffff 表示的是符号位为0 其余位为1的数 
    return hash & 0x7fffffff;    
}

int insert(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    //将字符串插入到下标为ind的这个位置所对应的链表中
    h->data[ind] = init_node(str, h->data[ind]);
    return 1;
}

int search(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    //p指向ind这位链表里存的头节点
    Node *p = h->data[ind];
    //沿着链表的头节点 遍历链表的每一位 strcmp返回值不为0时代表没找到
    while (p && strcmp(p->str, str)) p = p->next;
    //如果p 不等于NULL 说明是因为strcmp返回值为0退出的循环  也就是说找到了值
    return p != NULL;
}

void clear_node(Node *node) {
    if (node == NULL) return ;
    Node *p = node, *q;
    while (p) {
        q = p->next;
        free(p->str);
        free(p);
        p = q;
    }
    return ;
}

void clear_hashtable(HashTable *h) {
    if (h == NULL) return ;
    for (int i = 0; i < h->size; i++) {
        clear_node(h->data[i]);
    }
    free(h->data);
    free(h);
    return ;
}

int main() {
    int op;
    #define max_n 100
    char str[max_n + 5] = {0};
    HashTable *h = init_hashtable(max_n + 5);
    while (~scanf("%d%s", &op, str)) {
        switch (op) {
            case 0:
                printf("insert %s to HashTable\n", str);
                insert(h, str);
            break;
            case 1:
            printf("search %s from HashTable result = %d\n", str, search(h, str));
            break;
        }
    }
    #undef max_n
    clear_hashtable(h);
    return 0;
}

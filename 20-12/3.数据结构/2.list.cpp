/*************************************************************************
	> File Name: 2.list.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 12 Nov 2020 06:16:35 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)

//链表的结构定义
typedef struct ListNode {
    int data;
    struct ListNode *next;//struct 结构体类型关键字  虽然我们重命名了ListNode 但是12行还没有生效
} ListNode;

//链表整体的结构定义
typedef struct List {
    //ListNode *head;//头指针 因为插入的原则是 在待插入元素前进行插入 当链表为空时 很不好操作
    ListNode head;//虚拟头节点 为了方便插入和删除第一个元素  
    int length;
} List;

//链表的结构操作

//初始化
ListNode *getNewNode(int);
List *getLinkList();
void clear_node(ListNode *);
void clear(List*);
int insert(List *, int, int);
int erase(List *, int);
void output(List *);
void reverse(List *);

int main() {
    srand(time(0));
    #define max_op 20
    List *l = getLinkList();
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        int ind = rand() % (l->length + 3) - 1;
        int op = rand() % 4;
        switch (op) {
            case 0:
            case 1: {
                printf("insert %d at %d to List = %d\n", val, ind, insert(l, ind, val));
            } break;
            case 2: {
                printf("erase a iterm at %d from List = %d\n", ind, erase(l, ind));
            } break;
            case 3: {
                printf(GREEN("reverse the list!\n"));
                reverse(l);
            } break;
        }
        output(l), printf("\n");
    } 
    #undef max_op
    clear(l);
    return 0;
}


ListNode *getNewNode(int val) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = val;
    p->next = NULL;
    return p;
}

List *getLinkList() {
    List *l = (List *)malloc(sizeof(List));
    l->head.next = NULL;//因为虚拟头节点是一个没有实际意义的节点 所以虚拟头节点指向的后面的那个节点才是真的头节点
    l->length = 0;
    return l;
}

int insert(List *l, int ind, int val) {
    if (l == NULL) return 0;
    if (ind < 0 || ind > l->length) return 0;//下标是0 ~ length-1
    ListNode *p = &(l->head), *node = getNewNode(val);
    while (ind--) p = p->next;
    node->next = p->next;
    p->next = node;
    l->length += 1;
    return 1;
}

int erase(List *l, int ind) {
    if (l == NULL) return 0;
    if (ind < 0 || ind >= l->length) return 0;
    ListNode *p = &(l->head), *q;
    while (ind--) p = p->next;
    q = p->next;
    p->next = q->next;
    free(q);
    l->length -= 1;
    return 1;
}

//链表原地翻转 先将头节点指向空 用p 和 q去维护整个链表
void reverse(List *l) {
    if (l == NULL) return;
    ListNode *p = l->head.next, *q;
    l->head.next = NULL;
    while (p) {
        q = p->next;
        p->next = l->head.next;
        l->head.next = p;
        p = q;
    }
    return ;
}


void output(List *l) {
    if (l == NULL) return ;
    printf("List(%d) = [", l->length);
    for (ListNode *p = l->head.next; p; p = p->next) {
        printf("%d->", p->data);
    }
    printf("NULL]\n");
    return ;
}

void clear_node(ListNode *node) {
    if (node == NULL) return;
    free(node);
    return;
}

void clear(List *l) {
    if (l == NULL) return;
    ListNode *p = l->head.next, *q;//q中间变量
    while (p) {
        q = p->next;
        clear_node(p);
        p = q;
    }
    free(l);
    return ;
}



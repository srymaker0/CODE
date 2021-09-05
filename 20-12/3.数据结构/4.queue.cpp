#include <stdio.h>
#include <stdlib.h>

#include <time.h>
typedef struct Queue {
    int *data;
    int head, tail, length;//length 容量
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->length = n;
    q->head = q->tail = 0;//tail有两种实现方式 1.指向最后一个元素的地址 2.指向最后一个元素的下一个地址
    return q;
}

int front(Queue *q) {
    //if (q == NULL) return 0;
    return q->data[q->head];
}

int empty(Queue *q) {
    return q->head == q->tail; //tail 指向的是最后一个元素的下一个
}

int push(Queue *q, int val) {
    if (q == NULL) return 0;
    if (q->tail == q->length) return 0;
    q->data[q->tail++] = val;//将val放入tail指向的位置 然后将tail++操作
    return 1;
}

int pop(Queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;//判断当前队列是否为空 
    q->head++;
    return 1;
}

void output(Queue *q) {
    if (q == NULL) return;
    printf("Queue : [");
    for (int i = q->head, j = 0; i < q->tail; i++, j++) {
        j && printf(", "); //打印逗号和空格
        printf("%d", q->data[i]);
    }
    printf("]\n");
    return ;
}

void clear(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return;
}

int main() {
    srand(time(0));
    #define max_op 20
    Queue *q = init(max_op);
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        int op = rand() % 4;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("push %d to the Queue! ", val);
                printf("result = %d\n", push(q, val));
            } break;
            case 3: {
                printf("pop %d from the Queue! ", front(q));
                printf("result = %d\n", pop(q));
            } break;
        }
        output(q), printf("\n");
    }
    #undef max_op
    clear(q);
    return 0;
}

/*************************************************************************
	> File Name: vector.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Sat 21 Nov 2020 10:29:39 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)

typedef struct Vector {
    int *data;
    int size, length;
} Vec;

Vec *init(int n) {
    Vec *v =(Vec *)malloc(sizeof(Vec));
    v->data = (int *)malloc(sizeof(int) * n);
    v->size = n;
    v->length = 0;
    return v;
}

int expand(Vec *v) {
    int extr_size = v->size;
    int *p;
    while (extr_size) {
        p = (int *)realloc(v->data, sizeof(int) * (extr_size + v->size));
        if (p) break;
        extr_size >>= 1;
    }
    if (extr_size == 0) return 0;
    v->data = p;
    v->size += extr_size;
    return 1;
}

int insert(Vec *v, int val, int ind) {
    if (v == NULL) return 0;
    if (ind < 0 || ind > v->length) return 0;
    if (v->length == v->size) {
        if (!expand(v)) return 0;
        printf(GREEN("success to expand! The Vector size is %d\n"), v->size);
    }
    for (int i = v->length; i > ind; i--) {
        v->data[i] = v->data[i - 1];
    }
    v->data[ind] = val;
    v->length++;
    return 1;
}

int erase(Vec *v, int ind) {
    if (v == NULL) return 0;
    if (ind < 0 || ind >= v->length) return 0;
    for (int i = ind + 1; i < v->length; i++) {
        v->data[i - 1] = v->data[i];
    }
    v->length--;
    return 1;
}

void clear(Vec *v) {
    if (v == NULL) return ;
    free(v->data);
    free(v);
    return ;
}

void output(Vec *v) {
    if (v == NULL) return ;
    printf("[");
    for (int i = 0; i < v->length; i++) {
        i && printf(" ");
        printf("%d ", v->data[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    Vec *v = init(2);
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        int ind = rand() % (v->length + 3) - 1;
        int op = rand() % 4;
        switch (op) {
            case 1:
            case 2:
            case 0: {
                printf("insert %d at %d to Vector = %d\n", val, ind, insert(v, val, ind));
            } break;
            case 3: {
                printf("erase a iterm at %d from Vector = %d\n", ind, erase(v, ind));
            } break;
        }
        output(v);
        printf("\n");
    }
    clear(v);
    return 0;
}

/*************************************************************************
	> File Name: 1.pthread.c
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 26 Jun 2021 04:42:09 PM CST
 ************************************************************************/

#include "head.h"
#define INS 100

struct Arg {
    int age;
    char name[20];
};

void *print(void *arg) {
    struct Arg argin;
    argin = *(struct Arg *)arg;
    printf("%s is %d years old!\n", argin.name, argin.age);
}

int main() {
    pthread_t thread;
    pthread_t *tid = calloc(INS + 5, sizeof(pthread_t));
    struct Arg *arg = calloc(INS + 5, sizeof(struct Arg));
    for (int i = 1; i <= INS; i++) {
        strcpy(arg[i].name, "ZYJ");
        arg[i].age = i;
        pthread_create(&tid[i], NULL, print, &arg[i]);
    }
    for (int i = 1; i <= 100; i++) {
        pthread_join(tid[i], NULL);
    }
    return 0;
}

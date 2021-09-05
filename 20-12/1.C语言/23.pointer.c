/*************************************************************************
	> File Name: 23.pointer.c
	> Author: 
	> Mail: 
	> Created Time: Mon 02 Nov 2020 01:06:15 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
#define offset(T, a) ({\
    T temp;\
    (char *)(&temp.a) - (char *)(&temp);\
})
*/

//宏表示 计算结构体里的变量的地址偏移量

#define offset(T, a) (long)(&(((T *)(NULL))->a))

struct Data {
    int a;
    double b;
    char c;
};

void output(int argc, char *argv[], char **env) {
    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    for (int i = 0; env[i]; i++) {
        if (!strncmp(env[i], "USER=", 5)) {
            if (!strcmp(env[i] + 5, "admin")) {
                printf("welcome!\n");
            } else {
                printf("you are not the User! Please gun!\n");
                exit(0);
            }
        }
    }
    return ;
}

int main(int argc, char *argv[], char **env) {
    output(argc, argv, env);
    return 0;
    int num = 0x0626364;
    printf("%s\n", (char *)(&num));//整型有4字节存储 由于我是小端机 64存在0地址上 以此类推
    printf("%ld\n", offset(struct Data, a));
    printf("%ld\n", offset(struct Data, b));
    printf("%ld\n", offset(struct Data, c));
    return 0;
}

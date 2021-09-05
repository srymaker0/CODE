/*************************************************************************
	> File Name: 20.LOG.c
	> Author: 
	> Mail: 
	> Created Time: Tue 27 Oct 2020 07:59:49 PM CST
 ************************************************************************/
#include <stdio.h>

#define DEBUG

#ifdef DEBUG
#define log(frm, args...) {\
    printf("[%s : %s : %d]", __FILE__, __func__, __LINE__);\
    printf(frm, ##args);\
    printf("\n");\
}
#else
#define log(frm, args...)
#endif

#define contact(a, b) a##b

int main() {
    int a = 123;
    int b = 234;
    int abcdef = 0, abc, def;
    log("%d", b);
    log("hello world");
    contact(abc, def) = 112233;
    log("%d", abcdef);
    return 0;
}


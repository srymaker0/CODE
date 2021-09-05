/*************************************************************************
	> File Name: 14.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Nov 2020 11:06:24 PM CST
 ************************************************************************/
#include <stdio.h>

#define log(frm, args...) {\
    printf("[%s, %s, %d]", __FILE__, __func__, __LINE__);\
    printf(frm, ##args);\
    printf("\n");\
}

int main() {
    int a = 123;
    log("%d", a);
    log("hello world");
    return 0;
}

/*************************************************************************
	> File Name: 4.nonblock.c
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Thu 17 Jun 2021 05:29:08 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    int age1 = 0, age2 = 0;
    make_nonblock(0);
    sleep(2);
    int ret = scanf("%d", &age1);
    if (ret < 0) {
        if (errno == EAGAIN) {
            printf("EAGIN\n");
        }
        perror("scanf");
    }
    make_block(0);
    scanf("%d", &age2);
    printf("Zyj is %d <%d> years old!\n", age1, age2);
    return 0;
}

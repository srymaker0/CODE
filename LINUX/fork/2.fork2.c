/*************************************************************************
	> File Name: 2.fork2.c
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 20 Jun 2021 03:46:45 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    pid_t pid;
    int i = 1;
    for ( ; i <= 10; i++) {
        sleep(1);
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        }
        if (pid == 0) break;
    }
    if (pid == 0) {
        printf("I'm the %d Child Process!\n", i);
    } else {
        sleep(2);
        printf("I'm the father!\n");
    }
    return 0;
}

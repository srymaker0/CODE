/*************************************************************************
	> File Name: 1.fork.c
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 20 Jun 2021 03:31:08 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        printf("In Child Process! <%d>--<%d>\n", getppid(), getpid());
    } else {
        printf("In Parent Process! <%d>--<%d>--<%d>\n", getppid(), getpid(), pid);
        sleep(500);
    }
    return 0;
}

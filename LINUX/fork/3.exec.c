/*************************************************************************
	> File Name: 3.exec.c
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 20 Jun 2021 03:51:31 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        execl("/bin/cat", "cat", "/etc/hosts", NULL);
        printf("Hello world\n");
    } else {
        wait(NULL);
    }
    return 0;
}

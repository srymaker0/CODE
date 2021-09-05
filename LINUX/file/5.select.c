/*************************************************************************
	> File Name: 5.select.c
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Fri 18 Jun 2021 11:31:22 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    fd_set rfds;
    struct timeval tv;
    int ret;
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    ret = select(1, &rfds, NULL, NULL, &tv);
    if (ret == -1) {
        perror("select()");
    } else if (ret) {
        printf("Data is available now.\n");
    } else {
        printf("No data within five seconds.\n");
    }
    return 0;
}

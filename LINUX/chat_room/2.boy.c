/*************************************************************************
	> File Name: 2.boy.c
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 11 Jul 2021 08:45:29 PM CST
 ************************************************************************/

#include "head.h"

int sockfd;

void close_sock(int signum) {
    send(sockfd, "Bye", 3, 0);
    close(sockfd);
    exit(0);
}

void Usage(const char *arg) {
    fprintf(stderr, "Usage %s ip port!\n", arg);
    return ;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        Usage(argv[1]);
        exit(1);
    }
    if ((sockfd = socket_connect(argv[1], atoi(argv[2]))) < 0) {
        perror("socket_connect");
        exit(1);
    }
    signal(SIGINT, close_sock);
    while (1) {
        char buff[1024] = {0};
        scanf("%[^\n]s", buff);
        getchar();
        if (strlen(buff)) {
            send(sockfd, buff, strlen(buff), 0);
        }
    }
    return 0;
}

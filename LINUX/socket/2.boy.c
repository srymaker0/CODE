/*************************************************************************
	> File Name: 2.boy.c
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 03 Jul 2021 06:33:25 PM CST
 ************************************************************************/

#include "head.h"

int sockfd;

void close_sock(int signum) {
    send(sockfd, "Bye", 3, 0);
    close(sockfd);
    exit(0);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage %s ip port!\n", argv[0]);
        exit(1);
    }
    struct sockaddr_in server;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket()");
        exit(1);
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);
    signal(SIGINT, close_sock);
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(1);
    }
    while (1) {
        char buff[1024] = {0};
        scanf("%[^\n]s", buff);
        getchar();
        if (strlen(buff)) {
            send(sockfd, buff, sizeof(buff), 0);
        }
    }
    return 0;
}

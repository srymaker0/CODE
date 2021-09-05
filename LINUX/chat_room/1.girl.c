/*************************************************************************
	> File Name: 1.girl.c
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 11 Jul 2021 08:45:15 PM CST
 ************************************************************************/

#include "head.h"

void Usage(const char *arg) {
    fprintf(stderr, "Usage : %s -p port!\n", arg);
    return ;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        Usage(argv[2]);
        exit(1);
    }
    int sockfd, opt, port;
    while ((opt = getopt(argc, argv, "p:")) != -1) {
        switch (opt) {
            case 'p': {
                port = atoi(optarg);
                break;
            }
            default : {
                Usage(argv[2]);
                exit(1);
            }
        }
    }
    if ((sockfd = socket_create(port)) < 0) {
        perror("socket_create()");
        exit(1);
    }
    while (1) {
        int socket_listen, pid;
        struct sockaddr_in client;
        socklen_t len = sizeof(client);
        if ((socket_listen = accept(sockfd, (struct sockaddr *)&client, &len)) < 0) {
            perror("accept");
            exit(1);
        }
        printf("<Accept> : %s:%d \n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        }
        if (pid == 0) {
            while (1) {
                char buff[1024] = {0};
                ssize_t rsize = recv(socket_listen, buff, sizeof(buff), 0);
                printf("<Recv %ld> : %s\n", rsize, buff);
                if (rsize <= 0) {
                    close(sockfd);
                    break;
                }
            }
            printf("<Bye> : A boy left!\n");
            exit(0);
        }
    }
    return 0;
}

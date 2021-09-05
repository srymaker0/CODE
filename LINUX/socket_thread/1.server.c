/*************************************************************************
	> File Name: 1.server.c
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sun 11 Jul 2021 10:37:42 PM CST
 ************************************************************************/

#include "head.h" 
#define MAXUSER 100

void Usage(const char *arg) {
    fprintf(stderr, "Usage %s -p port\n", arg);
    return ;
}

void *worker(void *arg) {
    int sockfd;
    sockfd = *(int *)arg;
    while (1) {
        char buff[1024] = {0};
        ssize_t rsize = recv(sockfd, buff, sizeof(buff), 0);
        if (rsize <= 0) {
            close(sockfd);
            break;
        } else {
            send(sockfd, buff, sizeof(buff), 0);
        }
    }
    printf("<Bye> : A boy left!\n");
    exit(0);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        Usage(argv[0]);
        exit(1);
    }
    pthread_t tid[MAXUSER];
    int fd[MAXUSER + 5];
    int opt, port, sockfd;
    while ((opt = getopt(argc, argv, "p:")) != -1) {
        switch (opt) {
            case 'p':
                port = atoi(optarg);
                break;
            default :
                Usage(argv[0]);
                exit(1);
        }
    }

    if ((sockfd = socket_creat(port)) < 0) {
        perror("socket_creat");
        exit(1);
    }
    
    while (1) {
        int sockfd_listen;
        struct sockaddr_in client;
        socklen_t len = sizeof(client);
        if ((sockfd_listen = accept(sockfd, (struct sockaddr *)&client, sizeof(client))) < 0) {
            perror("accept");
            exit(1);
        }
        if (sockfd_listen > MAXUSER) {
            close(sockfd_listen);
            printf("Too many users!\n");
            break;
        }
        fd[sockfd_listen] = sockfd_listen;
        pthread_create(&tid[sockfd_listen], NULL, worker, (void *)&fd[sockfd_listen]);
    }
    return 0;
}

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

int main(int argc, char **argv) {
    if (argc != 3) {
        Usage(argv[0]);
        exit(1);
    }
    pthread_t tid[MAXUSER + 5];
    int fd[MAXUSER + 5];
    int opt, port, server_listen, maxfd = 0;
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
    fd_set rfds;
    struct timeval tv;
    maxfd = server_listen;
    fd[server_listen] = server_listen;
    while (1) {
        FD_ZERO(&rfds);
        for (int i = 0; i < MAXUSER; i++) {
            if (fd[i] > 0) {
                FD_SET(fd[i], &rfds);
            }
        }
        int rnum = select(maxfd + 1, &rfds, NULL, NULL, NULL);
        if (rnum < 0) {
            perror("select");
            exit(1);
        }
        if (FD_ISSET(server_listen, &rfds)) {
            int new_fd;
            struct sockaddr_in client;
            socklen_t len = sizeof(client);
            if ((new_fd = accept(server_listen, (struct sockaddr *)&client, &len)) < 0) {
                perror("accept");
                exit(1);
            }
            if (new_fd >= MAXUSER) {
                close(new_fd);
                printf("Too many users!\n");
                break;
            }
            if (maxfd < new_fd) maxfd = new_fd;
            fd[new_fd] = new_fd;
            printf("<Accept> %s:%d!\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        }
        for (int i = 0; i < MAXUSER; i++) {
            if (fd[i] == server_listen) continue;
            if (fd[i] > 0 && FD_ISSET(fd[i], &rfds)) {
                char buff[1024] = {0};
                int rsize = recv(fd[i], buff, sizeof(buff), 0);
                if (rsize <= 0) {
                    close(fd[i]);
                    fd[i] = 0;
                } else {
                    send(fd[i], buff, sizeof(buff), 0);
                }
            }
        }
    }
    
    return 0;
}

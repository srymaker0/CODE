/*************************************************************************
	> File Name: 1.shm.c
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Mon 21 Jun 2021 10:53:40 AM CST
 ************************************************************************/

#include "head.h"

int main() {
    pid_t pid;
    int shmid;
    char *share_memory = NULL;
    key_t key = ftok("./1.shm.c", 2021);
    if ((shmid = shmget(key, 4096, IPC_CREAT | IPC_EXCL | 0600)) < 0) {
        perror("shmget()");
        exit(1);
    }
    if ((share_memory = shmat(shmid, NULL, 0)) == NULL) {
        perror("shmat");
        exit(1);
    }
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    if (pid) {
        while(1) {
            scanf("%s", share_memory);
            getchar();
        }
    } else {
        while(1) {
            sleep(2);
            if (strlen(share_memory)) printf("<Child> : %s\n", share_memory);
            memset(share_memory, 0 , 4096);
        }
    }
    return 0;
}

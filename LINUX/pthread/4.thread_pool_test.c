/*************************************************************************
	> File Name: 4.thread_pool_test.c
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 26 Jun 2021 07:02:38 PM CST
 ************************************************************************/

#include "head.h"
#define INS 5
#define QUEUE_SIZE 500

void *do_work(void *arg) {
    pthread_detach(pthread_self());
    struct task_queue *taskQueue = (struct task_queue *)arg;
    while (1) {
        char *str = task_queue_pop(taskQueue);
        usleep(20);
        printf("<%ld> : %s \n", pthread_self(), str);
    }
}

int main() {
    pthread_t tid[INS + 1];
    struct task_queue taskQueue;
    task_queue_init(&taskQueue, QUEUE_SIZE);
    char buff[QUEUE_SIZE][10] = {0};
    for (int i = 0; i < INS; i++) {
        pthread_create(&tid[i], NULL, do_work, (void *)&taskQueue);
    }
    int sub = 0;
    while (1) {
        FILE *fp = fopen("./4.thread_pool_test.c", "r");
        if (fp == NULL) {
            perror("fopen");
            exit(1);
        }
        while (fgets(buff[sub], 1024, fp) != NULL) {
            task_queue_push(&taskQueue, buff[sub]);
            if (++sub == QUEUE_SIZE) {
                sub = 0;
            }
            if (taskQueue.total == taskQueue.size) {
                while (1) {
                    if (taskQueue.total < taskQueue.size) {
                        break;
                    }
                    usleep(10000);
                }
            }
        }
        fclose(fp);
    }
    return 0;
}

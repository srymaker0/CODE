/*************************************************************************
	> File Name: 2.multi_thread_add.c
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Sat 26 Jun 2021 04:49:14 PM CST
 ************************************************************************/

#include "head.h"
#define INS 50
#define MAX 100
int now;
int sum;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *add(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (now > MAX) {
            pthread_mutex_unlock(&mutex);
            return NULL;
        }
        sum += now;
        usleep(15);
        now++;
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    pthread_t thread[INS + 5];
    for (int i = 1; i <= INS; i++) {
        pthread_create(&thread[i], NULL, add, NULL);
    }
    for (int i = 1; i <= INS; i++) {
        pthread_join(thread[i], NULL);
    }
    printf("sum = %d\n", sum);
    return 0;
}

/*************************************************************************
	> File Name: thread_pool.c
	> Author: 
	> Mail: 
	> Created Time: Sat 02 Oct 2021 03:20:53 PM CST
 ************************************************************************/

#include "head.h"
#include "./thread_pool.h"

void task_queue_init(struct task_queue *taskQueue, int size) {
    taskQueue->size = size;
    taskQueue->head = taskQueue->tail = 0;
    taskQueue->tail = 0;
    taskQueue->data = calloc(size, sizeof(void *));
    pthread_mutex_init(&taskQueue->mutex, NULL);
    pthread_cond_init(&taskQueue->cond, NULL);
    return ;
}
void task_queue_push(struct task_queue *taskQueue, char *str) {
    pthread_mutex_lock(&taskQueue->mutex);
    if (taskQueue->total == taskQueue->size) {
        pthread_mutex_unlock(&taskQueue->mutex);
        printf("task queue is full!\n");
        return ;
    }
    printf("<push> : %s\n", str);
    taskQueue->data[taskQueue->tail++] = str;
    taskQueue->total++;
    if (taskQueue->tail == taskQueue->size) {
        printf("task queue reach end!\n");
        taskQueue->tail = 0;
    }
    pthread_cond_signal(&taskQueue->cond);
    pthread_mutex_unlock(&taskQueue->mutex);
    return ;
}

char *task_queue_pop(struct task_queue *taskQueue) {
    pthread_mutex_lock(&taskQueue->mutex);
    while (taskQueue->total == 0) {
        printf("task queue is empty!\n");
        pthread_cond_wait(&taskQueue->cond, &taskQueue->mutex);
    }
    char *str = taskQueue->data[taskQueue->head++];
    taskQueue->total--;
    if (taskQueue->head == taskQueue->size) {
        printf("task queue reach end!\n");
        taskQueue->head = 0;
    }
    pthread_mutex_unlock(&taskQueue->mutex);
    return str;
}

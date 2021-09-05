/*************************************************************************
	> File Name: head.h
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Mon 19 Apr 2021 10:18:40 AM CST
 ************************************************************************/

#ifndef _HEAD_H
#define _HEAD_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>   // open headfile
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "common.h"
#include "thread_pool.h"

#endif

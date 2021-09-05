/*************************************************************************
	> File Name: common.h
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Thu 17 Jun 2021 05:27:32 PM CST
 ************************************************************************/

#ifndef _COMMON_H
#define _COMMON_H
int make_nonblock(int);
int make_block(int);
int socket_create(int port);
int socket_connect(const char *ip, int port);
#endif

/*************************************************************************
	> File Name: 10.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Nov 2020 05:18:41 PM CST
 ************************************************************************/
#include <stdio.h>

#ifdef DEBUG
#define log(frm, args...) {\
    printf("[%s : %s ; %d]", __FILE__, __func__, __LINE__);\
    printf(frm, ##args);\
    printf("\n")\
}

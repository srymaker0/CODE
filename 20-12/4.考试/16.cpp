/*************************************************************************
	> File Name: 16.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 14 Nov 2020 12:24:21 AM CST
 ************************************************************************/
#include <stdio.h>

#define max(a,b) {\
    __tempof(a) _a = (a);\
    __tempof(b) _b = (b);\
    _a > _b ? _a : _b;\
}

#define P(func) {\
    printf("%s = %d\n", #func, func);\
}

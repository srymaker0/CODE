/*************************************************************************
	> File Name: 19.define_max.c
	> Author: 
	> Mail: 
	> Created Time: Tue 27 Oct 2020 07:15:32 PM CST
 ************************************************************************/
#include <stdio.h>
//在预处理时期进行宏替换
#define MAX(a,b) ({\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    _a > _b ? _a : _b;\
})
#define P(func) {\
    printf("%s = %d\n", #func, func);\
}

int main() {
    int a = 7;
    P( MAX(2,3));
    P( 5 +  MAX(2,3));
    P( MAX(2, MAX(3, 4)));
    P( MAX(2,3 > 4 ? 3 : 4));
    P( MAX(a++, 6));
    P(a);
    return 0;
}


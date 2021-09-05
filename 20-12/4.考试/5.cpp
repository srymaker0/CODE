/*************************************************************************
	> File Name: 5.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Nov 2020 03:01:19 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>
int max_num(int n, ...) {
    int ans = INT32_MIN;
    va_list arg;
    va_start(arg, n);
    while(n--) {
        int temp = va_arg(arg, int);
        if (temp > ans) ans = temp;
    }
    va_end(arg);
    return ans;
}

int main() {
    printf("%d\n", max_num(3,1,5,10));

    return 0;
}

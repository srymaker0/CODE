/*************************************************************************
	> File Name: 13.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Nov 2020 10:44:03 PM CST
 ************************************************************************/
#include <stdio.h>
#include <inttypes.h>
#include <stdarg.h>

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
    printf()


    return 0;
}

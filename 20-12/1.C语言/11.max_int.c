/*************************************************************************
	> File Name: 11.max_int.c
	> Author: 
	> Mail: 
	> Created Time: Mon 26 Oct 2020 04:16:43 PM CST
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <stdarg.h>

int max_int(int n, ...){
    int ans = INT32_MIN;//编译器默认的最小整型
    va_list arg;
    va_start(arg, n);
    while(n--){
        int temp = va_arg(arg, int);
        if(temp > ans) ans = temp;
    }
    va_end(arg);
    return ans;

}

int main(){
    printf("%d\n", max_int(3,1,5,10));
    printf("%d\n", max_int(2,1,3));
    printf("%d\n", max_int(6,1,3,5,7,13,15,17));
    return 0;
}

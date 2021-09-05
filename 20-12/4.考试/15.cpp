/*************************************************************************
	> File Name: 15.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 14 Nov 2020 12:06:06 AM CST
 ************************************************************************/
#include <stdio.h>
#include <inttypes.h>
#include <stdarg.h>

int rev_num(int n, int *temp) {
    int digit = 0;
    *temp = 0;
    do{
        *temp = *temp * 10 + n % 10;
        n /= 10;
        ++digit;
    }while(n);
    return digit;
}

int output_num(int n, int digit) {
    int cnt = 0;
    while(digit--) {
        putchar(n % 10 + 48), ++cnt;
        n /= 10;
    }
    return cnt;
}

int my_printf(const char *frm, ...) {
    int cnt = 0;
    va_list = arg;
    va_start(arg, frm);
    #define PUTC(a) purchar(a), ++cnt
    for (int i = 0; frm[i]; i++) {
        switch(frm[i]) {
            case'%': {
                switch(frm[++i]) {
                    case '%': PUTC(frm[i]); break;
                    case 'd': {
                        int xx = va_arg(arg, int);
                        uint32_t x;
                        if (xx < 0) PUTC('-'), x = -xx;
                        else x = xx;
                        int temp1, temp2;
                        int x1 = x / 100000, x2 = x % 100000;
                        int digit1 = rev_num(x1, &temp1);
                        int digit2 = rev_num(x2, &temp2);
                        if(x1) digit2 = 5;
                        else digit1 = 0;
                        cnt += output_num(temp1, digit1);
                        cnt += output_num(temp2, digit2);
                    } break;
                    case 's': {
                        const char *str = va_arg(arg, const char *);
                        for (int i = 0; str[i]; i++) {
                            PUTC(str[i]);
                        }
                    } break;
                }
            } break;
            default:PUTC(frm[i]); break;
        }
    }
    #undef PUTC
    va_end(arg);
    return cnt;
}


int main() {


    return 0;
}

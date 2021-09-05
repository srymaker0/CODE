/*************************************************************************
	> File Name: 12.my_printf.c
	> Author: 
	> Mail: 
	> Created Time: Mon 26 Oct 2020 04:29:37 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>

int rev_num(int n, int *temp){
    int digit = 0;
    *temp = 0;
    do{
        *temp = *temp * 10 + n % 10;
        n /= 10;
        ++digit;
    }while(n);
    return digit;
}

int output_num(int n, int digit){
    int cnt = 0;
    while(digit--){
        putchar(n % 10 + 48), ++cnt;
        n /= 10;
    }
    return cnt;
}

//va_list 类型的变量 获得a往后的参数列表
//va_start 定位a后面第一个参数的位置
//va_arg 获取下一个可变参数列表中的参数
//va_end 结束整个获取可变参数列表的动作
int my_printf(const char *frm, ...){
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    #define PUTC(a) putchar(a), ++cnt
    for(int i = 0; frm[i]; i++){
        switch(frm[i]){
            case'%':{
                switch(frm[++i]){
                    case '%': PUTC(frm[i]); break;
                    case 'd': {
                        int xx = va_arg(arg, int);
                        uint32_t x;
                        if (xx < 0) PUTC('-'), x = -xx;
                        else x = xx;
                        int temp1,temp2;
                        int x1 = x / 100000, x2 = x % 100000;//把一个整数分为高位和低位
                        int digit1 = rev_num(x1, &temp1);
                        int digit2 = rev_num(x2, &temp2);
                        if(x1) digit2 = 5;
                        else digit1 = 0;
                        cnt += output_num(temp1, digit1);
                        cnt += output_num(temp2, digit2);
                    } break;
                    case 's':{
                        const char *str = va_arg(arg, const char *);
                        for(int i = 0; str[i]; i++){
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

int main(){
    int n;
    while(~scanf("%d", &n)){
        printf(" has %d digits!\n", printf("%d", n));
        my_printf(" has %d digits!\n", my_printf("%d", n));
    }
    int a = 123;
    printf("hello world\n ");
    my_printf("hello world\n");
    printf("int (a) = %d\n", a);
    my_printf("int (a) = %d\n", a);
    printf("int (a) = %d\n", 0);
    my_printf("int (a) = %d\n", 0);
    printf("int (a) = %d\n", 1000);
    my_printf("int (a) = %d\n", 1000);
    printf("int (a) = %d\n", -123);
    my_printf("int (a) = %d\n", -123);
    printf("int (a) = %d\n", INT32_MAX);
    my_printf("int (a) = %d\n", INT32_MAX);
    printf("int (a) = %d\n", INT32_MIN);
    my_printf("int (a) = %d\n", INT32_MIN);
    char str[100] = "I love China";
    printf("%s\n", str);
    my_printf("%s\n", str);
    return 0;
}

/*************************************************************************
	> File Name: 7.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 20 Oct 2020 02:31:01 PM CST
 ************************************************************************/


#include<stdio.h> 
int rev_num(int n, int base){
    if(n < 0) return 0;
    int x = n, temp = 0;
    while(x){
        temp = temp * base + x % base;
        x /= base;
    }
    return temp == n;
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%s\n", rev_num(n, 10) ? "YES" : "NO");
    int x = n, digit = 0;
    //这里用do while 是因为数字0有特殊情况 要先判断一次位数
    do{
        x /= 10;
        digit += 1;
    }while(x);
    printf("%d has %d digits!\n", n, digit);
    return 0;
}


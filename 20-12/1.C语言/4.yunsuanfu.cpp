/*************************************************************************
	> File Name: 4.yunsuanfu.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 20 Oct 2020 11:06:16 AM CST
 ************************************************************************/
#include<stdio.h>

int main(){
    int a = 7, b = 3, c;
    a += 7; //a = a + 7;
    int *p = &a;
    (*p)--; // a--  *p-- 运算符优先级问题
    printf("a = %d, b = %d\n", a, b);
    //swap
    /*int temp = a;
    a = b;
    b = temp;
    */

    //异或运算实现交换
    a ^= b;
    b ^= a;
    a ^= b;
    printf("swap : a = %d, b = %d\n", a, b);
    return 0;
}


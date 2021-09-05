/*************************************************************************
	> File Name: 13.prime.c
	> Author: 
	> Mail: 
	> Created Time: Mon 26 Oct 2020 06:43:45 PM CST
    > 素数筛  用素数标记合数  
 ************************************************************************/

#include<stdio.h>
#define max_n 10000000

//编程技巧：+5为了防止访问到max_n时报错 给它扩容一下 
//当数组定义在函数外部时 系统会主动的为数组每一位清0
int prime[max_n + 5];
void init() {
    for (int i = 2; i <= max_n; i++) {
        if (prime[i]) continue;//如果prime[i]是一个合数 则直接执行下一次循环
        prime[++prime[0]] = i;//++prime[0]是将数组中第一个值+1再存放到原位
        for (int j = i * 2; j <= max_n; j += i) {//可以是j = i * i 可以减少重复标记 但是会越界
            prime[j] = 1;//若prime[i]是一个素数 则扩大相应的倍数 将此倍数标记为合数
        }
    }
    return ;
}
int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    init();
    for (int i = 0; i <= prime[0]; i++) {
        if (prime[i] > m && prime[i] < n) {
            printf("%d\n", prime[i]);
        }
    }
    return 0;
}

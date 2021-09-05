/*************************************************************************
	> File Name: 14.prime.c
	> Author: 
	> Mail: 
	> Created Time: Mon 26 Oct 2020 08:37:39 PM CST
 ************************************************************************/

#include<stdio.h>
#define max_n 200000 //算出第n个素数 估算范围n * 20

//线性筛 用（最小的素因子 * 最大的因子） 标记合数 每个合数只用标记1次

int prime[max_n + 5];
void init() {
    for (int i = 2; i <= max_n; i++){
        if (!prime[i]) prime[++prime[0]] = i; //存储素数
        for (int j = 1; j <= prime[0]; j++){ 
            if (i * prime[j] > max_n) break; //判断越界
            prime[prime[j] * i] = 1; // 标记素数
            if (i % prime[j] == 0) break;//确保是（最小的素因子 * 最大的因子）来标记合数 避免重复
        }
    }
    return ;
}

int main() {
    init();
    printf("%d\n", prime[10001]);
    return 0;
}



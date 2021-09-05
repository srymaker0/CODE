/*************************************************************************
	> File Name: 10.ex_gcd.c
	> Author: 
	> Mail: 
	> Created Time: Wed 21 Oct 2020 09:37:38 PM CST
 ************************************************************************/

#include<stdio.h>

int ex_gcd(int a, int b, int *x, int *y){
    if(!b){
        *x = 1, *y = 0;
        return a;
    }
    int xx, yy, ret = ex_gcd(b, a % b, &xx, &yy);
    *x = yy;
    *y = xx - a / b * yy;
    return ret;
}

int main(){
    int a, b, x, y;
    while(scanf("%d%d", &a, &b) != EOF){
        printf("ex_gcd(%d, %d) = %d\n", a, b, ex_gcd(a, b, &x, &y));
        printf("%d * %d + %d * %d = %d\n", a, x, b, y, a * x + b * y);
    }
    return 0;
}

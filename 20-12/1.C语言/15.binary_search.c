/*************************************************************************
	> File Name: 15.binary_search.c
	> Author: 
	> Mail: 
	> Created Time: Tue 27 Oct 2020 09:30:06 AM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x;
}

//通过二分查找法求x的平方根
double binary_search(double (*arr)(double), double x) {
    double head = 0, tail = x, mid; //求x的平方根 范围在0~x之内
    if (x < 1.0) tail = 1.0;
    #define EPSL 1e-7 //1 * 10^-7 足够小的精度
    while (tail - head > EPSL) {
        mid = (head + tail) / 2.0;
        if (arr(mid) < x) head = mid;
        else tail = mid;
    }
    #undef EPSL
    return head;
    
}

int main() {
    double x;
    while (~scanf("%lf" , &x)) {
        double ans = binary_search(f, x);
       // printf("sqrt(%g) = %g\n", x, sqrt(x));
        printf("my_sqrt(%g) = %g\n", x, ans);
    }
    return 0;
}

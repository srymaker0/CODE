/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Nov 2020 02:21:09 PM CST
 ************************************************************************/
#include <stdio.h>

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b)) {
        printf("gcd(%d,%d) = %d\n", a, b, gcd(a, b));
    }
    return 0;
}

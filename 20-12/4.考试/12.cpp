/*************************************************************************
	> File Name: 12.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Nov 2020 10:38:19 PM CST
 ************************************************************************/
#include <stdio.h>

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    int x, y;
    while (~scanf("%d%d", &x, &y)) {
        printf("gcd(%d, %d) = %d", x, y, gcd(x, y));
    }
    return 0;
}

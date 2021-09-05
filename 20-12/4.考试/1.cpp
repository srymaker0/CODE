/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Nov 2020 01:49:33 PM CST
 ************************************************************************/
#include <stdio.h>

bool rev_num(int n) {
    int temp, t = n;
    while(n) {
        temp = temp * 10 + n % 10;
        n /= 10;
    }
    return temp == t;
}


int main() {
    int n;
    while(~scanf("%d", &n)) {
        printf("IS revnum\n %s", rev_num(n) ? "True" : "False");
    }
    int x = n, digit = 0;
    do{
        x /= 10;
        digit++;
    }while(x);
    return 0;
}

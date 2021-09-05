/*************************************************************************
	> File Name: 9.gcd.c
	> Author: 
	> Mail: 
	> Created Time: Wed 21 Oct 2020 03:16:38 PM CST
 ************************************************************************/

#include<stdio.h>

int gcd(int a, int b){
    return (b ? gcd(b, a % b) : a); 
}

int main(){
    int a, b;
    while(scanf("%d%d", &a, &b)){
        printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    }
    return 0;
}

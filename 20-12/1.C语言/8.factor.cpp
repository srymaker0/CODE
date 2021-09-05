/*************************************************************************
	> File Name: 8.factor.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 20 Oct 2020 03:18:25 PM CST
 ************************************************************************/

#include <stdio.h>

int fac(int n){
    if(n == 1) return 1;
    return n * fac(n - 1);
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        printf("fac(%d) = %d\n", n, fac(n));
    }
    return 0;
}

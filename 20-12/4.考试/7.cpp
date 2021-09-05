/*************************************************************************
	> File Name: 7.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Nov 2020 04:04:33 PM CST
 ************************************************************************/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int a, b, n, cnt = 0;
    srand(time(0));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int val = rand() % 100;
        cnt += (val & 1);
        i && printf(" ");
        printf("%d", val);
    }
    printf("\n");
    return 0;
}

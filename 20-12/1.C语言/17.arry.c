/*************************************************************************
	> File Name: 17.arry.c
	> Author: 
	> Mail: 
	> Created Time: Tue 27 Oct 2020 04:21:16 PM CST
 ************************************************************************/

#include <stdio.h>
#define max_n 100

void func(int (*num)[100][32]) {
    printf("num = %p, num + 1 = %p\n", num, num + 1);
    return ;
}

int main() {
    int arr[100][100][32];
    printf("sizeof(arr) = %lu\n", sizeof(arr));
    printf("&arr = %p, &arr[0] = %p\n", arr, &arr[0]);
    printf("arr + 1 = %p, arr + 2 = %p\n", arr + 1, arr + 2);
    char *p = (char *)arr;
    printf("p + 1 = %p, p + 2 = %p\n", p + 1, p + 2);
    func(arr);
    printf("arr = %p, arr + 1 = %p\n", arr, arr + 1);
    int **q;
    printf("q = %p, q + 1 = %p\n", q, q + 1);
    return 0;
}

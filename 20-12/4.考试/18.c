/*************************************************************************
	> File Name: 18.c
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Nov 2020 02:27:20 PM CST
 ************************************************************************/
#include <stdio.h>

int main() {
    int arr1[] = {12, 45, 55, 78, 5};
    int arr2[] = {1, 2, 3, 4, 5};
    int max = arr1[0], t;
    for (int i = 0; i < 5; i++) {
        if (max < arr1[i]) {
            max = arr1[i];
            t = i;
        }
    }
    printf("%d\n", t);
    printf("%d\n", max);
    arr1[t] = arr2[0];
    for (int j = 0; j < 5; j++) {
        j && printf(" ");
        printf("%d", arr1[j]);
    }
    return 0;
}

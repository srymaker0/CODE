/*************************************************************************
	> File Name: 2.quick_sort.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Wed 19 May 2021 02:16:03 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

void quick_sort_2(int *arr, int l, int r) {
    // 单边递归法
    while (l < r) {
        int x = l, y = r, base = arr[l];
        while (l <= r) {
            while (x < y && arr[y] >= base) y--;
            if (x < y) arr[x++] == arr[y];
            while (x < y && arr[x] < base) x++;
            if (x < y) arr[y--] == arr[x];
        }
        arr[x] = base;
        quick_sort_2(arr, x + 1, r);        // 右边使用递归
        r = x - 1;                          // 左边使用循环
    }
    return ;
}


int main() {

    return 0;
}

/*************************************************************************
	> File Name: quick_sort.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Wed 19 May 2021 11:08:26 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

void quick_sort(int *arr, int l, int r) {
    if (l >= r) return ;                        // 边界条件，当左右指针重合或者错开返回
    int x = l, y = r, base = arr[l];            // 取基准值，默认数组第一个元素
    while (x < y) {                             // 当左指针小于右指针，一直做partition操作
        while (x < y && arr[y] >= base) y--;    // 与基准值比较，找第一个小于基准值的位置
        if (x < y) arr[x++] = arr[y];           // 将第一个小于基准值的元素放入到最前面，并移动x指针
        while (x < y && arr[x] < base) x++;     // 找第一个大于基准值的位置
        if (x < y) arr[y--] = arr[x];           // 交换位置
    }                                           // 至此完成了一次partition操作
    arr[x] = base;                              // 到这里，说明x指针与y指针重合，也就是我们放入基准值的位置
    quick_sort(arr, l, x - 1);                  // 继续递归调用，对基准值左区间做partition操作
    quick_sort(arr, x + 1, r);                  // 对右区间做partition操作
    return ;
}


int main() {
    int arr[6] = {5, 2, 3, 4, 8, 7};
    quick_sort(arr, 0, 5);
    for (auto a : arr) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}


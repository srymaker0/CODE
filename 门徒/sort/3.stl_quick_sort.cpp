/*************************************************************************
	> File Name: 3.stl_quick_sort.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Wed 19 May 2021 03:06:05 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

const int threshold = 16;
inline int getmid(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    return b;
}

void __quick_sort_3(int *arr, int l, int r) {
    while (r - l > threshold) {                                               // 仿照stl中 分区  
        int x = l, y = r, base = getmid(arr[l], arr[(l + r) / 2], arr[r]);      // 三点取中法
        do {
            while(arr[x] < base) x++;     // 找第一个大于base的值
            while(arr[y] > base) y--;     // 找第一个小于base的值
            if (x <= y) {                 // 若x，y没有错位
                swap(arr[x], arr[y]);     // 交换x，y的值
                x++, y--;                 // 继续比较  
            }
        } while (x <= y);                 // 终止条件
        __quick_sort_3(arr, x, r);
        r = y;                            // 单边递归
    }
    return ;
}

// 无监督的插入排序    处理小区间
void final_insert_sort(int *arr, int l, int r) {
    int ind = l;
    for (int i = l + 1; i <= r; i++) {
        if (arr[i] < arr[ind]) ind = i;             // 找到最小值的下标
    }
    while (ind > l) {
        swap(arr[ind] , arr[ind - 1]);              // 将最小值拱到最前面
        ind--;                                      
    }
    for (int i = l + 2; i <= r; i++) {              // 此时最左边已经是最小的元素了，从l + 2开始比较
        int j = i;
        while (arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
    return ;
}

void quick_sort_3(int *arr, int l, int r) {
    __quick_sort_3(arr, l, r);
    final_insert_sort(arr, l, r);
    return ;
}

int main() {
    int arr[10] = {2, 4, 3, 8, 1, 7};
    quick_sort_3(arr, 0, 5);
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

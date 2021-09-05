/*************************************************************************
	> File Name: 4.merge_sort.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Tue 15 Jun 2021 09:48:48 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

void merge_sort(int *arr, int l, int r) {
    if (l >= r) return ;              // 一个元素或空区间直接终止递归
    int mid = (l + r) >> 1;
    merge_sort(arr, l, mid);          // 左区间
    merge_sort(arr, mid + 1, r);      // 右区间
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));     // 开辟新的空间
    int p1 = l, p2 = mid + 1, k = 0;                          // p1指向左区间，p2指向右区间
    while (p1 <= mid || p2 <= r) {                            // 左区间和右区间只要有元素就放入temp中
        // 两种情况：一、右区间没有元素，左区间有元素直接放入temp
        //           二、p1指针指向的值小于p2指针指向的值，将p1指向的值放入temp
        if ((p2 > r) || (p1 <= mid && arr[p1] <= arr[p2])) {  
            temp[k++] = arr[p1++];
        } else {
            temp[k++] = arr[p2++];
        }
    }
    // 将temp中的值复制到arr中
    for (int i = l; i <= r; i++) {
        arr[i] = temp[i - l];       // 下标映射：temp的下标从0开始，arr的下标是l到r
    }
    free(temp);
    return ;
}

int main() {
    int n;
    int arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

/*************************************************************************
	> File Name: 1.binary_search.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Tue 06 Jul 2021 09:09:37 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

void output_binary_process(int *arr, int n, int head, int tail, int mid) {
    int p1, p2, p3, len = 0;
    for (int i = 0; i < n; i++) {
        len += printf("%5d", i);
        if (i == head) p1 = len - 1;
        if (i == tail) p2 = len - 1;
        if (i == mid) p3 = len - 1;
    }
    printf("\n");
    for (int i = 0; i < len; i++) printf("-");
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%5d", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < len; i++) {
        if (i == p1 || i == p2 || i == p3) {
            printf("^");
        } else {
            printf(" ");
        }
    }
    printf("\n");
    for (int i = 0; i < len; i++) {
        if (i == p1 || i == p2 || i == p3) {
            printf("|");
        } else {
            printf(" ");
        }
    }
    printf("\n\n");
    return ;
}

// 进行二分查找
int binary_search(int *arr, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = head + (tail - head) >> 1;    // 防止head + tail 超过整形范围
        // output_binary_process(arr, n, head, tail, mid);    输出调试代码
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

// 骚操作 避免死循环：大范围用二分 小范围用顺序查找
int binary_search_2(int *arr, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (tail - head > 3) {
        mid = (head + tail) >> 1;
        output_binary_process(arr, n, head, tail, mid);
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    for (int i = head; i <= tail; i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}

// 随机生成数据
int *getRandData(int n) {
    int *arr = (int *)malloc(sizeof(int) * n);
    arr[0] = rand() % 10;
    for (int i = 1; i < n; i++) {
        arr[i] = arr[i - 1] + rand() % 5 + 1;
    }
    return arr;
}

// 输出
void output(int *arr, int n) {
    int len = 0;
    for (int i = 0; i < n; i++) {
        len += printf("%5d", i);
    }
    printf("\n");
    for (int i = 0; i < len; i++) printf("-");
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%5d", arr[i]);
    }
    printf("\n");
    return ;
}

int main() {
    srand(time(0));
    int n, x;
    scanf("%d", &n);
    int *arr = getRandData(n);
    output(arr, n);
    while (~scanf("%d", &x)) {
        printf("arr[%d] = %d\n",
            binary_search(arr, n, x),
            x
        );
    }
    return 0;
}


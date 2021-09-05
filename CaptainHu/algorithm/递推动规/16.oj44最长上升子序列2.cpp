/*************************************************************************
	> File Name: 16.oj44最长上升子序列2.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Tue 16 Feb 2021 05:11:08 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 1000000
int dp;
int len[MAX_N + 5];

int func(int *arr, int n, int x) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] < x) head = mid + 1;
        else tail = mid;
    }
    return head;
}

int main() {
    int n, ans = 0, val;
    scanf("%d", &n);
    memset(len, 0x3f, sizeof(len));
    len[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &val);
        dp = func(len, ans + 1, val);
        len[dp] = val;
        ans = max(dp, ans);
    }
    printf("%d\n", ans);
    return 0;
}

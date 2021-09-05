/*************************************************************************
	> File Name: 390.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Mon 23 Nov 2020 04:40:54 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int n, m, lr;
int num[1000005];

int func(int len) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += num[i] / len;
    }
    return s;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        lr = max(lr, num[i]);
    }
    int l = 1, r = lr;
    while (l != r) {
        int mid = (l + r + 1) / 2;
        int s = func(mid);
        if (s >= m) l = mid;
        else r = mid - 1;
    }
    cout << r << endl;
    return 0;
}

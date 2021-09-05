/*************************************************************************
	> File Name: 390.oj.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 01 Nov 2020 04:20:50 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m , num[100005], lr;

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
    int l = 1,  r = lr;
    while (l != r) {
        int mid = (l + r + 1) / 2;
        int s = func(mid);
        if (s >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << r << endl;
    return 0;
}

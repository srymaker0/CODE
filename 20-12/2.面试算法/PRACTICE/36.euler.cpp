/*************************************************************************
	> File Name: 36.euler.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Nov 2020 06:39:53 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int check(int x, int base) {
    int t = 0, raw = x;
    while (x) {
        t = t * base  + x % base;
        x /= base;
    }
    return raw == t;
}

int main() {
    int ans = 0;
    for (int i = 1; i < 1000000; i++) {
        if (check(i, 10) && check(i, 2)) {
            ans += 1;
            cout << i << endl;
        }
    }
    cout << ans << endl;
    return 0;
}

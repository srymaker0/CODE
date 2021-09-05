/*************************************************************************
	> File Name: 4.euler.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 05 Nov 2020 03:06:53 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int func(int n) {
    int t = 0, raw = n;
    while (n) {
        t = t * 10 + n % 10;
        n /= 10;
    }
    return t == raw;
}

int main() {
    int n = 0, ans = 0;
    for (int i = 100; i < 1000; i++) {
        for (int j = 100; j < 1000; j++) {
            n = i * j;
            if (func(n)) {
               ans = max(ans, n); 
            }
        }
    }
    cout << ans << endl;
    return 0;
}

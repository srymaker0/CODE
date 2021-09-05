/*************************************************************************
	> File Name: 30.euler.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Nov 2020 07:02:46 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int num[10];

void init() {
    for (int i = 1; i < 10; i++) {
        int t = i;
        for (int j = 1; j <= 4; j++) {
            t *= i;
        }
        num[i] = t;
    }
}

int check(int x) {
    int raw = x, t = 0;
    while (x) {
        t += num[x % 10];
        x /= 10;
    }
    return raw == t;
}

int main() {
    init();
    int ans = 0;
    for (int i = 10; i < 1000000; i++) {
        if (check(i)) {
            ans += i;
            cout << i << endl;
        }
    }
    cout << ans << endl;
    return 0;
}

/*************************************************************************
	> File Name: 34.euler.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Nov 2020 07:11:16 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
typedef long long ll;

ll num[11];

void init() {
    for (int i = 1; i < 10; i++) {
        ll ans = 1;
        for (int j = 1; j <= i; j++) {
            ans *= j;
        }
        num[i] = ans;
    }
}

int check(ll x) {
    ll raw = x, t = 0;
    while (x) {
        t += num[x % 10];
        x /= 10; 
    }
    return raw == t;
}

int main() {
    init();
    ll ans = 0;
    for (int i = 11; i < 10000000; i++) {
        if (check(i)) {
            ans += i;
            cout << i << endl;
        }
    }
    cout << ans << endl;
    return 0;
}

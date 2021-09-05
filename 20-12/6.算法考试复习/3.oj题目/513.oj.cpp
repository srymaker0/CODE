/*************************************************************************
	> File Name: 513.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Sat 28 Nov 2020 04:14:55 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, t, ans;

int func(int x, int t) {
    while (x) {
        if (x % 10 == t) return 0;
        x /= 10;
    }
    return 1;
}

int main() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        if (func(i, t)) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

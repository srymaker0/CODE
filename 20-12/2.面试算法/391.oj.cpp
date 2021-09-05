/*************************************************************************
	> File Name: 391.oj.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 01 Nov 2020 07:23:26 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

long long n, m, num[100005], tl, tr;

long long func(long long x) {
    long long cnt = 0, now = 0;
    for (int i = 0; i < n; i++ ) {
        if (now + num[i] == x) {
            cnt++;
            now = 0;
        } else if (now + num[i] > x) {
            cnt++;
            now = num[i];
        } else {
            now += num[i];
        }
    }
    if (now) {
        cnt++;
    }
    return cnt;
}

long long bin_search() {
    long long l = tl, r = tr;
    while (l != r) {
        long long mid = (l + r) / 2;
        long long s = func(mid);
        if (s <= m) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        tl = max(tl, num[i]);
        tr += num[i];
    }
    cout << bin_search() << endl;
    return 0;
}

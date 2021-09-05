/*************************************************************************
	> File Name: 82.oj.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 01 Nov 2020 06:49:25 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m, num[1000005], tr;

long long func(int h) {
    long long s = 0;
    for (int i = 0; i < n; i++) {
        if (h < num[i]) {
            s += num[i] - h;
        } 
    }
    return s;
}

int bin_search() {
    int l = 0, r = tr;
    while (l != r) {
        int mid = ((long long)l + r + 1) / 2;
        long long s = func(mid);
        if (s >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return r;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        tr = max(tr, num[i]);
    }
    cout << bin_search() << endl;
    return 0;
}

/*************************************************************************
	> File Name: 15.oj390.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 29 Dec 2020 08:19:03 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

int n, m, num[100005], l, r;

int func(int x) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += num[i] / x;
    }
    return s;
}

int bs() {
    while (l != r) {
        int mid = (l + r + 1);
        int s = func(mid);
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
        r = max(r, num[i]);
    }
    cout << bs() << endl;
    return 0;
}

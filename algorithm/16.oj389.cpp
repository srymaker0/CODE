/*************************************************************************
	> File Name: 16.oj389.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 29 Dec 2020 08:42:48 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int n, m, num[100005];

int func(int x) {
    int s = 1, last = num[0];
    for (int i = 1; i < n; i++) {
        if (num[i] - last >= x) {
            s++;
            last = num[i];
        }
    }
    return s;
}

int bs() {
    int l = 1, r = num[n - 1] - num[0];
    while (l != r) {
        int mid = (l + r + 1) / 2;
        int s = func(mid);
        if (s >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    cout << bs() << endl;
    return 0;
}

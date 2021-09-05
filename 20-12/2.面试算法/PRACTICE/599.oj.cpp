/*************************************************************************
	> File Name: 599.oj.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Nov 2020 08:15:32 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int n, t, num[1000005];

int main() {
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    int l = 0, r = n - 1;
    while (l < r) {
        if (num[l] + num[r] == t) {
            cout << l << " " << r << endl;
            return 0;
        }
        if (num[l] + num[r] < t) {
            l++;
        } else {
            r--;
        }
    }
    cout << -1 << end;
}

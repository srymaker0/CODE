/*************************************************************************
	> File Name: find.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Sun 29 Nov 2020 09:25:50 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, k, num[500005], g[500005];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> g[i];
    }
    
    for (int i = 0; i < k; i++) {
        int l = 0, r = n - 1;
        while (l != r) {
            int mid = (l + r + 1) / 2;
            if (num[mid] <= g[i]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (i != 0) cout << " ";
        if (num[l] > g[i]) {
            cout << -1 ;
        } else {
            cout << l;
        }
    }
    return 0;
}

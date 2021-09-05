/*************************************************************************
	> File Name: 503.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Sat 28 Nov 2020 03:15:18 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int ans, w, n, num[30005];

int main() {
    cin >> w >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    for (int i = n - 1; i >= 0; i-- ) {
        if (num[i] == 0) continue;
        ans++;
        for (int j = i - 1; j >= 0; j--) {
            if (num[j] != 0 && num[i] + num[j] <= w) {
                num[j] = 0;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

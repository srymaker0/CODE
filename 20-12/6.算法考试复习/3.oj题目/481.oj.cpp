/*************************************************************************
	> File Name: 481.oj.cpp
	> Author: SORRYMAKER 
	> Mail: 1162065197@qq.com
	> Created Time: Sat 28 Nov 2020 01:56:46 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int r, ans[15][2];


void p(int n) {
    int a1 = 0, a2 = 0;
    for (int i = 1; i < n; i++) {
        a1 += ans[i][0];
        a2 += ans[i][1];
        cout << ans[i][0] << ":" << ans[i][1] << endl;
    }
    cout << a1 << ":" << a2 << endl;
}

int main() {
    cin >> r;
    for (int i = 1; i <= 10; i++) {
        int num1[10] = {0}, num2[10] = {0};
        for (int j = 0; j < 8; j++) {
            cin >> num1[j];
            if (num1[j] == -1) {
                p(i);
                return 0;
            }
        }
        for (int j = 0; j < 8; j++) {
            cin >> num2[j];
        }
        sort(num1, num1 + 8);
        sort(num2, num2 + 8);
        if (num1[0] < num2[0]) {
            for (int j = 0; j < 8; j++) {
                if (num1[j] > r || num1[j] >= num2[0]) break;
                ans[i][0]++;
            }
        } else {
            for (int j = 0; j < 8; j++) {
                if (num2[j] > r || num2[j] >= num1[0]) break;
                ans[i][1]++;
            }
        }
    }
    p(11);
    return 0;
}
